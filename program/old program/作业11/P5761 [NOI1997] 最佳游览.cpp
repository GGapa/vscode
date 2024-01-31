/*
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int m, n, map[105][20005], ans = 0, startx = -1, starty = -1, num = 0, MAX[20005], dp[20005];
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n - 1; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > 0 && ((startx == -1 && starty == -1) ||
				(starty == j && map[i][j] > ans)))
			{
				startx = i; starty = j;
				ans = max(ans, map[i][j]);
			}
		}
	num = ans;
	for (int j = 0; j < n - 1; j++)
	{
		int M = INT_MIN;
		for (int i = 0; i < m; i++)
		{
			M = max(M, map[i][j]);
		}
		MAX[j] = M;
	}
	for (int j = 0; j < n - 1; j++)
	{
		dp[j] = max(j-1<0?0:dp[j - 1], 0) + MAX[j];
		ans = max(ans, dp[j]);
	}
	cout << ans << endl;
	return 0;
}
*/