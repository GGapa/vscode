/*
#include <iostream>
#include <cmath>
using namespace std;
int a[100][100] = { 0 },n;
int ans = 0;
void tance(int r, int x, int y)
{
	for (int i = x - r; i <= x + r;i++)
	{
		for (int j = y - r; j <= y + r; j++)
		{
			if (i >= 0 && i <= n - 1 && j >= 0 && j <= n - 1)
			{
				double ls = sqrt(pow(i - x, 2) + pow(j - y, 2));
				if (ls <= r)
				{
					a[i][j] = 1;
				}
			}
		}

	}
}


int main()
{
	int  m, r,x,y;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--; y--;
		a[x][y] = 1;
		tance(r, x, y);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
*/