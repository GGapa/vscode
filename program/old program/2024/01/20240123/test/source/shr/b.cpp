#include <bits/stdc++.h>
using namespace std;
using V=vector<int>;
const int N=805,mod=1e9+7;
int n,m,q,tot,fl,iv[N],a[N],b[N];
V e[N],g[N],va,vb;
inline void fix(int&x) {if(x>=mod) x-=mod;}
int inv(int x){
	int res=1,y=mod-2;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod;
	return res;
}
void dfs1(int x){
	if(e[x].size()!=1) va.push_back(x);
	for(int y:e[x]) dfs1(y);
}
void dfs2(int x){
	if(g[x].size()!=1) vb.push_back(x);
	for(int y:g[x]) dfs2(y);
}
struct sb{
	int k,s,ans;
	vector<int> a;
	void init(int _k,int _s){
		k=_k;s=_s;
		a.resize(s+1);
	}
	int upd(int x,int op){
		if(x>s) return ans;
		if(op==1) a[x]++;
		else a[x]--;
		int t=0;
		for(int i=1;i<=s;i++) if(a[i]) {t=i;break;}
		if(!t) return ans=0;
		int sz=s-k*t;
		if(sz<0) return ans=0;
		V v1(begin(a)+t,begin(a)+t+sz+1),v2(sz+1);
		for(int i=1;i<=sz;i++){
			v2[i]=v1[i];
			for(int j=1;j<i;j++) fix(v2[i]+=mod-1ll*iv[i]*j%mod*v2[j]%mod*v1[i-j]%mod);
		}
		for(int i=0;i<=sz;i++) v2[i]=1ll*k*v2[i]%mod;
		for(int i=v1[0]=1;i<=sz;i++){
			v1[i]=0;
			for(int j=1;j<=i;j++) fix(v1[i]+=1ll*iv[i]*v1[i-j]%mod*v2[j]%mod*j%mod);
		}
		return ans=v1[sz];
	}
}f[N];
void add(int x,int y){
	if(e[x].size()!=g[y].size()) fl=1;
	int dx=0,dy=0;
	while(1){
		dx++;
		if(e[x=a[x]].size()!=1) break;
	}
	while(1){
		dy++;
		if(g[y=b[y]].size()!=1) break;
	}
	f[tot++].init(dx,dy);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) iv[i]=inv(i);
	for(int i=2;i<=n;i++) cin>>a[i],e[a[i]].push_back(i);
	for(int i=2;i<=m;i++) cin>>b[i],g[b[i]].push_back(i);
	dfs1(1);dfs2(1);
	int sa=va.size(),sb=vb.size();
	if(sa!=sb) fl=1;
	else for(int i=0;i<sa;i++) add(va[i],vb[i]);
	cin>>q;
	for(int op,x;q--;){
		cin>>op>>x;
		if(fl) cout<<"0\n";
		else{
			int ans=1;
			for(int i=0;i<tot;i++) ans=1ll*ans*f[i].upd(x,op)%mod;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
