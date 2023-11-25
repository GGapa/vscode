//P3842 [TJOI2007] 线段
#include <iostream>
//#include <cstdio>
//#include <cmath>
using namespace std;
int n,l[20005],r[20005],dp[20005][2];
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
    }
    dp[1][1]=r[1]-1;
    dp[1][0]=r[1]-l[1]-1+r[1];
    for(int i = 2;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][0]+abs(l[i-1]-r[i])+r[i]-l[i]+1,dp[i-1][1]+abs(r[i-1]-r[i])+r[i]-l[i]+1);
        dp[i][1]=min(dp[i-1][0]+abs(l[i-1]-l[i])+r[i]-l[i]+1,dp[i-1][1]+abs(r[i-1]-l[i])+r[i]-l[i]+1);
    }
    printf("%d\n", min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]));
    return 0;
}