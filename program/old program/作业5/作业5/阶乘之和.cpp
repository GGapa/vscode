/*
#include <iostream>
#include <cstring>
using namespace std;

int n, a[1000], b[1000];
bool bj = false;
int jia()
{
	for (int i = 999; i > 0; i--)
	{
		b[i] += a[i];
		int ls = b[i] / 10;
		b[i] -= ls * 10;
		b[i - 1] += ls;
	}
	return 0;
}

int cheng(int b)
{
	for (int i = 999; i > 0; i--)
	{
		a[i] *= b;
	}
	for (int i = 999; i > 0; i--)
	{
		int ls = a[i] / 10;
		a[i] -= ls * 10;
		a[i - 1] += ls;
	}
	return 0;
}
int fuyuan()
{
	a[999] = 1;
	for (int i = 0; i < 999; i++)
	{
		a[i] = 0;
	}
	return 0;
}

int shuchu()
{
	for (int i = 0; i <1000; i++)
	{
		if (b[i] != 0)bj = true;
		if (bj)cout << b[i];
	}
	return 0;
}

int main()
{
	a[999] = 1;
	for (int i = 0; i < 999; i++)
	{
		a[i] = 0;
		b[i] = 0;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cheng(j);
		}
		jia();
		fuyuan();
	}
	shuchu();
	cout << endl;
	return 0;
}
*/