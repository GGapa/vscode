/*
#include <cstdio>
#include <iostream>
using namespace std;
int n, m, a[1000][1000], yans[1000], rans[1000], ls = 0;
int main()
{
	int right = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> rans[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[j][i] == 1)
			{
				ls++;
			}
		}
		if (ls > n / 2)
		{
			yans[i] = 1;
		}
		else
		{
			yans[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (yans[i] == rans[i])
		{
			right++;
		}
	}
	cout << right << endl;
	return 0;
}
*/