/*
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define maxn 105
int n, m, xx1, xx2, yy1, yy2 ,fx[4] = { -1,0,1,0 }, fy[4] = { 0,-1,0,1 },map[maxn][maxn],fs[maxn][maxn][20][10],ok;
void bfs(int far)
{
	memset(fs, 0, sizeof fs); 
	ok = 0;
	queue<int> qx, qy, qt, q; 
	fs[xx1][yy1][far - 1][0] = 1;
	qx.push(xx1); qy.push(yy1); qt.push(far - 1); q.push(-1);
	while (!qx.empty())
	{
		int x = qx.front();
		qx.pop();
		int y = qy.front();
		qy.pop();
		int t = qt.front(); 
		qt.pop();
		int now = q.front();
		q.pop();
		if (x == xx2 && y == yy2)
		{
			ok = 1;
			cout << far << " " << fs[x][y][t][now] << endl;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if (((x == xx1 && y == yy1) || i == now) or !t)
			{
				int tx = x + fx[i], ty = y + fy[i];
				int nt = i == now ? max(0, t - 1) : far - 1;
				if (map[tx][ty] && tx <= n && ty <= m && tx >=1 && ty >= 1 && !fs[tx][ty][nt][i])
				{
					fs[tx][ty][nt][i] = fs[x][y][t][now] + 1; 
					qx.push(tx); 
					qy.push(ty); 
					qt.push(nt);
					q.push(i);
				}
			}
		}
	}

}
int main()
{
	cin >> n >> m >> xx1 >> yy1 >> xx2 >> yy2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	for (int i = 1; i <= 10; i++)bfs(i);
	return 0;
}
*/