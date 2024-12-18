#include <iostream>
using namespace std;
#include <limits.h>
#define maxn 5000001
int d[maxn];
int a[maxn];
int main()
{
    int n,p,x,y,z,i,ans=INT_MAX;
    cin>>n>>p;
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++)d[i]=a[i]-a[i-1];
    for(int i = 1;i<=p;i++)
    {
        cin>>x>>y>>z;
        d[x]+=z;
        d[y+1]-=z;
    }
    for(int i = 1;i<=n;i++)
    {
        a[i]=a[i-1]+d[i];
        ans=min(a[i],ans);
    }
    cout<<ans<<endl;
}

