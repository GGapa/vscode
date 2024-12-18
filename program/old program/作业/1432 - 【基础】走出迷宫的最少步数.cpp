/*
#include <iostream>
#include <queue>
using namespace std;
#define maxn 42
int  bj[maxn][maxn] = { 0 };
int n, m;
char map[maxn][maxn];
void dfs(int x, int y, int step)
{
	if (x < 0 || y < 0 || x >= n || y >= m || map[x][y] == '#')
		return;
	if (bj[x][y] == 0)
	{
		bj[x][y] = step;
	}
	else if (bj[x][y] < step)
		return;
	else
		bj[x][y] = step;
	dfs(x + 1, y, step + 1);
	dfs(x - 1, y, step + 1);
	dfs(x, y + 1, step + 1);
	dfs(x, y - 1, step + 1);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(0, 0, 1);
	cout << bj[n - 1][m - 1] << endl;
	return 0;

}
*/