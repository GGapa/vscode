/*
#include <iostream>
#include <queue>
using namespace std;
#define maxn 1005
struct place_
{
	int x, y;
};
int bj[maxn][maxn] = { 0 }, map[maxn][maxn], ans = 0, n, m, qx, qy, h;
int fx[4] = { -1,0,1,0 }, fy[4] = { 0,-1,0,1 };
queue<place_>place;
place_ temp;
int main()
{
	cin >> n >> m >> qx >> qy;
	temp.x = qx;
	temp.y = qy;
	bj[qx][qy] = 1;
	ans++;
	place.push(temp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	h = map[qx][qy];
	while (!place.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int X = place.front().x + fx[i];
			int Y = place.front().y + fy[i];
			if (X > 0 && Y > 0 && X <= n && Y <= m && bj[X][Y] == 0 && map[X][Y] <= h)
			{
				temp.x = X;
				temp.y = Y;
				place.push(temp);
				bj[X][Y] = 1;
				ans++;
			}
		}
		place.pop();
	}
	cout << ans << endl;
	return 0;
}
*/