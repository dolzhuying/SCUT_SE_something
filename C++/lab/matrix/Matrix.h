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
	friend ostream& operator<<(ostream& out, matrix& c);//����<<
	friend istream& operator>>(istream& in, matrix& c);//����>>
	matrix operator + (const matrix& c);//����+
	matrix operator - (const matrix& c);//����-
	matrix operator * (const matrix& c);//����*������˷���
	matrix& operator+=(const matrix& c);//����+=
	matrix& operator-=(const matrix& c);//����-=
	matrix& operator*=(const matrix& c);//����*=������˷���
	matrix operator *(int c);//����*����������֣�
	matrix& operator *=(int c);//����*=����������֣�
	bool operator==(const matrix& c);//����==
	bool operator!=(const matrix& c);//���أ�=
	matrix turntoT();//����ת��
	
};





