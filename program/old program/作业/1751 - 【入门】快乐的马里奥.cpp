/*
#include <iostream>
#include<queue>
using namespace std;
struct a_
{
	int x, y;
};
int map[102][102], add = 2, fx[4] = { 0,1,0,-1 }, fy[4] = { 1,0,-1,1 };
queue<a_>a;
a_ temp;
int main()
{
	int n, m;
	cin >> n >> m;
	map[1][1] = 1;
	temp.x = 1;
	temp.y = 1;
	a.push(temp);
	while (!a.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int x = a.front().x + fx[i],
				y = a.front().y + fy[i];
			if (x > 0 && x <= n && y > 0 && y <= m && map[x][y] == 0)
			{
				temp.x = x;
				temp.y = y;
				map[x][y] = add++;
				a.push(temp);
			}
		}
		a.pop();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/