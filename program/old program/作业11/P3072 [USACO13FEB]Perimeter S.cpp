/*
#include <iostream>
#include <set>
#include <map>
#include <limits.h>
using namespace std;
int x, y, n, sx = 0, sy = 0, ans = 0, fx[8] = { -1,0,1,0,-1,-1,1,1 }, fy[8] = { 0,-1,0,1,1,-1,-1,1 };
set<pair<int, int>> a;
set<pair<int, int>> b;
void dfs(int dx, int dy)
{
	if (a.count(make_pair(dx, dy)) > 0)
	{
		ans++;
		return;
	}
	bool bj = true;
	if (a.count(make_pair(dx, dy)) > 0 || b.count(make_pair(dx, dy)) > 0)
		return;
	for (int i = 0; i < 8; i++)
		if (a.count(make_pair(dx + fx[i], dy + fy[i])) != 0)
		{
			bj = false;
			break;
		}
	if (bj)
		return;
	b.insert(make_pair(dx, dy));
	for (int i = 0; i < 4; i++)
		dfs(dx + fx[i], dy + fy[i]);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		a.insert(make_pair(x, y));
		if (x > sx)
		{
			sx = x;
			sy = y;
		}
	}
	sx++;
	dfs(sx, sy);
	cout << ans << endl;
	return 0;
}
*/