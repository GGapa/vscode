/*
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 1001
#define maxi 500
int a[maxn], b[maxn], c[maxn], p;
void fun1()
{
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= maxi; i++)
	{
		for (int j = 1; j <= maxi; j++)
		{
			c[i + j - 1] += b[i] * a[j];
		}
	}
	for (int i = 1; i <= maxi; i++)
	{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	memcpy(b, c, sizeof(b));
}
void fun2()
{
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= maxi; i++)
	{
		for (int j = 1; j <= maxi; j++)
		{
			c[i + j - 1] += a[i] * a[j];
		}
	}
	for (int i = 1; i <= maxi; i++)
	{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	memcpy(a, c, sizeof(a));
}
int main()
{
	cin >> p;
	cout << int(log10(2) * p + 1) << endl;
	a[1] = 2;
	b[1] = 1;
	while (p != 0)
	{
		if (p % 2 == 1) fun1();
		p /= 2;
		fun2();
	}
	b[1] -= 1;
	for (int i = 500; i >= 1; i -= 1)
		if (i != 500 && i % 50 == 0)printf("\n%d", b[i]);
		else printf("%d", b[i]);
	return 0;
}
*/