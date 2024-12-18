// P1077 [NOIP2012 普及组] 摆花
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;
const int mod = 1000007;
int n, m, a[101], dp[105][105];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    dp[0][0]=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int q = 0; q <= min(j, a[i]); q++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - q]) % mod;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}