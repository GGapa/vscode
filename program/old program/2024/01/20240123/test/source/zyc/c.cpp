#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000001;
const ll P=998244353;
ll n,m,f[N];
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll inv(ll a)
{
    ll x,y;
    exgcd((a%P+P)%P,P,x,y);
    return x;
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int T;
    scanf("%lld%lld%d",&n,&m,&T);
    for(ll i=1;i<=m-1;++i)
    {
        f[i+1]=((m*m%P+m*(n-4)*i%P+2*i*i%P)*f[i]%P-(m*(n-2)*i%P+i*i%P)*f[i-1]%P-m*(n-1)*i%P)%P*inv((m-i)*(m-i)%P)%P;
    }
    while(T--)
    {
        ll s=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            scanf("%d",&x);
            s=(s+f[x])%P;
        }
        s=(s-f[m])%P;
        printf("%lld\n",(s%P+P)%P);
    }
    return 0;
}