/*
#include <iostream>
using namespace std;
int a[1000][1000];

int main()
{
	int  i, j, m, n, q, x1, x2, y1, y2;
	cin >> n >> m;
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			a[i][j] = 0;
		}
	}
	for (q = 1; q <= m; q++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (i = x1 - 1; i <= x2-1; i++)
		{
			for (j = y1 - 1; j <= y2-1; j++)
			{
				a[i][j]++;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/