/*
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define maxn 55
int map[maxn][maxn], ready[maxn][maxn], fx[4] = { 0,1,0,-1 }, fy[4] = { -1,0,1,0 };
struct a_
{
	int x, y, step = 2, f;
};
queue<a_>a;
int main()
{
	int n, m, x1, x2, y1, y2;
	char f;
	a_ ls;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ready[i][j];
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			map[i][j] = -1;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		map[i][0] = 1;
		map[i][m] = 1;
	}
	for (int i = 0; i <= m; i++)
	{
		map[0][i] = 1;
		map[n][i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ready[i][j] == 1)
			{
				map[i + 1][j] = 1;
				map[i][j + 1] = 1;
				map[i + 1][j + 1] = 1;
				map[i][j] = 1;
			}
		}
	}
	cin >> x1 >> y1 >> x2 >> y2 >> f;
	ls.x = x1;
	ls.y = y1;
	map[x1][y1] = 2;
	switch (f)
	{
	case'W':ls.f = 0; break;
	case'S':ls.f = 1; break;
	case'E':ls.f = 2; break;
	case'N':ls.f = 3; break;
	default:
		break;
	}
	a.push(ls);
	while (!a.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int jia = abs(i - a.front().f);
			if (jia >= 3)
				jia = 1;
			jia++;
			for (int j = 1; j <= 3; j++)
			{
				if (a.front().y + fy[i] * j >= 0 &&
					a.front().y + fy[i] * j <= m &&
					a.front().x + fx[i] * j >= 0 &&
					a.front().x + fx[i] * j <= n)
				{
					bool bj = true;
					for (int q = j; q >= 1; q--)
					{
						if (map[a.front().x + fx[i] * q][a.front().y + fy[i] * q] == 1)
						{
							bj = false;
							break;
						}
					}
					if (bj)
					{
						if (map[a.front().x + fx[i] * j][a.front().y + fy[i] * j] > a.front().step + jia ||
							map[a.front().x + fx[i] * j][a.front().y + fy[i] * j] == -1)
						{
							ls.x = a.front().x + fx[i] * j;
							ls.y = a.front().y + fy[i] * j;
							ls.step = a.front().step + jia;
							ls.f = i;
							map[a.front().x + fx[i] * j][a.front().y + fy[i] * j] = ls.step;
							a.push(ls);
						}

					}
				}
			}
		}
		a.pop();
	}
	if(map[x2][y2]!=-1)
		cout << map[x2][y2]-2 << endl;
	else
		cout << -1 << endl;
	return 0;
}
*/