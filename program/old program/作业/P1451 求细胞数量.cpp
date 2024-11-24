/*
#include <iostream>
#include <string>
using namespace std;
int  bj[105][105], fx[4] = { -1,0,1,0 }, fy[4] = { 0,-1,0,1 }, ans = 0;
int a[105][105];
string ls;
int n, m;
void digui(int x, int y)
{
	bj[x][y] = 1;
	bool bj1 = true;
	for (int i = 0; i < 4; i++)
	{
		if (x + fx[i] >= 0 && x + fx[i] < n && y + fy[i] >= 0 && y + fy[i] < m)
		{
			if (bj[x + fx[i]][y + fy[i]] == 0 && a[x + fx[i]][y + fy[i]] != 0)
			{
				bj1 = false;
				break;
			}
		}
	}
	if (bj1)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (x + fx[i] >= 0 && x + fx[i] < n && y + fy[i] >= 0 && y + fy[i] < m)
		{
			if (bj[x + fx[i]][y + fy[i]] != 1 && a[x + fx[i]][y + fy[i]] != 0)
			{
				bj[x + fx[i]][y + fy[i]] = 1;
				digui(x + fx[i], y + fy[i]);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> ls;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = ls[j] - 48;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (bj[i][j] == 0&&a[i][j]!=0)
			{
				ans++;
				digui(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
*/