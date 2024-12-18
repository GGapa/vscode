//P1387 最大正方形
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 101;
int map[maxn][maxn],f[maxn][maxn],n,m,ans=0;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==1)f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
            ans=max(ans,f[i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}