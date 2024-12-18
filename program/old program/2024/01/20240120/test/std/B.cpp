#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#define bitc __builtin_popcount
#define pb emplace_back
#define mp std::make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
int cmax(int &x,int y){ return x=x>y?x:y; }
int cmin(int &x,int y){ return x=x<y?x:y; }
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
ll &read(ll &r){
	bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
	return r=w?-r:r;
}
int &readint(int &r){
	r=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
	return r=w?-r:r;
}
const int N=1010;
const ll mod=1000000007;
inline int cadd(int &x,int y){return x=(x+y>=mod)?(x+y-mod):(x+y);}
inline int cmul(int &x,int y){return x=1ll*x*y%mod;}
inline int Add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
inline int Mul(int x,int y){return 1ll*x*y%mod;}
inline int Mod(int x){return (x>=mod)?(x-mod):(x<0?(x+mod):x);}
int n,m;
int z[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int a[N],vis[N];
ll val[N],X,Y;
vpii eg[N];
int f[N][32768];
int ans=0;
void dfs(int x,int fa){
	fill(f[x],f[x]+m,1);
	for(auto o:eg[x])if(o.se!=fa){
		int w=o.fi,v=o.se;
		dfs(v,x);
		for(int i=w;;i=(i+1)|w){
			cadd(f[x][i],1ll*f[x][i]%mod*f[v][i]%mod);
			if(i==m-1)break;
		}
	}
	int s=0;
	for(int i=0;i<m;i++)
		if((bitc(Y)^bitc(i))&1)
			cadd(s,mod-f[x][i]);
		else
			cadd(s,f[x][i]);
	cadd(ans,s);
}
signed main(){
	readint(n);read(X);read(Y);
	Y=Y/X;
	{
		ll s=0;
		for(int i=1;i<=15;i++)
			if(Y%z[i]==0)
				s|=1<<(i-1);
		Y=s;
	}
	m=1<<bitc(Y);
	for(int i=1;i<=n;i++){
		read(val[i]);
		int ct=-1;
		for(int j=1;j<=15;j++){
			if((1<<(j-1))&Y){
				++ct;
				if(val[i]%z[j]==0)
					a[i]|=1<<ct;
			}
		}
	}
	for(int i=1,u,v;i<n;i++){
		readint(u);readint(v);
		eg[u].pb(mp(a[u]^a[v],v));
		eg[v].pb(mp(a[u]^a[v],u));
	}
	dfs(1,0);
	cout << ans << '\n';
	return 0;
}
