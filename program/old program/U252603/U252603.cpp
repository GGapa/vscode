//U252603 球状精灵的传说
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cmath>
using namespace std;
long long a[500005][3],ans=INT_MIN;
int main()
{
    int n,opt=0,num1=-1,num2=-1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
        sort(a[i],a[i]+3);
    }
    for(int i = 1;i<=n;i++)
    {
        long long temp=pow(min(a[i][0],min(a[i][1],a[i][2])),3)/4;
        if(temp>ans)
        {
            ans=temp;
            num1=i;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if(a[i][1]==a[j][1]&&a[i][2]==a[j][2])
            {
                long long temp=pow(min(a[i][0]+a[j][0],min(a[i][1],a[i][2])),3)/4;
                if(temp>ans)
                {
                    opt=1;
                    num1=i;num2=j;
                    ans=temp;
                }
            }
        }
    }
    if(opt==0)
    {
        printf("0\r\n%lld\r\n%lld",num1,ans);
    }
    else
    {
        printf("1\r\n%lld %lld\r\n%lld",num1,num2,ans);
    }
    return 0;
}
