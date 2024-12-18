//奶牛大学
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,a[100005],f[1000005];
long long ans=0,num=0,mon;
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++)
    {
        long long tmp=(long long)a[i]*(n-i+1);
        if(tmp>ans)
        {
            ans=tmp;
            mon=a[i];
        }
    }
    printf("%lld %lld",ans,mon);
    return 0;
}