#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <limits.h>
using namespace std;
const long long Min = -1e18;
const int maxn = 1e3+10;
long long n,m,map[maxn][maxn],used[maxn][maxn],dp[maxn][maxn][2];
inline long long mx(long long p, long long q, long long r) {return p > q ? (p > r ? p : r) : (q > r ? q : r);}
long long dfs(long long x,long long y,long long z)
{
	if (x < 1 || x > n || y < 1 || y > m) return Min;
    if (dp[x][y][z] != Min) return dp[x][y][z];
    if (z == 0) dp[x][y][z] = mx(dfs(x + 1, y, 0), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + map[x][y];
    else dp[x][y][z] = mx(dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + map[x][y];
    return dp[x][y][z];
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%lld", &map[i][j]);
			dp[i][j][0] = dp[i][j][1] = Min;
		}
    dp[1][1][0] = dp[1][1][1] = map[1][1];
	printf("%lld\n", dfs(n, m, 1));
	return 0;
}
