//P2165 [AHOI2009]飞行棋
//直径所对的圆周角为九十度
#include <iostream>
#include <cstdio>
using namespace std;
int C=0,n,a[21],ans=0;
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        a[i]=a[i-1]+tmp;
        C+=tmp;
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if((a[j]-a[i])*2==C)ans++;
        }
    }
    printf("%d",ans*(ans-1)/2);
    return 0;
}