/*
#include <iostream>
using namespace std;
#define maxn 102
char a[maxn][maxn];
int bj[maxn][maxn], n, m, fx[8] = { 0,-1,-1,-1,0,1,1,1 }, fy[8] = {-1,-1,0,1,1,1,0,-1},ans=0;
void dfs(int x, int y)
{
	bool bj1 = true;
	bj[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		if (x + fx[i] >= 0 && x + fx[i] < n && y + fy[i] >= 0 && y + fy[i] < m)
		{
			if (a[x + fx[i]][y + fy[i]] == 'W' && !bj[x + fx[i]][y + fy[i]])
			{
				bj1 = false;
				break;
			}
		}
	}
	if (bj1)
		return;
	for (int i = 0; i < 8; i++)
	{
		if (x + fx[i] >= 0 && x + fx[i] < n && y + fy[i] >= 0 && y + fy[i] < m)
		{
			if (a[x + fx[i]][y + fy[i]] == 'W' && !bj[x + fx[i]][y + fy[i]])
			{
				dfs(x + fx[i], y + fy[i]);
			}
		}
	}
}
int main()
{
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			bj[i][j] = false;
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'W' && !bj[i][j])
			{
				dfs(i, j);
				ans++;
			}
		}

	}
	cout << ans << endl;
	return 0;
}
*/