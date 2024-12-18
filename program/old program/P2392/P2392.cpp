// P2392 kkksc03考前临时抱佛脚
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int s[5];
int a[5][30];
int dp[5][3000];
int ans = 0, sum = 0;
int main()
{
    for (int i = 1; i <= 4; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i <= 4; i++)
    {
        sum=0;
        for (int j = 1; j <= s[i]; j++)
        {

            scanf("%d", &a[i][j]);
            sum+=a[i][j];
        }
        for(int j = 1;j<=s[i];j++)
        {
            for(int q = sum/2;q>=a[i][j];q--)
            {
                dp[i][q]=max(dp[i][q],dp[i][q-a[i][j]]+a[i][j]);
            }
        }
        ans+=sum-dp[i][sum/2];
    }
    cout << ans << endl;
    return 0;
}