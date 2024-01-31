/*
#include <iostream>
#include <queue>
using namespace std;
int map[402][402], fx[8] = { -1,-2,-2,-1,1,2,2,1 }, fy[8] = { -2,-1,1,2,2,1,-1,-2 };
struct h
{
	int x, y, step = 0;
};
queue<h> a;
int main()
{
	int n, m, x, y;
	h ls;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < 402; i++)
	{
		for (int j = 0; j < 402; j++)
		{
			map[i][j] = -1;
		}
	}
	map[x][y] = 0;
	ls.x = x;
	ls.y = y;
	a.push(ls);
	while (!a.empty())
	{
		for (int i = 0; i < 8; i++)
		{
			if (a.front().x + fx[i] > 0 && a.front().x + fx[i] <= n && a.front().y + fy[i] > 0 && a.front().y + fy[i] <= m)
			{
				if (map[a.front().x + fx[i]][a.front().y + fy[i]] == -1)
				{
					map[a.front().x + fx[i]][a.front().y + fy[i]] = a.front().step + 1;
					ls.x = a.front().x + fx[i];
					ls.y = a.front().y + fy[i];
					ls.step = a.front().step + 1;
					a.push(ls);
				}
			}
		}
		a.pop();
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%-4d ", map[i][j]);
		}
		cout << endl;
	}
	return 0;
}
*/