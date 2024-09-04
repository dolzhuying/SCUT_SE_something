#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<ctime>

char mapp[205][205];

class spirit
{
private:
    string name = "NULL";
    int x, y;
    int health=1000;
    bool alivestate = true;
public:
    
    static int number;
    static int alivenumber;
    spirit()
    {
        cout << "name:";
        cin >> name;
        cout << "x:";
        cin >> x;
        cout << "y:";
        cin >> y;
    }
    spirit(string s, int t, int w)
    {
        name = s; x = t, y = w;
    }
    void createmember2(string s, int t, int w)
    {
        name = s;
        x = t; y = w;
        number++;
        alivenumber++;
    }

    void takedamage(int damage)
    {
        if (alivestate == true)
        {
            health -= damage;
            if (health <= 0)
            {
                health = 0;
                alivenumber--;
                alivestate = false;
            }
        }
    }

    void setposition(int t, int w)
    {
        if (t < 1 || t>100 || w < 1 || w>100)
        {
            cout << "out of range!\n";
        }
        else
        {
            x = t; y = w;
        }
    }

    int getpositionx() { return x; }
    int getpositiony() { return y; }
    string getname() { return name; }
    int gethealth() { return health; }
    int getnumber() { return number; }
    int getalivenumber() { return alivenumber; }
    void getinfo()
    {
        cout << "name:" << name<<'\n';
        cout << "health:" << health << '\n';
        if (health > 0)cout << "alivestate:true\n";
        else cout << "alivestate:false\n";
        cout << "position: x:" << x << " y: " << y << "\n\n";
    }
};

int spirit::number = 0;
int spirit::alivenumber = 0;

int main()
{
    
    srand(time(0));
    
    spirit ys[10];
    for (int i = 0; i < 10; i++)
    {
        ys[i];
        
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            mapp[i][j] = '_';
        }
    }
    for (int i = 0; i < 10; i++)
    {
        mapp[ys[i].getpositionx()][ys[i].getpositiony()] = '*';
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            cout << mapp[i][j];
        }
        cout << '\n';
    }
   
   

    return 0;
}
