#include<bits/stdc++.h>
using namespace std;
const int N=805,mod=1e9+7;
struct Graph{
	struct edge{
		int y,w;
	};
	vector<edge>G[N];
	void add(int x,int y,int z){G[x].push_back((edge){y,z});} 
};
struct tree{
	int dep[N];
	Graph G1,G2;
	void dfs(int u,int tp,int fa){
		bool fl=0;
		dep[u]=dep[fa]+1;
		if(G1.G[u].size()!=1)G2.add(tp,u,dep[u]-dep[tp]),fl=1;
		for(auto i:G1.G[u])
			dfs(i.y,(fl?u:tp),u);
	}
}T1,T2;
struct gx{
	int cnt,sum;
};
bool operator < (gx x,gx y){return x.cnt<y.cnt;}
vector<gx>v;
int n,m,q,mx;
bool dfs(int x,int y){
	if(T1.G2.G[x].size()!=T2.G2.G[y].size())return 0;
	bool fl=1;
	for(int i=0;i<T1.G2.G[x].size();i++){
		int v1=T1.G2.G[x][i].y,w1=T1.G2.G[x][i].w;
		int v2=T2.G2.G[y][i].y,w2=T2.G2.G[y][i].w;
		v.push_back((gx){w1,w2});
		mx=max(mx,w2);
		fl&=dfs(v1,v2);
	}
	return fl;
}
bool check(){return dfs(0,0);}
set<int>st;
int dp[11][N];
int f[N],g[N];
void calc(int x){
	bool fl=0;
	for(int i=x,cnt=1;i;i>>=1,cnt++){
		if(!(i&1))continue;
		if(!fl){
			memcpy(f,dp[cnt],sizeof(f));
			fl=1;continue;
		}
		memset(g,0,sizeof(g));
		for(int j=1;j<=mx;j++){
			if(!f[j])continue;
			for(int k=1;j+k<=mx;k++)
				g[j+k]=(g[j+k]+1ll*f[j]*dp[cnt][k]%mod)%mod;
		}
		memcpy(f,g,sizeof(f));
	}
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=2,x;i<=n;i++)cin>>x,T1.G1.add(x,i,0);
	for(int i=2,x;i<=m;i++)cin>>x,T2.G1.add(x,i,0);
	T1.dfs(1,0,0),T2.dfs(1,0,0);
	cin>>q;
	if(!check()){
		while(q--)cout<<0<<'\n';
		return 0;
	}
	sort(v.begin(),v.end());
	while(q--){
		int op,x,ans=1;
		cin>>op>>x;
		if(op==1)st.insert(x);
		else st.erase(x);
		memset(dp,0,sizeof(dp));
		for(auto i:st)dp[1][i]=1;
		for(int i=2;i<=10;i++){
			for(int j=1;j<=mx;j++){
				if(!dp[i-1][j])continue;
				for(int k=1;j+k<=mx;k++)
					dp[i][j+k]=(dp[i][j+k]+1ll*dp[i-1][j]*dp[i-1][k]%mod)%mod;
			}
		}
		for(int i=0;i<v.size();){
			int l=i,r=i;
			while(v[r].cnt==v[l].cnt&&r<v.size())r++;
			calc(v[l].cnt);
			for(int j=l;j<r;j++)ans=1ll*ans*f[v[j].sum]%mod;
			i=r;
			if(!ans)break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
