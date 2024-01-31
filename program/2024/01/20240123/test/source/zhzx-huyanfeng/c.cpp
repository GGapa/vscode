#include<bits/stdc++.h>
using namespace std;
int n,m,t; 
constexpr int maxn=1e5+5;
typedef long long ll;
constexpr ll mod=998244353;
int cnt;vector<int> a;
ll qpow(ll a,int b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
ll iv,g[1005][1005],f[1005];
vector<vector<int> >chi; 
map<vector<int>,int> p;
void dfs(int t,int lst,int sum){
	if(t==n){
		if(sum==m)p[a]=cnt++,
		chi.push_back(a);
		return;
	}
	for(int i=lst;i<=m-sum;i++) a[t]=i,dfs(t+1,i,sum+i);
}
inline void solve1(){
	iv=qpow(m,mod-2);ll ivv=qpow((n-1)*m%mod,mod-2);
	a.resize(n);dfs(0,0,0);
	for(int i=0;i<n-1;i++) a[i]=0;
	a[n-1]=m,g[p[a]][p[a]]=1;
	for(int z=1;z<cnt;z++){
		a=chi[z];g[z][z]=1;g[z][cnt]=1;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(!a[i]) continue;
			vector<int> t=a;ll w=t[i]*(m-t[j])%mod;t[i]--,t[j]++;
			sort(t.begin(),t.end());
			g[z][p[t]]=(g[z][p[t]]-w*iv%mod*ivv%mod+mod)%mod;
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=i;j<cnt;j++) if(g[j][i]){
			swap(g[i],g[j]);
			break; 
		}
		for(int j=0;j<cnt;j++)if(i!=j){
			if(g[j][i]){
				ll q=g[j][i]*qpow(g[i][i],mod-2)%mod;
				for(int k=0;k<=cnt;k++) g[j][k]=(g[j][k]+mod-g[i][k]*q%mod)%mod;
			}
		}
	}
	for(int i=0;i<cnt;i++) f[i]=(g[i][cnt]*qpow(g[i][i],mod-2)%mod)%mod;
	while(t--){
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a.begin(),a.end());
		cout<<f[p[a]]<<'\n';
	}
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>t;solve1();
}
