#include <iostream>
#include <cstring>
using namespace std;
#define ull unsigned long long
ull a[1005][1005],sum[1005][1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        memset(a,0,sizeof(a));
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
                    cin>>a[i][j];
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        ull ans=0;
        while(q--)
        {
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            ans^=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}