#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
long long position[1000005],n,d;
int main()
{
    scanf("%lld%lld",&n,&d);
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld",&position[i]);
    }
    sort(position+1,position+1+n);
    long long total=0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if(position[j]-position[i]<=d)total++;
            else break;
        }
    }
    printf("%lld",total);
    return 0;
}