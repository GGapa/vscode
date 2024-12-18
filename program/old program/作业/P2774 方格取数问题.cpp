/*
#include <iostream>
using namespace std;
#define maxn 101
int n, m, a[maxn][maxn], ans = 0, num = 0, bj[maxn][maxn], fx[8] = { -1,1,0,0 },
fy[8] = { 0,0,-1,1 };

void dfs(int x, int y)
{
	if (x >= n)
	{
		ans = max(num, ans);
		return;
	}
	if (y >= m)
	{
		dfs(x + 1, 0);
		return;
	}
	dfs(x, y + 1);
	if (bj[x][y] == 0)
	{
		bj[x][y] ++;
		num += a[x][y];
		for (int i = 0; i < 4; i++)
		{
			if (x + fx[i] >= 0 && x + fx[i] < n && y + fy[i] >= 0 && y + fy[i] < m)
			{
				bj[x + fx[i]][y + fy[i]]++;
			}
		}
		dfs(x, y + 1);
		for (int i = 0; i < 4; i++)
		{
			if (x + fx[i] >= 0 && x + fx[i] < n && y + fy[i] >= 0 && y + fy[i] < m)
			{
				bj[x + fx[i]][y + fy[i]] --;
			}
		}
		bj[x][y] --;
		num -= a[x][y];
	}
}
int main()
{
	int t;
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			a[i][j] = bj[i][j] = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	ans = num = 0;
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
*/