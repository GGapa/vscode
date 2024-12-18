//P2049 魔术棋子
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 101
int m,n,k,map[maxn][maxn],num=1,fx[2]={0,1},fy[2]={1,0};
bool used[maxn][maxn][maxn],val[maxn];
long long ans=1;
struct stru
{
    int x,y,num;
};
queue<stru> q;
int main()
{
    memset(used,0,sizeof(used));
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
            map[i][j]%=k;
        }
    }
    q.push({1,1,map[1][1]});
    while(!q.empty())
    {
        if(q.front().x==n&&q.front().y==m)
        {
            val[q.front().num]=true;
        }
        else
        {
            for(int i = 0;i<2;i++)
            {
                int X=q.front().x+fx[i];
                int Y=q.front().y+fy[i];
                int N=q.front().num*map[X][Y]%k;
                if(X<=0||Y<=0||X>n||Y>m||used[X][Y][N])
                {
                    continue;
                }
                else
                {
                    q.push({X,Y,N});
                    used[X][Y][N]=true;
                }
            }
        }
        q.pop();
    }
    int cnt=0;
    for(int i = 0;i<=maxn;i++)if(val[i])cnt++;
    cout<<cnt<<endl;
    for(int i = 0;i<k;i++)if(val[i])cout<<i<<" ";
    return 0;
}