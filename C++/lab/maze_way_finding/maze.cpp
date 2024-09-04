

#include <iostream> 
#include <fstream> 
#include "Maze.h"   
using namespace std;


enum Direction { DOWN, LEFT, UP, RIGHT };


struct Position
{
    int H, V; // H为水平坐标，V为垂直坐标
};


char *maze;//修改迷宫声明为指向char的指针
int mazeWidth, mazeHeight;
int *posi; // 记录搜索路径的位置数组
int i = 0; // 记录当前位置在path数组中的索引
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

        // 分配迷宫内存
        maze = static_cast<char*>(malloc(mazeWidth * mazeHeight * sizeof(char)));
        if (maze == nullptr)
        {
            cerr << "Failed to allocate memory for maze." << endl;
            return false;
        }

        // 读入迷宫数据
        for (int i = 0; i < mazeHeight; i++)
            for (int j = 0; j < mazeWidth; j++)
                ifs >> maze[i * mazeWidth + j];

        // 给 posi 分配内存
        posi = static_cast<int*>(malloc(sizeof(int) * (mazeWidth * mazeHeight + 1)));// Add 1 for the final position
        if (posi == nullptr)
        {
            cerr << "Failed to allocate memory for posi." << endl;
            free(maze); // 释放已分配的内存
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
    int pos = 0; // 现在位置
    Direction heading = DOWN; // 初始化方向
    int* solutionPath = posi;


    
    FindEntrance(pos);

    while (!AtExit(pos))
    {
        
        if (prevPos != pos || (prevPos == solutionPath[-1] && i > 1)) // Not backtracking or revisiting
        {
            *solutionPath++ = pos; // 当前方向加入解决路径
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

    // 出口加入解决路径
    *solutionPath++ = pos;
    i++;

    //如果过大，输出错误
    if (i >= mazeWidth * mazeHeight + 1)
    {
        cout << "Solution path array is too small\n";
        abort();
    }

    //输出并计数
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
    while (Wall(pos)) pos++; // 找到第一个非墙壁位置
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
    right = pos; // 初始化目标位置为当前位置
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
    int new_pos; // 新的位置
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

    // 检查新位置是否在迷宫范围内且不是墙壁
    if (new_pos >= 0 && new_pos < mazeWidth * mazeHeight && !Wall(new_pos))
    {
        pos = new_pos; // 更新当前位置为新的有效位置
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
