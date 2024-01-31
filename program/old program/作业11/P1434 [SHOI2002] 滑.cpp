/*
#include <iostream>
#include <limits.h>
using namespace std;
#define maxn 105
int a[maxn][maxn], n, m, fx[4] = { 0,0,1,-1 }, fy[4] = { 1,-1,0,0 }, ans = INT_MIN, s[maxn][maxn], num = 0;
bool bj[maxn][maxn];
int dfs(int x, int y)
{
	if (s[x][y])
		return s[x][y];
	s[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int X = x + fx[i];
		int Y = y + fy[i];
		if (X > 0 && Y > 0 && X <= n && Y <= m && a[x][y] > a[X][Y])
		{
			dfs(X, Y);
			s[x][y] = max(s[x][y], s[X][Y] + 1);
		}
	}
	return s[x][y];
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans = max(ans, dfs(i, j));
			num = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
*/