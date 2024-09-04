#include<iostream>
using namespace std;
class matrix
{
private:
	int a[3][3];
public:
	matrix()
	{
		a[1][1] = 1; a[1][2] = 0; a[2][1] = 0; a[2][2] = 1;
	}
	matrix(int e, int f, int g, int h)
	{
		a[1][1] = e; a[1][2] = f; a[2][1] = g; a[2][2] = h;
	}
	friend ostream& operator<<(ostream& out, matrix& c);//重载<<
	friend istream& operator>>(istream& in, matrix& c);//重载>>
	matrix operator + (const matrix& c);//重载+
	matrix operator - (const matrix& c);//重载-
	matrix operator * (const matrix& c);//重载*（矩阵乘法）
	matrix& operator+=(const matrix& c);//重载+=
	matrix& operator-=(const matrix& c);//重载-=
	matrix& operator*=(const matrix& c);//重载*=（矩阵乘法）
	matrix operator *(int c);//重载*（矩阵乘数字）
	matrix& operator *=(int c);//重载*=（矩阵乘数字）
	bool operator==(const matrix& c);//重载==
	bool operator!=(const matrix& c);//重载！=
	matrix turntoT();//矩阵转置
	
};





