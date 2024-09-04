

#include <iostream> 
#include <fstream> 
#include "Maze.h"   
using namespace std;


enum Direction { DOWN, LEFT, UP, RIGHT };


struct Position
{
    int H, V; // HΪˮƽ���꣬VΪ��ֱ����
};


char *maze;//�޸��Թ�����Ϊָ��char��ָ��
int mazeWidth, mazeHeight;
int *posi; // ��¼����·����λ������
int i = 0; // ��¼��ǰλ����path�����е�����
int prevPos = -1;



void FindEntrance(int&);
bool AtExit(int);
void ReportPosition(int);
void WheresRight(int, Direction, int&);
bool Wall(int);
void TurnRight(Direction&);
void MoveForward(int&, Direction);
void WheresAhead(int, Direction, int&);
void TurnLeft(Direction&);


bool LoadMaze(const char fname[])
{
    ifstream ifs(fname);

    if (ifs.good())
    {
        ifs >> mazeWidth >> mazeHeight;

        // �����Թ��ڴ�
        maze = static_cast<char*>(malloc(mazeWidth * mazeHeight * sizeof(char)));
        if (maze == nullptr)
        {
            cerr << "Failed to allocate memory for maze." << endl;
            return false;
        }

        // �����Թ�����
        for (int i = 0; i < mazeHeight; i++)
            for (int j = 0; j < mazeWidth; j++)
                ifs >> maze[i * mazeWidth + j];

        // �� posi �����ڴ�
        posi = static_cast<int*>(malloc(sizeof(int) * (mazeWidth * mazeHeight + 1)));// Add 1 for the final position
        if (posi == nullptr)
        {
            cerr << "Failed to allocate memory for posi." << endl;
            free(maze); // �ͷ��ѷ�����ڴ�
            return false;
        }

        ifs.close();
        return true;
    }
    else
    {
        cerr << "File not found." << endl;
        return false;
    }
}

void SolveMaze()
{
    int pos = 0; // ����λ��
    Direction heading = DOWN; // ��ʼ������
    int* solutionPath = posi;


    
    FindEntrance(pos);

    while (!AtExit(pos))
    {
        
        if (prevPos != pos || (prevPos == solutionPath[-1] && i > 1)) // Not backtracking or revisiting
        {
            *solutionPath++ = pos; // ��ǰ���������·��
            i++;
            if (i >= mazeWidth * mazeHeight + 1)
            {
                cout << "Solution path array is too small\n";
                abort();
            }
            prevPos = pos;
        }

        int other;
        WheresRight(pos, heading, other);
        if (!Wall(other))
        {
            TurnRight(heading);
            MoveForward(pos, heading);
        }
        else
        {
            WheresAhead(pos, heading, other);
            if (!Wall(other))
                MoveForward(pos, heading);
            else
                TurnLeft(heading);
        }
    }

    // ���ڼ�����·��
    *solutionPath++ = pos;
    i++;

    //��������������
    if (i >= mazeWidth * mazeHeight + 1)
    {
        cout << "Solution path array is too small\n";
        abort();
    }

    //���������
    int counter = 0;
    for (int j = 0; j < i; j++)
    {
        if (posi[j] < 0)
            continue;
        cout << "current position: (" << posi[j] / mazeWidth << ',' << posi[j] % mazeWidth << ')' << endl;
        counter++;
    }
    cout << "total steps: " << counter << endl;
    cout << "Maze solved" << endl;
    free(maze);
    free(posi);
}

void FindEntrance(int& pos)
{
    pos = 0;
    while (Wall(pos)) pos++; // �ҵ���һ����ǽ��λ��
}

bool AtExit(int pos)
{
    return (pos >= (mazeHeight - 1) * mazeWidth);
}

void ReportPosition(int pos)
{
    cout << "Current position: (" << pos / mazeWidth << ',' << pos % mazeWidth << ')' << endl;
}

void WheresRight(int pos, Direction heading, int& right)
{
    right = pos; // ��ʼ��Ŀ��λ��Ϊ��ǰλ��
    switch (heading)
    {
    case DOWN:
        right--;
        break;
    case LEFT:
        right -= mazeWidth;
        break;
    case UP:
        right++;
        break;
    case RIGHT:
        right += mazeWidth;
    }
}

bool Wall(int pos)
{
    return (maze[pos] == '#');
}

void TurnRight(Direction& heading)
{
    switch (heading)
    {
    case DOWN:
        heading = LEFT;
        break;
    case LEFT:
        heading = UP;
        break;
    case UP:
        heading = RIGHT;
        break;
    case RIGHT:
        heading = DOWN;
        break;
    }
}

void MoveForward(int& pos, Direction heading)
{
    int new_pos; // �µ�λ��
    switch (heading)
    {
    case DOWN:
        new_pos = pos + mazeWidth;
        break;
    case LEFT:
        new_pos = pos - 1;
        break;
    case UP:
        new_pos = pos - mazeWidth;
        break;
    case RIGHT:
        new_pos = pos + 1;
        break;
    }

    // �����λ���Ƿ����Թ���Χ���Ҳ���ǽ��
    if (new_pos >= 0 && new_pos < mazeWidth * mazeHeight && !Wall(new_pos))
    {
        pos = new_pos; // ���µ�ǰλ��Ϊ�µ���Чλ��
    }
}

void WheresAhead(int pos, Direction heading, int& ahead)
{
    switch (heading)
    {
    case DOWN:
        ahead = pos + mazeWidth;
        break;
    case LEFT:
        ahead = pos - 1;
        break;
    case UP:
        ahead = pos - mazeWidth;
        break;
    case RIGHT:
        ahead = pos + 1;
        break;
    }
}

void TurnLeft(Direction& heading)
{
    switch (heading)
    {
    case DOWN:
        heading = RIGHT;
        break;
    case LEFT:
        heading = DOWN;
        break;
    case UP:
        heading = LEFT;
        break;
    case RIGHT:
        heading = UP;
        break;
    }
}
