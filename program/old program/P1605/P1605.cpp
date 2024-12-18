//P1605 迷宫
#include <iostream>
#include <cstdio>
using namespace std;
int map[10][10],used[10][10];
int n,m,sx,sy,fx,fy,t,ans=0;
inline void dfs(int x,int y)
{
    if(used[x][y]==1||map[x][y]==1||x>n||y>m||x<1||y<1)return;
    if(x==fx&&y==fy){ans++;return;}
    used[x][y]=1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
    used[x][y]=0;
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i = 1;i<=t;i++)
    {
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        map[tx][ty]=1;
    }
    dfs(sx,sy);
    cout<<ans<<endl;
    return 0;
}
