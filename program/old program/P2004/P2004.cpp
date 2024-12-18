//P2004 领地选择
#include <iostream>
#include <limits.h>
#include <cstdio>
using namespace std;
#define maxn 1005
int n,m,c;
long long map[maxn][maxn];
long long numans=LLONG_MIN,ansx,ansy;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>c;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            int tmp;
            cin>>tmp;
            map[i][j]=map[i-1][j]+map[i][j-1]-map[i-1][j-1]+tmp;
        }
    }
    for(int i=1;i<=n-c+1;i++)
    {
        for(int j=1;j<=m-c+1;j++)
        {
            int x=i+c-1,y=j+c-1;
            //ans=max(ans,);
            //cout<<map[i][j]<<" ";
            if(numans<map[x][y]-map[i-1][y]-map[x][j-1]+map[i-1][j-1])
            {
                numans=map[x][y]-map[i-1][y]-map[x][j-1]+map[i-1][j-1];
                ansx=i;
                ansy=j;
            }

        }
        //cout<<endl;
    }
    cout<<ansx<<" "<<ansy<<endl;
    return  0;
}