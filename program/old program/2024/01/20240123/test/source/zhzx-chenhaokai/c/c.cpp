#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=300;
const ll mod=998244353;
int cnt,n,m,T;
ll g[N][N],f[N],inv[N];
vector<int>a,b;
vector<vector<int> >id;
map<vector<int>,int>mp;
void dfs(int t,int la,int sum){
	if(t==n){
		if(sum==m)mp[a]=cnt++,id.pb(a);
		return;
	}for(int i=la;sum+i<=m;i++){a[t]=i;dfs(t+1,i,sum+i);}
}
ll Pow(ll a,ll b){
	ll rec=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)rec=rec*a%mod;
	return rec;
}
void Gauss(int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			if(g[j][i]){if(i^j)swap(g[j],g[i]);break;}
		for(int j=0;j<n;j++)if(i^j)
			if(g[j][i]){
				ll w=g[j][i]*Pow(g[i][i],mod-2)%mod;
				for(int k=0;k<=n;k++)g[j][k]=(g[j][k]-g[i][k]*w%mod+mod)%mod;
			}
	}for(int i=0;i<n;i++)f[i]=g[i][n]*Pow(g[i][i],mod-2)%mod;
}
void solve1(){
	ll invm=Pow(m,mod-2),invn=Pow((n-1)*m%mod,mod-2);
	a.resize(n);dfs(0,0,0);
	for(int i=0;i<n;i++)a[i]=0;
	a[n-1]=m;g[mp[a]][mp[a]]=1;
	for(int l=1;l<id.size();l++){
		a=id[l];g[l][l]=1;g[l][cnt]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(!a[i])continue;
				b=a;b[i]--;b[j]++;
				sort(b.begin(),b.end());
				g[l][mp[b]]=(g[l][mp[b]]-invm*invn%mod*a[i]%mod*(m-a[j])%mod+mod)%mod;
			}
	}Gauss(cnt);
	while(T--){
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a.begin(),a.end());
		printf("%lld\n",f[mp[a]]);
	}
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	solve1();
}

