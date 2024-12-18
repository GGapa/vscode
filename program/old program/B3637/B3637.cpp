//B3637 最长上升子序列
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2*10e5+5;
int n,a[maxn],dp[maxn],ans=1;
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)
    {
        dp[i]=1;
        for(int j = 1;j<=i-1;j++)
        {
            if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}