#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=905,M=1805,mod=998244353;
int h[N],nex[M<<1],to[M<<1],e[M<<1],tot;
void add(int x,int y,int z){to[++tot]=y,nex[tot]=h[x],e[tot]=z,h[x]=tot;}
struct edge{
	int x,y,z;
}ed[M];
int n,m,k,p,t;
int a[N];
int fr[M<<1],inv[M<<1];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int C(int x,int y){if(x<y)return 0;return fr[x]*inv[y]%mod*inv[x-y]%mod;}
namespace sub1{
	int ans;
	bool vis[25];
	void solve(){
		int iv=ksm(C(n+m,p),mod-2);
		for(int i=0;i<(1<<n);i++){
			int res=0,cnt=0,nw=0;
			bool fl=1;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=n;j++)
				if((i>>(j-1))&1)vis[j]=1,res+=a[j],cnt++;
			for(int j=1;j<=m;j++){
				if(vis[ed[j].x]==0&&vis[ed[j].y]==0)res+=ed[j].z,cnt++;
				if(vis[ed[j].x]==1&&vis[ed[j].y]==1){fl=0;break;}
			}
			if(!fl)continue;
			res%=mod;
			for(int j=0;j<=min(p,cnt);j++){
				int cs=C(n+m-cnt,p-j)*C(cnt,j)%mod;
				nw=nw+cs*ksm((res+j*t%mod)%mod,k)%mod;
			}
			ans=(ans+nw*iv%mod)%mod;
		}
		cout<<ans<<'\n';
	}
}
namespace sub2{
	int dp[N][2][35];
	int g[2][35];
	void dfs(int u,int fa){
		dp[u][0][0]=1;
		for(int i=0;i<=k;i++)dp[u][1][i]=ksm(a[i],i);
		for(int i=h[u];i;i=nex[i]){
			int v=to[i];
			if(v==fa)continue;
			dfs(v,u);
			memset(g,0,sizeof(g));
			for(int j=0;j<=k;j++){
				for(int l=0;l<=j;l++){
					g[1][j]+=C(j,l)*dp[u][1][l]%mod*dp[v][0][j-l]%mod,g[1][j]%=mod;
					g[0][j]+=C(j,l)*dp[u][0][l]%mod*dp[v][1][j-l]%mod,g[0][j]%=mod;
					int res=0;
					for(int o=0;o<=j-l;o++)res+=C(j-l,o)*dp[v][0][o]%mod*ksm(e[i],j-l-o)%mod,res%=mod;
					g[0][j]+=C(j,l)*dp[u][0][l]%mod*res%mod,g[0][j]%=mod;
				}
			}
			memcpy(dp[u],g,sizeof(dp[u]));
		}
	}
	void solve(){
		dfs(1,0);
		cout<<(dp[1][0][k]+dp[1][0][k])%mod<<'\n';
	}
}
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>p>>t;
	inv[0]=fr[0]=1;
	for(int i=1;i<=n+m;i++)fr[i]=fr[i-1]*i%mod;
	inv[n+m]=ksm(fr[n+m],mod-2);
	for(int i=n+m-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		ed[i]=(edge){x,y,z};
		add(x,y,z),add(y,x,z);
	}
	if(n<=17){sub1::solve();return 0;}
	if(m==n-1&&p==0){sub2::solve();return 0;}
	return 0;
}
