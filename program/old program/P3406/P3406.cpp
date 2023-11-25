//P3406 海底高铁
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 100005
int n,m;
long long a[maxn],b[maxn],c[maxn],p[maxn];
long long f[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
   for(int i = 1;i<=m;i++)cin>>p[i];
   for(int i = 1;i<n;i++)
   {
        cin>>a[i]>>b[i]>>c[i];
   }
    for(int i = 1;i<m;i++)
    {
        f[min(p[i],p[i+1])]++;
        f[max(p[i],p[i+1])]--;
    }
    unsigned long long ans=0;
    for(int i = 1;i<n;i++)
    {
        f[i]+=f[i-1];
        //cout<<f[i]<<endl;
        ans+=min(a[i]*f[i],c[i]+b[i]*f[i]);
    }
    cout<<ans<<endl;
    return 0;
}