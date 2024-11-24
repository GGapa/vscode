/*
#include<iostream>
using namespace std;
int a[2000][2000];
int main()
{
	int m, n, i, j, q, zsm = -1, csm = -1, bj = 0, bjt = 0;

	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (i = 0; i < m; i++)
	{
		if (a[0][i] == 0)
		{
			bj = 1;
		}
		if (a[0][i] == 1)
		{
			bj = 2;
		}
		for (j = 1; j < n; j++)
		{
			if (bj == 2)
			{
				if (a[j][i] == 0)
				{
					bj = 1;
					continue;
				}
				else {
					bj = 0;
					continue;
				}
			}
			if (bj == 1)
			{
				if (a[j][i] == 1)
				{
					bj = 2;
					continue;
				}
				else
				{
					bj = 0;
					continue;
				}
			}
		}
		if (bj == 0 && i == j && zsm < i * j)zsm = i * j;
		if (bj == 0 && i != j && csm < i * j)csm = i * j;
	}
	cout << zsm << endl << csm << endl;


}
*/