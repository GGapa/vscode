#include<bits/stdc++.h>
using namespace std;
int n,m;
constexpr int maxn=805;
vector<int> e[maxn][2];
int a[maxn],b[maxn],tot,ff=1;
void dfs(int p,int q){
	int aa=1,bb=1;
	while(e[p][0].size()==1) p=e[p][0][0],aa++;
	while(e[q][1].size()==1) q=e[q][1][0],bb++;
	a[++tot]=aa,b[tot]=bb;
	if(e[p][0].size()!=e[q][1].size()) return ff=0,void();
	for(int i=0;i<(int)e[p][0].size();i++) dfs(e[p][0][i],e[q][1][i]);
}
typedef long long ll;
constexpr ll mod=1e9+7;
ll f[maxn][maxn],fac[maxn],inv[maxn];
ll qpow(ll a,int b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n>>m;
	for(int i=2,x;i<=n;i++) cin>>x,e[x][0].push_back(i);
	for(int i=2,x;i<=m;i++) cin>>x,e[x][1].push_back(i);
	dfs(1,1);
	int ma=0,mb=0;
	for(int i=1;i<=tot;i++) ma=max(ma,a[i]),mb=max(mb,b[i]);
	int q;cin>>q;
	for(int i=fac[0]=1;i<=ma;i++) fac[i]=fac[i-1]*i%mod;
	inv[ma]=qpow(fac[ma],mod-2);
	for(int i=ma;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	set<int> s;f[0][0]=1;
	while(q--){
		int op,x;cin>>op>>x;
		if(op==1){
			for(int i=ma;i>=1;i--)
			for(int j=mb;j>=1;j--)
			for(int k=1;k*x<=j&&k<=i;k++)
				f[i][j]=(f[i][j]+f[i-k][j-x*k]*inv[k]%mod)%mod;
		}
		else{
			for(int i=1;i<=ma;i++)
			for(int j=1;j<=mb;j++)
			for(int k=1;k*x<=j&&k<=i;k++)
				f[i][j]=(f[i][j]+mod-f[i-k][j-x*k]*inv[k]%mod)%mod;
		}
		ll ans=ff;
		for(int i=1;i<=tot;i++) ans=ans*f[a[i]][b[i]]%mod*fac[a[i]]%mod;
		cout<<ans<<'\n';
	}
}
