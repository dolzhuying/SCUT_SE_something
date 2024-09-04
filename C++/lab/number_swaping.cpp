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
#include<random>


int x;
char t[8] = { '1','2','3','4','5','6','7','8' };
void print(char s)
{
	cout << t[(0 + x) % 8] <<  " -- " << t[(1 + x) % 8] << " -- " << t[(2 + x) % 8] << '\n';
	cout << "|  \\ | /  |" << '\n';
	cout << t[(7 + x) % 8] << " -- " << s << " -- " << t[(3 + x) % 8] << '\n';
	cout << "|  / | \\  |" << '\n';
	cout << t[(6 + x) % 8] << " -- " << t[(5 + x) % 8] << " -- " << t[(4 + x) % 8] << "\n\n";
}

void swap1()
{
	char sp; int y = 0;
	for (int i = 2; i < 8; i++)
	{
		if (t[i - 1] == '0' + i)continue;
		for (int j = i - 1; j < 8; j++)
		{
			if (t[j] == '0' + i)
			{
				sp = t[j];
				t[j] = ' ';
				y = j;
				break;
			}
		}
		print(sp);
		for (int j = y; j >= i; j--)
		{
			t[j] = t[j - 1];
			t[j - 1] = ' ';
			print(sp);
		}
		t[i - 1] = char('0' + i);
		sp = ' ';
		print(sp);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	srand(time(0));
	x = rand() % 8;
	random_shuffle(t + 1, t + 8);
	print(' ');
	swap1();
	return 0;
}
