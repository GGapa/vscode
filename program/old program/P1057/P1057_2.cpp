// P1057 [NOIP2008 普及组] 传球游戏
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, dp[32][32];
int main()
{
    dp[0][1] = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j==1)
            {
                dp[i][j]=dp[i-1][j+1]+dp[i-1][n];
            }
            else if(j==n)
            {
                dp[i][j]=dp[i-1][1]+dp[i-1][j-1];
            }
            else 
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            }
        }
    }
    cout<<dp[m][1]<<endl;
    return 0;
}