#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;



class array0
{
public:
	int n;
	int *a;
	
	void input()
	{
		
		cin >> n;
		a = new int[n];
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		
	}

	void output()
	{
		cout << n << '\n';
		for (int i = 1; i <= n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	int search(int x)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == x)return i;
		}
		return -1;
	}
	int minimum()
	{
		int ans = 1e9;
		for (int i = 1; i <= n; i++)
		{
			ans = __min(ans, a[i]);
		}
		return ans;
	}

	int maximum()
	{
		int ans = -1e9;
		for (int i = 1; i <= n; i++)
		{
			ans = __max(ans, a[i]);
		}
		return ans;
	}

	int minipos()
	{
		int p, ans = 1e9;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < ans)
			{
				ans = a[i];
				p = i;
			}
		}
		return p;
	}

	int maxipos()
	{
		int p, ans = -1e9;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > ans)
			{
				ans = a[i];
				p = i;
			}
		}
		return p;
	}

	long long sum()
	{
		 long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += a[i];
		}
		return ans;
	}

	double average()
	{
		return 1.0 * sum() / n;

	}

	int even()
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] % 2 == 0)
			{
				ans++;
			}
		}
		return ans;
	}

	int odd()
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] & 1)
			{
				ans++;
			}
		}
		return ans;
	}

	void split()
	{
		cin >> n;
		int od, ev;
		if (n & 1)
		{
			od = n / 2 + 1;
			ev = n / 2;
		}
		else
		{
			od = n / 2;
			ev = n / 2;
		}
		cout << od << '\n';
		for (int i = 1; i <= n; i += 2)
		{
			a[i] = i;
			cout << a[i] << ' ';
		}
		cout << '\n';
		cout << ev << '\n';
		for (int i = 2; i <= n; i += 2)
		{
			a[i] = i;
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	void combine()
	{
		int t, m;
		cin >> t;
		for (int i = 1; i <= t; i++)
		{
			cin >> a[i];
		}
		cin >> m;
		for (int i = t + 1; i <= t + m; i++)
		{
			cin >> a[i];
		}
		cout << t + m << '\n';
		for (int i = 1; i <= t + m; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	void qsort(int l, int r)
	{
		int i = l, j = r, flag = a[(l + r) / 2], tmp;
		do
		{
			while (a[i] < flag)i++;
			while (a[j] > flag)j--;
			if (i <= j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++; j--;
			}
		} while (i <= j);
		if (l < j) qsort(l, j);
		if (i < r) qsort(i, r);
	}

	void combineordered()
	{
		int t, m;
		cin >> t;
		for (int i = 1; i <= t; i++)
		{
			cin >> a[i];
		}
		cin >> m;
		for (int i = t + 1; i <= t + m; i++)
		{
			cin >> a[i];
		}
		cout << t + m << '\n';
		qsort(1, t + m);
		for (int i = 1; i <= t + m; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	void qzh(int l, int r)
	{
		long long* sum;
		sum = new long long[n];
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + a[i];
		}
		cout << sum[r] - sum[l - 1] << '\n';
	}

	void insert1(int p)
	{
		int x;
		cin >> x;
		a[++n] = 0;
		for (int i = n; i >p; i--)
		{
			a[i] = a[i-1];
		}
		a[p] = x;
	}

	void erase1(int p)
	{
		for (int i = p; i < n; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
	}

	void swap1(int l, int r)
	{
		int tmp = a[l];
		a[l] = a[r];
		a[r] = tmp;
	}

	void swap2()
	{
		for (int i = 1; i <= n / 2; i++)
		{
			swap1(i, n + 1 - i);
		}
	}

	void fill(int x)
	{
		for (int i = 1; i <= n; i++)
		{
			a[i] = x;
		}
	}

	void 原神(int x)
	{
		//sjgg很喜欢抽卡，他想知道他能否从数组卡池里抽出他想要的数字
		srand(time(0));
		int y = a[rand() % n + 1];
		if (y == x)cout << "好好好" << '\n';
		else cout <<y<<' ' << "shit" << '\n';
	}

};

int main()
{
	array0 mm;
	mm.input();
	cout << mm.maxipos()<<'\n';
	cout << mm.minipos();

	
}