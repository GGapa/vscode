//P2335 [SDOI2005]位图
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;

int map[155][155],n,m,ans[155][155];

inline void dfs(int x,int y,int step)
{
    if(x<1||y<1||x>n||y>m||step>=ans[x][y]||(map[x][y]==1&&step!=0))return ;
    ans[x][y]=step;
    dfs(x+1,y,step+1);
    dfs(x,y+1,step+1);
    dfs(x-1,y,step+1);
    dfs(x,y-1,step+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(ans,10000,sizeof(ans));
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if (map[i][j]==1)
            {
                dfs(i,j,0);
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}