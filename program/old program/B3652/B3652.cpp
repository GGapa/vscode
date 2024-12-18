//B3652 [语言月赛202208]渡荆门送别
#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;
const int maxn = 1e6+10;
long long a[maxn],Max=LLONG_MIN,Min=LLONG_MAX;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        Max=max(Max,a[i]);
        Min=min(Min,a[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        printf("%lld ",Max-a[i]);
    }
    printf("\n");
    for(int i = 1;i<=n;i++)
    {
        printf("%lld ",a[i]-Min);
    }
}