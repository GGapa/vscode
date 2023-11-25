
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long n,k;
long long a[300005]={0},ans=0;
struct stru
{
    int d,m;
}b[300005];
bool cmp(stru x,stru y)
{
    return x.d<y.d;
}
int main()
{
    cin>>n>>k;
    for(int i = 0;i<=300000;i++)a[i]=k;
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld %lld",&b[i].d,&b[i].m);
    }
    sort(b+1,b+1+n,cmp);
    for(int i = 1;i<=n;i++)
    {
        if(b[i].m<=a[b[i].d])a[b[i].d]-=b[i].m,ans+=b[i].m;
        else if(b[i].m<=a[b[i].d]+a[b[i].d+1])
        {
            ans+=b[i].m;
            b[i].m-=a[b[i].d];
            a[b[i].d]=0;
            a[b[i].d+1]-=b[i].m;
        }
        else
        {
            ans+=(a[b[i].d]+a[b[i].d+1]);
            a[b[i].d]=a[b[i].d+1]=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
