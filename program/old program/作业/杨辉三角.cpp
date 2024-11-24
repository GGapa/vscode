/*
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a[25][25] = { 0 }, i, j, n;
	a[0][1] = 1;
	cin >> n;
	for (i = 1; i < 20; i++)
	{
		a[i][i + 1] = 1;
		a[i][1] = 1;
	}
	for (i = 2; i < n; i++)
	{
		for (j = 2; j < i + 1; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	int kong = n-1;
	for (i = 0; i < n; i++)
	{
		for (int i = 0; i < kong; i++)
			cout << " ";
		kong -= 1;
		for (j = 1; j <= i + 1; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
*/