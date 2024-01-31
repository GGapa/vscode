/*
#include <iostream>
#include <queue>
using namespace std;
#define maxn 155
struct a_
{
	int x, y, step = 0;
};
char map[maxn][maxn];
int an[maxn][maxn] = { 0 }, sx, sy, ex, ey;
int fx[8] = { -1,-2,-2,-1,1,2,2,1 }, fy[8] = { -2,-1,1,2,2,1,-1,-2 };
queue<a_>a;
a_ temp;
int n, m;
int main()
{
	int n, m;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin>>map[i][j];
			if (map[i][j] == 'K')
			{
				sx = i;
				sy = j;
			}
			if (map[i][j] == 'H')
			{
				ex = i; ey = j;
			}
		}
	temp.x = sx;
	temp.y = sy;
	temp.step = 1;
	a.push(temp);
	an[sx][sy] = 1;
	while (!a.empty())
	{
		for (int i = 0; i < 8; i++)
		{
			int X = a.front().x + fx[i];
			int Y = a.front().y + fy[i];
			if (X > 0 && X <= n && Y > 0 && Y <= m)
			{
				if (an[X][Y] == 0 && map[X][Y] != '*')
				{
					an[X][Y] = a.front().step + 1;
					temp.x = X;
					temp.y = Y;
					temp.step = a.front().step + 1;
					a.push(temp);
				}
			}
		}
		a.pop();
	}
	cout << an[ex][ey]-1 << endl;
	return 0;
}
*/