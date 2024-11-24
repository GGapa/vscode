/*
#include<iostream>
using namespace std;

int main()
{
	int a[100][100], i, j,n,m,k,x,y,q,num=0;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			a[i][j] = 0;
		}
	}
	cin >> n >> m >> k;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		a[x][y] = 1;
		for (j = x - 2; j <= x + 2; j++)
		{
			if (j<0 || j>n - 1) continue;
			a[j][y] = 1;

		}
		for (j = y - 2; j <= y + 2; j++)
		{
			if (j<0 || j>n - 1) continue;
			a[x][j] = 1;
		}
		for (j = y - 1; j <= y + 1; j++)
		{
			for (q = x - 1; q <= x + 1; q++)
			{
				if (j<0 || q<0 || j>n - 1 || q>n - 1) continue;
				a[q][j] = 1;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		for (j = y - 2; j <= y + 2; j++)
		{
			for (q = x - 2; q <= x + 2; q++)
			{
				if (j<0 || q<0 || j>n - 1 || q>n - 1) continue;
				a[q][j] = 1;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 0) num++;
		}
	}
	cout << num << endl;
	return 0;

*/