#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 150
int map[maxn][maxn],f[maxn][maxn];
int n,ans=-10000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
        {
            cin>>map[i][j];
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+map[i][j];
        }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            for(int x = i;x<=n;x++)
            {
                for(int y = j;y<=n;y++)
                {
                    ans=max(ans,f[x][y]-f[i-1][y]-f[x][j-1]+f[i-1][j-1]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}