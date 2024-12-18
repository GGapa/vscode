/*
#include <iostream>
using namespace std;
#define maxn 102
char a[maxn][maxn];
int bj[maxn][maxn], n, m, fx[4] = { -1,0,1,0 }, fy[4] = { 0 - 1,0,1 }, ans = 0;
void dfs(int x, int y)
{
	bool bj1 = true;
	if (x >= n || y >= m || x < 0 || y < 0 || a[x][y] != 'W' || bj[x][y] == true)
		return;
	bj[x][y] = true;
	dfs(x + 1,y);
	dfs(x,y + 1);
	dfs(x - 1,y);
	dfs(x, y - 1);
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