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
#define ll unsigned long long
#define ull unsigned long long
#define mod 1000000007
mt19937 rnd(time(0));
mt19937_64 rndl(time(0));

int n1,n2,fa[3][805],mxs[805],son[805][805],q,dp[805][805],pp[805][805],op,u,sz1[805],sz2[805];
vector <int> e[3][805],ns[805];
set <int> ss;

void dfs2(int x)
{
	if(e[2][x].size()>1||e[2][x].size()==0) 
	{
		mxs[x]=1,son[x][1]=x; for(auto i:e[2][x]) dfs2(i);
	}
	else
	{
		dfs2(e[2][x][0]); mxs[x]=mxs[e[2][x][0]]+1; son[x][1]=x;
		for(int i=2;i<=mxs[x];i++) son[x][i]=son[e[2][x][0]][i-1];
	}
}
void solve()
{
	for(int i=n1;i>=1;i--)
	{
		for(int j=n2;j>=1;j--)
		{
			if(sz2[j]<sz1[i]) continue;
			if(e[1][i].size()==e[2][j].size())
			{
				int na=1;
				for(int p=0;p<e[1][i].size();p++)
				{
					na=(ll)na*dp[e[1][i][p]][e[2][j][p]]%mod;
				}
				pp[i][j]=na;
			}
			ll naa=0;
			for(auto p:ns[min(mxs[j],sz2[j]-sz1[i]+1)]) naa+=pp[i][son[j][p]];//,cnttt++;
			dp[i][j]=naa%mod;
		}
	}
}

signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n1>>n2;
	for(int i=2;i<=n1;i++) cin>>fa[1][i],e[1][fa[1][i]].pb(i);
	for(int i=2;i<=n2;i++) cin>>fa[2][i],e[2][fa[2][i]].pb(i); 
	for(int i=n1;i>=1;i--) sz1[i]++,sz1[fa[1][i]]+=sz1[i];
	for(int i=n2;i>=1;i--) sz2[i]++,sz2[fa[2][i]]+=sz2[i];
	dfs2(1); cin>>q; int lq=q;
	while(q--)
	{
		cin>>op>>u; 
		if(op==1) ss.insert(u); else ss.erase(u);
		for(int i=1;i<=max(n1,n2);i++) ns[i].clear();
		for(int i=1;i<=max(n1,n2);i++) for(auto j:ss) if(j<=i) ns[i].pb(j);
		solve(); cout<<dp[1][1]<<endl;
	}
}
