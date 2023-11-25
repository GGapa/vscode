#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int maxn = 1e5+10;
#define int long long
int n,m;
int a[maxn];
bool used[maxn];

void dfs(int x,int y)
{
    if(x!=7)
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    if((m==n/2+1&&n%2!=0)||(m==n/2&&n%2==0))
    {
        if(n%2!=0)
        {
            int ans=0;
            for(int i = 1;i<=n-2;i+=2)
            {
                ans+=abs(a[i+2]-a[i]);
            }
            cout<<ans<<endl;
        }
        else if(n%2==0)
        {
            int ans=0;
            for(int i = n-2;i>4;i-=2)
            {
                ans+=abs(a[i]-a[i+2]);
            }
            cout<<min(ans+abs(a[3]-a[1]),ans+abs(a[4]-a[2]))<<endl;
        }
    }
    else if(m==1)
    {
        cout<<0<<endl;

    }
    if(n<=6)
    {
        int ans=INT_MAX;
    }
    else
    {
        int ans=INT_MAX;
        for(int i = 1;i<=n;i++)
        {
            int num=0;
            if(i+2*m-1>n)break;
            for(int j = i+2,it=2;j<=n&&it<=m;j+=2,it++)
            {
                num+=abs(a[j]-a[j-2]);
            }
            ans=min(ans,num);
        }
        cout<<ans<<endl;

    }
}
