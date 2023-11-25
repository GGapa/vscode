// P1199 [NOIP2010 普及组] 三国游戏
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 505
int peo[maxn][maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            scanf("%d",&peo[i][j]);
            peo[j][i]=peo[i][j];
        }
        sort(peo[i]+1,peo[i]+1+n);
    }
    int ans=0;
    for(int i = 1;i<=n;i++)
    {
        if(peo[i][n-1]>ans)
        {
            ans=peo[i][n-1];
        }
    }
    printf("1\r\n%d",ans);
    return 0;
}