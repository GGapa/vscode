/*
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int c[4000];
int a[4000], b[4000];

int main()
{
	string A, B;

	int i, ls, j;
	bool bj = false;
	cin >> A >> B;
	for (i = 0; i < 4000; i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	for (i = A.length() - 1; i >= 0; i--)
		a[A.length() - 1 - i] = A[i] - '0';
	for (i = B.length() - 1; i >= 0; i--)
		b[B.length() - i - 1] = B[i] - '0';
	for (i = 0; i <= A.length(); i++)
	{
		for (j = 0; j <= B.length(); j++)
		{
			c[i + j] += a[i] * b[j];
		}
	}
	for (i = 0; i < 3999; i++)
	{
		ls = c[i] / 10;
		c[i] -= ls * 10;
		c[i + 1] += ls;
	}
	for (i = 3999; i >= 0; i--)
	{
		if (c[i] != 0)bj = true;
		if (bj)cout << c[i];
	}
	if (!bj)cout << 0;
	cout << endl;
	return 0;
}
*/