// P2642 双子序列最大和
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
#define maxn 1000005
long long f[maxn], a[maxn], now = 0, it1 = 1, it2 = 1,sum[maxn],d[maxn];

int main()
{
    int n;
    long long ans=LLONG_MIN;
    memset(f,0,sizeof(f));
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(int i = 1;i<=n;i++)f[i]=max(f[i-1]+a[i],a[i]);
    for(int i = 2;i<=n;i++)f[i]=max(f[i-1],f[i]);
    for(int i = n;i>=1;i--)d[i]=max(d[i+1]+a[i],a[i]);
    for(int i = n-1;i>=1;i--)d[i]=max(d[i+1],d[i]);
    for(int i = 2;i+1<=n;i++)ans=max(ans,f[i-1]+d[i+1]);
    printf("%lld", ans);
    return 0;
}
