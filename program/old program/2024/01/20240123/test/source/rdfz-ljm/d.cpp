/*
  author: honglan0301
  Sexy_goodier _ xiaoqing
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <random>
#include <set>
#include <bitset>
#include <assert.h>
using namespace std;

//namespace Fread{const int SIZE=1<<20;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return*S++;}}using namespace Fread;namespace Fwrite{const int SIZE=1<<20;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}using namespace Fwrite;
//#define getchar Fread::getchar
//#define putchar Fwrite::putchar

namespace Fastio{struct Reader{template<typename T>Reader&operator>>(T&x){x=0;short f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();x*=f;return*this;}Reader&operator>>(double&x){x=0;double t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(long double&x){x=0;long double t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(__float128&x){x=0;__float128 t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(char&c){c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();return*this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(string&str){str.clear();char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{const int Setprecision=6;typedef int mxdouble;template<typename T>Writer&operator<<(T x){if(x==0){putchar('0');return*this;}if(x<0)putchar('-'),x=-x;static short sta[40];short top=0;while(x>0)sta[++top]=x%10,x/=10;while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(double)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(long double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(long double)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(__float128 x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(__float128)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}using namespace Fastio;
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl//;fflush(stdout)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define mod 998244353
mt19937 rnd(time(0));
mt19937_64 rndl(time(0));

int n,m,k,p,t,a[905],u[1805],v[1805],w[1805],vv[905][905];
vector <pair<int,int>> e[905];
vector <int> g[1805];

int ksm(int x,int k) {int na=1; for(int i=1;i<=k;i<<=1) {if(i&k) na=na*x%mod; x=x*x%mod;} return na;}
int c[2005][2005];
void init() {c[0][0]=1; for(int i=1;i<=2001;i++) {c[i][0]=1; for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;}}

void solve1()
{
	
}

int dfn[905],low[905],cntd,cnts,stk[905],top,flag[905];
void dfs1(int x)
{
	dfn[x]=low[x]=++cntd; stk[++top]=x;
	for(auto i:e[x])
	{
		if(!dfn[i.fi])
		{
			dfs1(i.fi); low[x]=min(low[x],low[i.fi]);
			if(low[i.fi]>=dfn[x])
			{
				cnts++; g[cnts].pb(x); g[x].pb(cnts); flag[x]=cnts;
				while(1) {int nr=stk[top--]; g[cnts].pb(nr); g[nr].pb(cnts); flag[nr]=cnts; if(nr==i.fi) break;}
			}
		}
		else low[x]=min(low[x],dfn[i.fi]);
	}
}
vector <pair<int,int>> hn[905];
int dp[1805][35][35][2],dph[1805][35][35][2][2],gg[35][35];
int kk,bb,ff;

void merge(int x,int y,int opx,int opy)
{
	memset(gg,0,sizeof(gg));
	for(int i=0;i<=k;i++)
	{
		for(int l=0;l<=p;l++)
		{
			if(!dp[x][i][l][opx]) continue;
			for(int j=0;i+j<=k;j++)
			{
				for(int r=0;r+l<=p;r++)
				{
					if(!dp[y][j][r][opy]) continue;
					gg[i+j][l+r]+=dp[x][i][l][opx]*dp[y][j][r][opy]%mod*c[i+j][i];
					gg[i+j][l+r]%=mod;
				}
			}
		}
	}
}
void mm(int opx)
{
	for(int i=0;i<=k;i++) for(int j=0;j<=p;j++) dp[ff][i][j][opx]=gg[i][j];
}
void ckm1(int x,int opx)
{
	for(int i=0;i<=k;i++) for(int j=0;j<=p;j++) dp[x][i][j][opx]=gg[i][j];
}
void ckmm1(int x,int opx)
{
	for(int i=0;i<=k;i++) for(int j=0;j<=p;j++) dp[x][i][j][opx]=dp[ff][i][j][opx];
}
void ckm2(int x,int opx)
{
	for(int i=0;i<=k;i++) for(int j=0;j<=p;j++) dp[x][i][j][opx]=(dp[x][i][j][opx]+gg[i][j])%mod;
}
void ckmm2(int x,int opx)
{
	for(int i=0;i<=k;i++) for(int j=0;j<=p;j++) dp[x][i][j][opx]=(dp[x][i][j][opx]+dp[ff][i][j][opx])%mod;
}
void prt(int x,int opx)
{
	for(int i=0;i<=k;i++) for(int j=0;j<=p;j++) cout<<x<<" "<<i<<" "<<j<<" "<<opx<<" "<<dp[x][i][j][opx]<<endl;
}
void prtg()
{
	for(int i=0;i<=k;i++) for(int j=0;j<=p;j++) cout<<i<<" "<<j<<" "<<gg[i][j]<<endl;
}
void dfs2(int x,int fat)
{
	if(x<=n)
	{
		for(int i=0;i<=k;i++) dp[x][i][0][0]=ksm(0,i),dp[x][i][1][0]=ksm(0,i),dp[x][i][0][1]=ksm(a[x],i),dp[x][i][1][1]=ksm((a[x]+t)%mod,i);
		for(auto i:g[x])
		{
			if(i==fat) continue;
			dfs2(i,x);
			merge(x,i,1,1); ckm1(x,1);
			merge(x,i,0,0); ckm1(x,0);
		}
	}
	else//
	{
		if(g[x].size()==2)
		{
			for(auto i:g[x]) {if(i==fat) continue; dfs2(i,x);}
			int to=fat,frm=0; for(auto i:g[x]) if(i!=to) frm=i;
			int nval=vv[frm][to];
			for(int i=0;i<=k;i++) dp[bb][i][0][1]=ksm(nval,i),dp[bb][i][1][1]=ksm((nval+t)%mod,i),dp[bb][i][0][0]=ksm(0,i),dp[bb][i][1][0]=ksm(0,i);
			merge(frm,bb,0,0); ckm1(x,1);
			merge(frm,bb,1,0); ckm1(x,0);
			merge(frm,bb,0,1); ckm2(x,0);
		}
		else
		{
			
		}
	}
	//prt(x,0); prt(x,1);
}
void solve2()
{
	cnts=n; dfs1(1);
	for(int i=1;i<=n;i++) for(auto j:e[i]) if(flag[i]==flag[j.fi]) hn[i].pb(mp(j.fi,j.se));
	kk=cnts+1; for(int i=0;i<=k;i++) dp[kk][i][0][0]=ksm(0,i);
	bb=cnts+2; ff=cnts+3;
	dfs2(1,1);
	cout<<(dp[1][k][p][0]+dp[1][k][p][1])*ksm(c[m+n][p],mod-2)%mod<<endl;
}

signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>m>>k>>p>>t; init();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i],vv[u[i]][v[i]]=vv[v[i]][u[i]]=w[i],e[u[i]].pb(mp(v[i],w[i])),e[v[i]].pb(mp(u[i],w[i]));
	if(m==n-2) solve1();
	else solve2();
}
