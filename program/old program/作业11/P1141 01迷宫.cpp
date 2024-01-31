/*
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 1010
struct node
{
	int x, y, himself;
};
queue<node>a;
int n, m, map[maxn][maxn], bj[maxn][maxn], ans[maxn][maxn], fx[4] = { 1,0,-1,0 }, fy[4] = { 0,1,0,-1 };
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
	{
		int it = 1;
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			map[i][it++] = temp[j] - '0';
		}
	}
	node temp;
	int step = 1;
	while (m--)
	{
		int startx, starty;
		startx = read();
		starty = read();
		if (bj[startx][starty] == 0)
		{
			int num = 1;
			temp.x = startx; temp.y = starty;
			temp.himself = map[startx][starty];
			bj[startx][starty] = step;
			a.push(temp);
			while (!a.empty())
			{
				for (int i = 0; i < 4; i++)
				{
					int X = a.front().x + fx[i];
					int Y = a.front().y + fy[i];
					if (X > 0 && Y > 0 && X <= n && Y <= n &&
						map[a.front().x][a.front().y] != map[X][Y] && bj[X][Y] == 0)
					{
						num++;
						temp.x = X;
						temp.y = Y;
						temp.himself = map[X][Y];
						bj[X][Y] = step;
						a.push(temp);
					}
				}
				a.pop();
			}
			for (int kkk = 1; kkk <= n; kkk++)
			{
				for (int cz = 1; cz <= n; cz++)
				{
					if (bj[kkk][cz] == step)
					{
						ans[kkk][cz] = num;
					}
				}
			}
			step++;
		}
		cout << ans[startx][starty] << "\n";
	}
	return 0;
}
*/