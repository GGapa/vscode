#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace IO{//by cyffff
    int len=0;
    char ibuf[(1<<21)+1],*iS,*iT,out[(1<<26)+1];
    #if ONLINE_JUDGE
    #define gh() (iS==iT?iT=(iS=ibuf)+fread(ibuf,1,(1<<21)+1,stdin),(iS==iT?EOF:*iS++):*iS++)
    #else
    #define gh() getchar()
    #endif
    #define reg register
    inline int read(){
        reg char ch=gh();
        reg int x=0;
        reg char t=0;
        while(ch<'0'||ch>'9')   t|=ch=='-',ch=gh();
        while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=gh();
        return t?-x:x;
    }
    inline void putc(char ch){
        out[len++]=ch;
    }
    template<class T>
    inline void write(T x){
        if(x<0)putc('-'),x=-x;
        if(x>9)write(x/10);
        out[len++]=x%10+48;
    }
    inline void flush(){
        fwrite(out,1,len,stdout);
        len=0;
    }
    inline char getc(){
        char ch=gh();
        while(ch<'1'||ch>'3') ch=gh();
        return ch;
    }
}
using IO::read;
using IO::write;
using IO::flush;
using IO::getc;
using IO::putc;
const int N=2e3+10,mod=998244353;
int n,m,k,p,t,v[N],head[N],cnt;
bool vis[N];
struct Edge{
	int to,nxt,w;
}a[N<<1];
struct Edge2{
	int u,v,w;
}b[N];
inline void add(int u,int v,int w){
	a[++cnt]={v,head[u],w};
	head[u]=cnt;
}
inline int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int C[N][N];
inline void Prefix(int n){
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
}
namespace Sub1{
	inline void solve(){
		Prefix(n+m);
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int c=0,s=0;
			for(int j=0;j<n;j++)
				if(i>>j&1) vis[j+1]=1,c++,s=(s+v[j+1])%mod;
				else vis[j+1]=0;
			bool fl=0;
			for(int j=1;j<=m;j++){
				fl|=vis[b[j].u]&&vis[b[j].v];
				if(vis[b[j].u]||vis[b[j].v]) continue;
				c++,s=(s+b[j].w)%mod;
			}
			if(fl) continue;
			for(int l=0;l<=c&&l<=p;l++)
				ans=(ans+1ll*qpow((s+1ll*l*t)%mod,k)*C[c][l]%mod*C[n+m-c][p-l])%mod;
		}
		write(1ll*ans*qpow(C[n+m][p],mod-2)%mod);
		flush();
		exit(0);
	}
}
namespace Sub2{
	inline int add(int x,int y){
		return x+y>=mod?x+y-mod:x+y;
	}
	namespace PolyC{
		#define Poly vector<int>
		int lim;
		inline void init(int l){
			lim=l+1;
		}
		inline Poly operator+(const Poly &a,const Poly &b){
			Poly c=a;
			c.resize(max(a.size(),b.size()));
			for(int i=0;i<b.size();i++)
				c[i]=add(c[i],b[i]);
			return c;
		}
		inline Poly operator*(const Poly &a,const Poly &b){
			Poly c;
			c.resize(min(int(a.size()+b.size()-1),lim));
			for(int i=0;i<min(int(a.size()),lim);i++)
				for(int j=0;j<min(int(b.size()),lim-i);j++)
					c[i+j]=add(c[i+j],1ll*a[i]*b[j]%mod*C[i+j][i]%mod);
			return c;
		}
	}
	using namespace PolyC;
	inline Poly getP(int x){
		Poly F;
		for(int i=0,t=1;i<=k;i++,t=1ll*t*x%mod)
			F.push_back(t);
		return F;
	}
	Poly F[N][2];
	inline void dfs(int x,int fa){
		F[x][0].push_back(1),F[x][1]=getP(v[x]);
		for(int i=head[x];i;i=a[i].nxt){
			int t=a[i].to;
			if(t==fa) continue;
			dfs(t,x);
			F[x][0]=F[x][0]*(F[t][0]*getP(a[i].w)+F[t][1]);
			F[x][1]=F[x][1]*F[t][0];
		}
	}
	inline void solve(){
		Prefix(k);
		init(k);
		dfs(1,1);
		Poly T=F[1][0]+F[1][1];
		write(T[k]),flush();
		exit(0);
	}
	#undef Poly
}
namespace Sub3{
	inline int add(int x,int y){
		return x+y>=mod?x+y-mod:x+y;
	}
	struct node{
		int c,v;
		node(int a=0,int b=0){ c=a,v=b; }
		inline friend node operator+(const node &a,const node &b){
			return node(add(a.c,b.c),add(a.v,b.v));
		}
		inline friend node operator*(const node &a,const node &b){
			node c;
			c.c=1ll*a.c*b.c%mod;
			c.v=(1ll*a.v*b.c+1ll*a.c*b.v)%mod;
			return c;
		}
	};
	namespace PolyC{
		#define Poly vector<node>
		int lim=N;
		inline void init(int l){
			lim=l+1;
		}
		inline Poly operator+(const Poly &a,const Poly &b){
			Poly c=a;
			c.resize(max(a.size(),b.size()));
			for(int i=0;i<b.size();i++)
				c[i]=c[i]+b[i];
			return c;
		}
		inline Poly operator*(const Poly &a,const Poly &b){
			Poly c;
			c.resize(min(int(a.size()+b.size()-1),lim));
			for(int i=0;i<min(int(a.size()),lim);i++)
				for(int j=0;j<min(int(b.size()),lim-i);j++)
					c[i+j]=c[i+j]+a[i]*b[j];
			return c;
		}
	}
	using namespace PolyC;
	Poly F[N][2];
	inline void dfs(int x,int fa){
		F[x][0]={node(1,0)},F[x][1]={node(),node(1,v[x])};
		for(int i=head[x];i;i=a[i].nxt){
			int t=a[i].to;
			if(t==fa) continue;
			dfs(t,x);
			F[x][0]=F[x][0]*(F[t][0]*(Poly){node(),node(1,a[i].w)}+F[t][1]);
			F[x][1]=F[x][1]*F[t][0];
		}
	}
	inline void solve(){
		dfs(1,1);
		Poly T=F[1][0]+F[1][1];
		int sv=0,s=0;
		for(int i=0;i<T.size();i++){
			int c=T[i].c,v=T[i].v;
			sv=add(sv,v);
			s=(s+1ll*c*i)%mod;
		}
		write((sv+1ll*s*t%mod*qpow(n+m,mod-2))%mod),flush();
		exit(0);
	}
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read(),m=read(),k=read(),p=read(),t=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
		b[i]={u,v,w};
	}
	if(m==n-1&&!p) Sub2::solve();
	if(m==n-1&&p==1) Sub3::solve();
	Sub1::solve();
	flush();
}
/*
3 2 1 1 5
3 5 2 
1 2 4
2 3 3
*/
