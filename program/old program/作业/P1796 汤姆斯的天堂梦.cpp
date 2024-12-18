/*
#include <iostream>
#include <limits.h>
using namespace std;
int map[105][105] = { 0 };
int main()
{
	int n, k;
	int x, y;
	cin >> n;
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			map[i][j] = INT_MAX;
			cin >> x;
			while (x != 0)
			{
				cin >> y;
				map[i][j] = min(map[i - 1][x] + y, map[i][j]);
				cin >> x;
			}
		}
	}
	for (int i = 1; i <= k; i++)
		ans = min(ans, map[n][i]);
	cout << ans << endl;
	return 0;
}
*/