/*
#include <iostream>
#include <queue>;
using namespace std;
#define maxn 105
int n, map[maxn][maxn], bj[maxn][maxn], xa, ya, xb, yb;
void  dfs(int x, int y)
{
	if (x > n || y > n || bj[x][y] == 1 || map[x][y] == 1 || x <= 0 || y <= 0)
	{
		return;
	}
	bj[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> xa >> ya >> xb >> yb;
	dfs(xa, ya);
	if (bj[xb][yb] == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
*/