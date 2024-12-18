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
#define between '\n'
template<typename T>struct is_char{static constexpr bool value=(std::is_same<T,char>::value||std::is_same<T,signed char>::value||std::is_same<T,unsigned char>::value);};template<typename T>struct is_integral_ex{static constexpr bool value=(std::is_integral<T>::value||std::is_same<T,__int128>::value)&&!is_char<T>::value;};template<typename T>struct is_floating_point_ex{static constexpr bool value=std::is_floating_point<T>::value||std::is_same<T,__float128>::value;};namespace Fastio{struct Reader{template<typename T>typename std::enable_if_t<std::is_class<T>::value,Reader&>operator>>(T&x){for(auto &y:x)*this>>y;return *this;}template<typename T>typename std::enable_if_t<is_integral_ex<T>::value,Reader&>operator>>(T&x){char c=getchar();short f=1;while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}x*=f;return *this;}template<typename T>typename std::enable_if_t<is_floating_point_ex<T>::value,Reader&>operator>>(T&x){char c=getchar();short f=1,s=0;x=0;T t=0;while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}template<typename T>typename std::enable_if_t<is_char<T>::value,Reader&>operator>>(T&c){c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();return *this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(std::string&str){str.clear();char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{typedef __int128 mxdouble;template<typename T>typename std::enable_if_t<std::is_class<T>::value,Writer&>operator<<(T x){for(auto &y:x)*this<<y<<between;*this<<'\n';return *this;}template<typename T>typename std::enable_if_t<is_integral_ex<T>::value,Writer&>operator<<(T x){if(x==0)return putchar('0'),*this;if(x<0)putchar('-'),x=-x;static int sta[45];int top=0;while(x)sta[++top]=x%10,x/=10;while(top)putchar(sta[top]+'0'),--top;return*this;}template<typename T>typename std::enable_if_t<is_floating_point_ex<T>::value,Writer&>operator<<(T x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(T)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x+0.5;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}template<typename T>typename std::enable_if_t<is_char<T>::value,Writer&>operator<<(T c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return *this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(std::string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl

#define int long long
const int mod=998244353;
int qp(int a,int b){
	if(b<0){
		return qp(qp(a,mod-2),-b);
	}
	int ans=1;
	while(b){
		if(b&1) (ans*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return ans;
}
int g[1000001],f[1000001];
main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<m;i++){
		g[i]=((i*n%mod*m%mod+i*i%mod+mod-2*m*i%mod)*g[i-1]%mod+i*n%mod*m%mod+mod-i*m%mod)*qp((m-i)*(m-i)%mod,mod-2)%mod;
	}
	for(int i=1;i<=m;i++){
		f[i]=(f[i-1]+g[i-1])%mod;
	}
	int t; cin>>t;
	while(t--){
		int ans=f[m];
		for(int i=1;i<=n;i++){
			int a; cin>>a;
			(ans+=mod-f[a])%=mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

