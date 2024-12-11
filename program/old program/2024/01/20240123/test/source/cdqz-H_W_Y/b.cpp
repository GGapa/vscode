#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

int read(){
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
  return x*f;
}

void prt(ll x){
  int p[25],tmp=0;
  if(x==0) putchar('0');
  if(x<0) putchar('-'),x=-x;
  while(x) p[++tmp]=x%10,x/=10;
  for(int i=tmp;i>=1;i--) putchar(p[i]+'0');
  putchar('\n');
}

const int N=1e3+5;
const ll mod=1e9+7;
int m,n1,n2,cnt=0,n,w[N];
bool flag=false;
ll f[N][N],ans=0,fac[N],inv[N];
pii a[N];

void add(ll &x,ll y){x=(x+y)%mod;}
void dec(ll &x,ll y){x=(x-y+mod)%mod;}

ll qpow(ll a,ll b){
  ll res=1ll;
  while(b){if(b&1) res=res*a%mod;a=a*a%mod;b>>=1;}
  return res;
}

void init(){
  fac[0]=1;
  for(int i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
  inv[N-1]=qpow(fac[N-1],mod-2);
  for(int i=N-1;i>=1;i--) inv[i-1]=1ll*inv[i]*i%mod;
}

ll binom(int n,int m){
  //cout<<"binom("<<n<<","<<m<<")= "<<fac[n]*inv[m]%mod*inv[n-m]%mod<<endl;
  return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

struct node{
  int fa[N],id[N],n,c[N];
  vector<int> G[N],g[N];
  
  void dfs(int u,int tag){
    if(tag) id[u]=u;
    else id[u]=id[fa[u]];
    ++c[id[u]];
    //cout<<"dfs("<<u<<")= "<<id[u]<<endl;
    if(g[u].size()==1) dfs(g[u][0],0);
    else for(auto v:g[u]) dfs(v,1),G[id[u]].pb(id[v]);
  }

  void init(int _n){
    n=_n;
    for(int i=2;i<=n;i++) cin>>fa[i],g[fa[i]].pb(i);
    dfs(1,1);
  }
}T1,T2;

bool cmp(int u1,int u2){
  //cout<<"cmp("<<u1<<","<<u2<<")"<<endl;
  if(T1.G[u1].size()!=T2.G[u2].size()) return false;
  for(int i=0;i<(int)T1.G[u1].size();i++) if(!cmp(T1.G[u1][i],T2.G[u2][i])) return false;
  return true;
}

void dfs(int u1,int u2){
  a[++cnt]={T2.c[u2],T1.c[u1]};n=max(a[cnt].fi,n);
  for(int i=0;i<(int)T1.G[u1].size();i++) dfs(T1.G[u1][i],T2.G[u2][i]);
}

void ins(int x){
  for(int i=n;i>=x;i--)
    for(int k=1;k*x<=i&&k<=w[i];k++)
      for(int j=0;j<=min(w[i]-k,i-k*x);j++)
        add(f[i][j+k],f[i-k*x][j]*binom(j+k,k)%mod);
}

void del(int x){
  for(int i=x;i<=n;i++)
    for(int k=1;k*x<=i&&k<=w[i];k++)
      for(int j=0;j<=min(w[i]-k,i-k*x);j++)
        dec(f[i][j+k],f[i-k*x][j]*binom(j+k,k)%mod);
}

void sol(){
//   for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
//   f[0][0]=1;
//   for(int i=1;i<=n;i++)
//     for(int j=1;j<=n;j++)
//       for(int x=1;x<=i;x++) 
//         if(vis[x]) add(f[i][j],f[i-x][j-1]);
  ans=1ll;
  for(int i=1;i<=cnt;i++) ans=1ll*ans*f[a[i].fi][a[i].se]%mod;
  prt(ans);
}

int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  n1=read(),n2=read();
  T1.init(n1),T2.init(n2);init();
  n=0;
  if(!cmp(1,1)) flag=true;
  else{
    dfs(1,1);
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--) w[a[i].fi]=max(w[a[i].fi],a[i].se);
    for(int i=n;i>=1;i--) w[i]=max(w[i],w[i+1]);
  }
  m=read();
  //cout<<"flag= "<<flag<<endl;
  memset(f,0,sizeof(f));
  f[0][0]=1;
  while(m--){
    int op=read(),x=read();
    if(flag) prt(0);
    op==1?ins(x):del(x);
    sol(); 
    //for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<"f("<<i<<","<<j<<")= "<<f[i][j]<<endl;
  }
  return 0;
}