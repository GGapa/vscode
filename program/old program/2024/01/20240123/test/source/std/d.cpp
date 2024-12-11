#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include"dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
namespace Fread{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}}namespace Fwrite{const int SIZE=1<<16;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}
#define getchar Fread::getchar
#define putchar Fwrite::putchar
#define Setprecision 10
#define between ' '
template<typename T>struct is_char{static constexpr bool value=(std::is_same<T,char>::value||std::is_same<T,signed char>::value||std::is_same<T,unsigned char>::value);};template<typename T>struct is_integral_ex{static constexpr bool value=(std::is_integral<T>::value||std::is_same<T,__int128>::value)&&!is_char<T>::value;};template<typename T>struct is_floating_point_ex{static constexpr bool value=std::is_floating_point<T>::value||std::is_same<T,__float128>::value;};namespace Fastio{struct Reader{template<typename T>typename std::enable_if_t<std::is_class<T>::value,Reader&>operator>>(T&x){for(auto &y:x)*this>>y;return *this;}template<typename T>typename std::enable_if_t<is_integral_ex<T>::value,Reader&>operator>>(T&x){char c=getchar();short f=1;while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}x*=f;return *this;}template<typename T>typename std::enable_if_t<is_floating_point_ex<T>::value,Reader&>operator>>(T&x){char c=getchar();short f=1,s=0;x=0;T t=0;while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}template<typename T>typename std::enable_if_t<is_char<T>::value,Reader&>operator>>(T&c){c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();return *this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(std::string&str){str.clear();char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{typedef __int128 mxdouble;template<typename T>typename std::enable_if_t<std::is_class<T>::value,Writer&>operator<<(T x){for(auto &y:x)*this<<y<<between;*this<<'\n';return *this;}template<typename T>typename std::enable_if_t<is_integral_ex<T>::value,Writer&>operator<<(T x){if(x==0)return putchar('0'),*this;if(x<0)putchar('-'),x=-x;static int sta[45];int top=0;while(x)sta[++top]=x%10,x/=10;while(top)putchar(sta[top]+'0'),--top;return*this;}template<typename T>typename std::enable_if_t<is_floating_point_ex<T>::value,Writer&>operator<<(T x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(T)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}template<typename T>typename std::enable_if_t<is_char<T>::value,Writer&>operator<<(T c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return *this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(std::string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl
#define int long long
const int mod=998244353;
int qp(int a,int b){
	int ans=1;
	while(b){
		if(b&1) (ans*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return ans;
} 
vector<int> vc[2005],tr[2005];
int dfn[2005],low[2005],s[2005],top,cnt,bcc,n,k,p,t;
int ed[2005][2005],pt[2005],siz[2005],tag[2005],C[3005][3005];
void dfs0(int now,int fa){
	low[now]=dfn[now]=++cnt;
	s[++top]=now;
	for(auto v:vc[now]){
		if(!dfn[v]){
			dfs0(v,now);
			low[now]=min(low[now],low[v]);
			if(low[v]>=dfn[now]){
				bcc++;
				int ts=0;
				while(s[top+1]!=v) tr[n+bcc].push_back(s[top]),tr[s[top]].push_back(n+bcc),top--,ts++;
				tr[n+bcc].push_back(now),tr[now].push_back(n+bcc),ts++;
				if(ts==2){
					tag[bcc+n]=1;
				}
			}
		}
		else if(v!=fa) low[now]=min(low[now],dfn[v]);
	}
} 
struct arr{
	int a[32][32];
}ept;
arr dp[2005][2][2];
arr putv(arr x,int val){
	for(int i=k;i>=0;i--){
		for(int j=p;j>=0;j--){
			int pw=1;
			for(int l=1;i+l<=k;l++){
				(pw*=val)%=mod;
				(x.a[i+l][j]+=x.a[i][j]*pw%mod*C[i+l][i])%=mod;
			}
		}
	}
	for(int i=k;i>=0;i--){
		for(int j=p-1;j>=0;j--){
			int pw=1;
			for(int l=1;i+l<=k;l++){
				(pw*=t)%=mod;
				(x.a[i+l][j+1]+=x.a[i][j]*pw%mod*C[i+l][i])%=mod;
			}
		}
	}
	return x;
}
arr merge(arr x,arr y,int tp1,int tp2){
	tp1=min(tp1,p),tp2=min(tp2,p);
	arr z=ept;
	for(int i=0;i<=k;i++){
		for(int j=0;i+j<=k;j++){
			for(int l1=0;l1<=tp1;l1++){
				for(int l2=0;l2<=tp2&&l1+l2<=p;l2++){
					(z.a[i+j][l1+l2]+=x.a[i][l1]*y.a[j][l2]%mod*C[i+j][j])%=mod;
				}
			}
		}
	}
	return z;
}
arr add(arr x,arr y){
	for(int i=0;i<=k;i++){
		for(int j=0;j<=p;j++){
			(x.a[i][j]+=y.a[i][j])%=mod;
		}
	}
	return x;
}
void dfs(int now,int fa){
	if(now<=n){
		siz[now]=1;
		dp[now][0][0].a[0][0]=1;
		dp[now][0][1].a[0][0]=1;
		dp[now][0][1]=putv(dp[now][0][1],pt[now]);
		for(auto v:tr[now]){
			if(v==fa) continue;
			dfs(v,now);
			dp[now][0][0]=merge(dp[now][0][0],dp[v][0][0],siz[now],siz[v]);
			dp[now][0][1]=merge(dp[now][0][1],dp[v][0][1],siz[now],siz[v]);
			siz[now]+=siz[v];
		}
	}
	else{
		vector<int> ord;
		bool ok=0;
		for(auto v:tr[now]){
			if(v==fa){
				ok=1; continue;
			}
			if(ok) ord.push_back(v);
		}
		for(auto v:tr[now]){
			if(v==fa) break;
			ord.push_back(v);
		}
		for(auto v:ord){
			dfs(v,now);
		}
		siz[now]=siz[ord[0]];
		dp[now][0][0]=dp[ord[0]][0][0];
		dp[now][1][1]=dp[ord[0]][0][1];
		for(int i=1;i<ord.size();i++){
			arr tmp[2][2];
			tmp[0][0]=add(merge(dp[now][0][0],putv(dp[ord[i]][0][0],ed[ord[i-1]][ord[i]]),siz[now],siz[ord[i]]+1),merge(dp[now][0][1],dp[ord[i]][0][0],p,p));
			tmp[0][1]=merge(dp[now][0][0],dp[ord[i]][0][1],siz[now],siz[ord[i]]);
			tmp[1][0]=add(merge(dp[now][1][0],putv(dp[ord[i]][0][0],ed[ord[i-1]][ord[i]]),siz[now],siz[ord[i]]+1),merge(dp[now][1][1],dp[ord[i]][0][0],p,p));
			tmp[1][1]=merge(dp[now][1][0],dp[ord[i]][0][1],siz[now],siz[ord[i]]);
			siz[now]+=siz[ord[i]]+1;
			dp[now][0][0]=tmp[0][0];
			dp[now][0][1]=tmp[0][1];
			dp[now][1][0]=tmp[1][0];
			dp[now][1][1]=tmp[1][1];
		}
		arr tmp[2];
		if(tag[now]){
			tmp[0]=add(putv(dp[now][0][0],ed[fa][ord[0]]),dp[now][1][1]);
			tmp[1]=dp[now][0][0];
			siz[now]++;
		}
		else{
			tmp[1]=dp[now][0][0];
			dp[now][0][0]=putv(dp[now][0][0],ed[fa][ord[0]]);
			dp[now][0][1]=putv(dp[now][0][1],ed[fa][ord[0]]);
			dp[now][0][0]=putv(dp[now][0][0],ed[fa][ord[ord.size()-1]]);
			dp[now][1][0]=putv(dp[now][1][0],ed[fa][ord[ord.size()-1]]);
			tmp[0]=add(add(dp[now][0][0],dp[now][0][1]),add(dp[now][1][0],dp[now][1][1]));
			siz[now]+=2;
		}
		dp[now][0][0]=tmp[0];
		dp[now][0][1]=tmp[1];
	}
}
main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	for(int i=0;i<=3000;i++) C[i][0]=1;
	for(int i=1;i<=3000;i++) for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	int m; cin>>n>>m>>k>>p>>t;
	for(int i=1;i<=n;i++) cin>>pt[i];
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		vc[u].push_back(v);
		vc[v].push_back(u);
		ed[u][v]=ed[v][u]=w;
	}
	dfs0(1,0);
	dfs(1,0);
	int ans=0;
	arr res=add(dp[1][0][0],dp[1][0][1]);
	for(int l=0;l<=p;l++){
		(ans+=res.a[k][l]*C[n+m-l][p-l])%=mod;
	}
	cout<<ans*qp(C[n+m][p],mod-2)%mod;
	return 0;
}
