/*
#include <iostream>
#include <queue>
using namespace std;
int fx[12] = { -1,-2,-2,-1,1,2,2,1,-2,-2,2,2 }, fy[12] = { -2,-1,1,2,2,1,-1,-2,-2,2,2,-2 };
struct aa
{
	int x, y, step = 0;
};
queue<aa> a;
queue<aa> b;
bool map1[55][55], map2[55][55];
int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	aa ls;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			map1[i][j] = map2[i][j] = true;
		}
	}
	ls.x = x1;
	ls.y = y1;
	a.push(ls);
	map1[x1][y1] = false;
	ls.x = x2;
	ls.y = y2;
	map2[x2][y2] = false;
	b.push(ls);
	bool c = true;
	while (!a.empty())
	{
		for (int i = 0; i < 12; i++)
		{
			if (a.front().x + fx[i] > 0 && a.front().x + fx[i] <= 50 && a.front().y + fy[i] >0 && a.front().y + fy[i] > 0 <= 50 && map1[a.front().x + fx[i]][a.front().y + fy[i]])
			{
				ls.x = a.front().x + fx[i];
				ls.y = a.front().y + fy[i];
				ls.step = a.front().step + 1;
				map1[a.front().x + fx[i]][a.front().y + fy[i]] = false;
				a.push(ls);
			}
		}
		if (a.front().x == 1 && a.front().y == 1)
		{
			cout << a.front().step << endl;
			c = false;
		}
		a.pop();
	}
	if (c)
		cout << -1 << endl;
	c = true;
	while (!b.empty())
	{
		for (int i = 0; i < 12; i++)
		{
			if (b.front().x + fx[i] > 0 && b.front().x + fx[i] <= 50 && b.front().y + fy[i] > 0 && b.front().y + fy[i] > 0 <= 50 && map2[b.front().x + fx[i]][b.front().y + fy[i]])
			{
				ls.x = b.front().x + fx[i];
				ls.y = b.front().y + fy[i];
				ls.step = b.front().step + 1;
				map2[b.front().x + fx[i]][b.front().y + fy[i]] = false;
				b.push(ls);
			}
		}
		if (b.front().x == 1 && b.front().y == 1)
		{
			cout << b.front().step << endl;
			c = false;
		}
		b.pop();
	}
	if (c)
		cout << -1 << endl;
	c = true;
	return 0;
}
*/