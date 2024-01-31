#include<bits/stdc++.h>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
typedef long long ll;
constexpr int M=808,mod=1e9+7;
int n,m,q,fac[M],inv[M],last[M];
vector<pair<int,int>>vec;
vector<int>g1[M],g2[M],e1[M],e2[M];
int vis[M],ans[M],dp[M][M],sum1[M],sum2[M];
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
void dfs1(int x,int f,int ance){
	for (auto y:g1[x]){
		dfs1(y,x,g1[x].size()==1?ance:y);
		if (g1[x].size()>1) /*cout<<ance<<"-->"<<y<<endl,*/e1[ance].push_back(y);
	}
	sum1[ance]++;
}
void dfs2(int x,int f,int ance){
	for (auto y:g2[x]){
		dfs2(y,x,g2[x].size()==1?ance:y);
		if (g2[x].size()>1) /*cout<<ance<<"->"<<y<<endl,*/e2[ance].push_back(y);
	}
	sum2[ance]++;
}
void dfs3(int x,int y){
	if (e1[x].size()!=e2[y].size()){
		while (q--) puts("0");exit(0);
	}
	vec.push_back({sum1[x],sum2[y]});
	for (int i=0;i<e1[x].size();i++)
		dfs3(e1[x][i],e2[y][i]);
}
int rdc(int x){return x>=mod?x-mod:x;}
int qpow(int x,int n){
	int s=1; while (n){
		if (n&1) s=(ll)s*x%mod;
		x=(ll)x*x%mod;n>>=1; 
	} return s;
}
void init(int n){
	for (int i=fac[0]=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for (int i=n;i;i--) inv[i-1]=(ll)inv[i]*i%mod;
}
int c(int n,int m){return n<m||m<0?0:(ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int getans(){
	vector<int>s;
	for (int i=1;i<=m;i++) if (vis[i]) s.push_back(i);
	if (s.empty()) return 0;
	if (s.size()==1){
		for (auto tmp:vec)
			if (tmp.first*s[0]!=tmp.second)
				return 0;
		return 1;
	}
	if (s.size()==2){
		for (auto tmp:vec){
			int a=tmp.first,b=tmp.second;
			int v=s[0]*a-b;
			if (v%(s[0]-s[1])) return 0;
			int y=v/(s[0]-s[1]);
			if (y<0||y>a) return 0;
		}
		return 1;
	} 
	int mx1=0,mx2=0;int ans=1;
	for (int i=1;i<s.size();i++) s[i]-=s[0];
	for (auto tmp:vec){
		int tmp1=tmp.first,tmp2=tmp.second;
		if (tmp2<tmp1*s[0]) return 0;
		tmp2-=tmp1*s[0];
		for (int i=1;i<=tmp1;i++)
			for (int j=2;j<s.size();j++){
				int x=s[j];
				for (int j=1;j<=tmp2;j++)
					dp[i][j]=rdc(dp[i][j]+dp[i-1][j-x]);
			}
		int a=tmp.first,b=tmp.second;
		b-=a*s[0]; int now=0;
		for (int j=0;j<=a;j++)
			for (int i=0;i<=j&&i*s[1]<=b;i++)
				now=(now+(ll)dp[j-i][b-i*s[1]]*c(a,j)%mod*c(j,i))%mod;
		ans=(ll)ans*now%mod;
		for (int i=1;i<=tmp1;i++)
			for (int j=1;j<=tmp2;j++)
				dp[i][j]=0;
		if (!ans) return 0;
	}
	return ans; 
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();m=read();
	for (int i=2;i<=n;i++) g1[read()].push_back(i);
	for (int i=2;i<=m;i++) g2[read()].push_back(i);
	q=read();dfs1(1,0,1);dfs2(1,0,1);dfs3(1,1);
	if (n>m) {while (q--) puts("0");return 0;} init(m);
	dp[0][0]=1; for (int i=1;i<=q;i++){
		int op,x;op=read();x=read();
		vis[x]^=1; printf("%d\n",getans());
//		for (int i=1;i<=n;i++) last[i]=0;
//		for (int i=1;i<=n;i++)
//			for (int j=1;j<=m;j++) dp[i][j]=0;
	}
	return 0;
}
