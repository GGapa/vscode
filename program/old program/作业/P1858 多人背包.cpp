/*
#include <iostream>
#include <limits.h>
#define maxn 205
using namespace std;
int k, v, n;
struct thing
{
	int v, m;
}a[220];
int dp[5010][60];
int main()
{
	cin >> k >> v >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].v >> a[i].m;
	for (int i = 0; i < 5010; i++)
		for (int j = 0; j < 60; j++)
			dp[i][j] = INT_MIN;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = v; j >= a[i].v; j--)
		{
			int x = 1, y = 1, len = 0, l[60000];
			while (x + y <= k + 1)
				(dp[j][x] > dp[j - a[i].v][y] + a[i].m) ?
				(l[++len] = dp[j][x++]) : (l[++len] = dp[j - a[i].v][y++] + a[i].m);
			for (int q = 1; q <= k; q++)
				dp[j][q] = l[q];
		}
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)ans += dp[v][i];
	cout << ans << endl;
	return 0;
}
*/