#include<iostream>
using namespace std;

#include"Matrix.h"

ostream& operator<<(ostream& out, matrix& c)
{
	out << c.a[1][1] << ' ' << c.a[1][2] << '\n' << c.a[2][1] << ' ' << c.a[2][2] << '\n';
	return out;
}

istream& operator>>(istream& in, matrix& c)
{
	in >> c.a[1][1] >> c.a[1][2] >> c.a[2][1] >> c.a[2][2];
	return in;
}

//重载+
matrix matrix::operator + (const matrix& c)
{
	matrix tmp;
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			tmp.a[i][j] = this->a[i][j] + c.a[i][j];
		}
	}
	return tmp;
}

//重载-
matrix matrix::operator - (const matrix& c)
{
	matrix tmp;
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			tmp.a[i][j] = this->a[i][j] - c.a[i][j];
		}
	}
	return tmp;
}

//重载*（矩阵乘法）
matrix matrix::operator * (const matrix& c)
{
	matrix tmp(0, 0, 0, 0);
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			for (int k = 1; k <= 2; k++)
			{
				tmp.a[i][j] += this->a[i][k] * c.a[k][j];
			}
		}
	}
	return tmp;
}

//重载+=
matrix& matrix::operator+=(const matrix& c)
{
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			this->a[i][j] += c.a[i][j];
		}
	}
	return *this;
}

//重载-=
matrix& matrix::operator-=(const matrix& c)
{
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			this->a[i][j] -= c.a[i][j];
		}
	}
	return *this;
}

//重载*=（矩阵乘法）
matrix& matrix::operator*=(const matrix& c)
{
	matrix tmp(0, 0, 0, 0);
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			for (int k = 1; k <= 2; k++)
			{
				tmp.a[i][j] += this->a[i][k] * c.a[k][j];
			}
		}
	}
	*this = tmp;
	return *this;
}

//重载*（矩阵乘数字）
matrix matrix::operator *(int c)
{
	matrix tmp;
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			tmp.a[i][j] = this->a[i][j] * c;
		}
	}
	return tmp;
}

//重载*=（矩阵乘数字）
matrix& matrix::operator *=(int c)
{
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			this->a[i][j] *= c;
		}
	}
	return *this;
}

//重载==
bool matrix::operator==(const matrix& c)
{
	if (this->a[1][1] == c.a[1][1] && this->a[1][2] == c.a[1][2] && this->a[2][1] == c.a[2][1] && this->a[2][2] == c.a[2][2])return true;
	return false;
}

//重载！=
bool matrix::operator!=(const matrix& c)
{
	if (this->a[1][1] != c.a[1][1] || this->a[1][2] != c.a[1][2] || this->a[2][1] != c.a[2][1] || this->a[2][2] != c.a[2][2])return true;
	return false;
}

//求矩阵转置
matrix matrix::turntoT()
{
	matrix tmp;
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			tmp.a[i][j] = this->a[j][i];
		}
	}
	return tmp;
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//test
	matrix e(1, 1, 1, 1), f(2, 2, 2, 2),g;
	cin >> g; cout << g<<'\n';
	
}
