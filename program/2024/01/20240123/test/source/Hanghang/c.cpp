#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1003,H=998244353;
ll Ksm(ll x,ll y)
{
    ll s=1;
    for(ll i=1;i<=y;i<<=1,x=x*x%H)if(i&y)s=s*x%H;
    return s;
}
ll n,m,tot=0,ivnm,ivm;
vector<ll>ve[N];
map<vector<ll>,ll>mp;
void Dfs(int x,int y,vector<ll>z)
{
    if(y>m)return;
    if(x==n+1){if(y==m)mp[z]=++tot,ve[tot]=z;return;}
    for(int i=0;i<=m;i++)z.push_back(i),Dfs(x+1,y+i,z),z.pop_back();
}
struct Guass
{
    ll f[N][N];
    void Work()
    {
        for(int i=1;i<=tot;i++)for(int j=1;j<=tot;j++)if(j!=i)
        {
            ll bas=f[j][i]*Ksm(f[i][i],H-2)%H;
            for(int k=i;k<=tot+1;k++)f[j][k]=(f[j][k]-f[i][k]*bas%H+H)%H;
        }
    }
}G;
void Init()
{
    ivnm=Ksm((n-1)*m%H,H-2);ivm=Ksm(m,H-2);
    vector<ll>zz;Dfs(1,0,zz);
    for(int i=1;i<=tot;i++)G.f[i][i]=1;
    for(int i=1;i<=tot;i++)
    {
        int x=0;vector<ll>now;
        for(int j=0;j<n;j++)x+=ve[i][j]>0,now.push_back(ve[i][j]);
        if(x==1)continue;
        G.f[i][tot+1]=1;ll sy=0;
        for(int j=0;j<n;j++)if(ve[i][j]>0)for(int k=0;k<n;k++)if(j!=k)
        {
            now[j]--;now[k]++;int id=mp[now];now[j]++;now[k]--;
            ll sx=ve[i][j]*ivm%H*(m-ve[i][k])%H*ivnm%H;
            G.f[i][id]=(G.f[i][id]-sx+H)%H;
        }
        for(int j=1;j<=tot;j++)if(j!=i)sy=(sy-G.f[i][j]+H)%H;
        G.f[i][i]=sy;
    }
    G.Work();
}
void Solve()
{
    vector<ll>a;
    for(int i=0,x;i<n;i++)cin>>x,a.push_back(x);
    int id=mp[a];cout<<G.f[id][tot+1]*Ksm(G.f[id][id],H-2)%H<<endl;
}
namespace Sub1
{
    ll n,val[N][5];
    void Solve()
    {
        ll x,y;cin>>x>>y;
        cout<<val[x][4]*Ksm(val[x][2],H-2)%H<<endl;
    }
    void Work()
    {
        ivm=Ksm(m,H-2);val[0][2]=val[m][2]=1;
        for(ll i=1;i<m;i++)
        {
            val[i][1]=i*ivm%H*i*ivm%H;val[i][3]=(m-i)*ivm%H*(m-i)*ivm%H;
            val[i][1]=(H-val[i][1]);val[i][3]=(H-val[i][3]);val[i][2]=(val[i][1]+val[i][3])%H;
            val[i][4]=1;
        }
        cout<<val[1][1]<<endl;
        for(int i=0;i<=m;i++)cout<<val[i][1]<<" "<<val[i][2]<<" "<<val[i][3]<<" "<<val[i][4]<<endl;
        for(ll i=0;i<=m;i++)
        {
            cout<<i<<endl;
            if(i)
            {
                ll bas=val[i-1][3]%H*Ksm(val[i][2],H-2)%H;
                val[i-1][3]=(val[i-1][3]-val[i][2]*bas%H+H)%H;
                val[i-1][4]=(val[i-1][4]-val[i][4]*bas%H+H)%H;
            }
            if(i<m)
            {
                ll bas=val[i+1][1]%H*Ksm(val[i][2],H-2)%H;
                val[i+1][1]=(val[i+1][1]-val[i][2]*bas%H+H)%H;
                val[i+1][2]=(val[i+1][2]-val[i][3]*bas%H+H)%H;
                val[i+1][4]=(val[i+1][4]-val[i][4]*bas%H+H)%H;
            }
            for(int i=0;i<=m;i++)cout<<val[i][1]<<" "<<val[i][2]<<" "<<val[i][3]<<" "<<val[i][4]<<endl;
        }
        int T;cin>>T;
        while(T--)Solve();
    }
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w".stdout);
    cin>>n>>m;
    //if(n==2){Sub1::Work();return 0;}
    int T;cin>>T;Init();
    while(T--)Solve();
    return 0;
}