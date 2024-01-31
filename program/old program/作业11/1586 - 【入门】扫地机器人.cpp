/*
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 10
int map[maxn][maxn];
int n, m, step = 1;
void dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || map[x][y] != 0)
		return;
	map[x][y] = step;
	step++;
	dfs(x, y + 1);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x - 1, y);
}
int main()
{
	cin >> n >> m;
	dfs(0, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%3d", map[i][j]);
		}
		cout << endl;
	}
	return 0;
}
*/