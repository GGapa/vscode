#include<bits/stdc++.h>
#define db double
#define int ll
#define ll long long
#define ull unsigned long long
#define pb emplace_back
#define MP make_pair
#define pii pair<int, int>
#define vec vector<int>
#define fi first
#define se second
#define ls k<<1
#define rs k<<1|1
#define CLK (double)clock()/(double)CLOCKS_PER_SEC
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(register int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int N=905,mod=998244353;
int n,m,k,p,t,fac[N],inv[N],v[N];
vector<pii> G[N];array<int,3> E[N*2];
void add(int &x,int y){(x+=y)%=mod;}
int Qpow(int b,int p){
    int res=1ll;
    while(p){
        if(p&1)(res*=b)%=mod;
        (b*=b)%=mod;p>>=1;
    }
    return res;
}
void init(int n){
    fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
    inv[n]=Qpow(fac[n],mod-2);for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int n,int m){if(n<m||m<0)return 0;return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int f[N][2][35],fl[2][35],h[N][2];
namespace Case1{
    void dfs(int x,int fa){
        f[x][0][0]=1;for(int i=0,c=1;i<=k;i++,c=c*v[x]%mod)f[x][1][i]=c*inv[i]%mod;
        h[x][0]=h[x][1]=1;
        for(auto t:G[x]){
            int y=t.fi,w=t.se;if(y==fa)continue;
            dfs(y,x);static int hl[2];hl[0]=h[x][0],hl[1]=h[x][1];
            h[x][0]=hl[0]*(h[y][0]+h[y][1])%mod,h[x][1]=hl[1]*h[y][0]%mod;
            for(int i=0;i<2;i++)for(int j=0;j<=k;j++)fl[i][j]=f[x][i][j],f[x][i][j]=0;
            // memcpy(fl,f[x],sizeof fl),memset(f[x],0,sizeof f[x]);
            for(int i=0;i<=k;i++)for(int j=0;i+j<=k;j++){    
                add(f[x][1][i+j],fl[1][i]*f[y][0][j]%mod);
                add(f[x][0][i+j],fl[0][i]*f[y][1][j]%mod);
            }
            for(int i=0;i<=k;i++)for(int j=0;i+j<=k;j++)for(int l=0,c=1;i+j+l<=k;l++,c=c*w%mod){
                int coef=fl[0][i]*f[y][0][j]%mod;
                add(f[x][0][i+j+l],coef*c%mod*inv[l]%mod);
            }
        }
        // cout<<x<<' ';
        // cout<<x<<' '<<f[x][0][0]<<' '<<f[x][1][1]<<"\n";
    }
    void MAIN(){
        dfs(1,0);int ans=(f[1][1][k]+f[1][0][k])*fac[k]%mod;
        cout<<(ans+mod)%mod<<"\n";
    }
}
namespace Case2{
    int Count(){
        for(int i=1;i<=n;i++)for(int j=0;j<2;j++)for(int l=0;l<=k;l++)f[i][j][l]=0;
        Case1::dfs(1,0);int ans=(f[1][1][k]+f[1][0][k])*fac[k]%mod;
        // cout<<ans<<"\n";
        return ans;
    }
    void MAIN(){
        int ans=0;
        for(int i=1;i<=n;i++)v[i]+=t,add(ans,Count()),v[i]-=t;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)G[j].clear();
            for(int j=1;j<=m;j++){
                int x=E[j][0],y=E[j][1],w=E[j][2];
                if(i==j)w+=t;
                G[x].pb(y,w),G[y].pb(x,w);
            }
            add(ans,Count());
        }
        ans=ans*Qpow(n+m,mod-2)%mod;cout<<(ans+mod)%mod<<"\n";
    }
}
void MAIN(){
    n=read(),m=read(),k=read(),p=read(),t=read();init(max(n,k));
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1,x,y,w;i<=m;i++)
        x=read(),y=read(),w=read(),G[x].pb(y,w),G[y].pb(x,w),E[i]={x,y,w};
    if(m==n-1&&!p)return Case1::MAIN(),void();
    if(m==n-1&&p==1)return Case2::MAIN(),void();
}
signed main(){
    freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
    int T=1;while(T--)MAIN();
//  printf("\nTIME:%lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
