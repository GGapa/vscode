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
const int N=800+10,mod=1e9+7;
int n,m,q,fac[N],ifac[N],C[N][N],stx[N],sty[N],f[2][N],siz[2][N],dep[2][N];
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
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
inline void Prefix(int n){
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*i*fac[i-1]%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)
		ifac[i-1]=1ll*ifac[i]*i%mod;
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
				c[i+j]=add(c[i+j],1ll*a[i]*b[j]%mod);
		return c;
	}
}
using namespace PolyC;
vector<int>G[2][N];
int F[N][N],T[N][N],tmp[N][N];
Poly g;
inline void dfs(int x,int p){
	siz[p][x]=1,dep[p][x]=dep[p][f[p][x]]+1;
	for(int t:G[p][x])
		dfs(t,p),siz[p][x]+=siz[p][t];
}
inline bool chk(int x,int y,int p){
	return siz[p][x]-siz[p][y]==dep[p][y]-dep[p][x];
}
inline int calc(int x,int y){
	if(T[x][y]!=-1) return T[x][y];
	init(y);
	Poly G,R=g;
	G.resize(y),G[0]++;
	while(x){
		if(x&1) G=G*R;
		R=R*R;
		x>>=1;
	}
	return T[x][y]=G[y];
}
inline int solve(int x,int y){
	if(G[0][x].size()!=G[1][y].size()) return 0;
	if(!G[0][x].size()) return 1;
	if(F[x][y]!=-1) return F[x][y];
	int r=1;
	for(int i=0;i<G[0][x].size();i++){
		int sx=G[0][x][i],sy=G[1][y][i];
		int sp=stx[sx],sq=sty[sy];
		int l1=dep[0][sp]-dep[0][sx]+1,l2=dep[1][sq]-dep[1][sy]+1;
		int s=1ll*calc(l1,l2)*solve(sp,sq)%mod;
		if(!s) return F[x][y]=0;
		r=1ll*r*s%mod;
	}
	return F[x][y]=r;
}
inline void ins(int x){
	g[x]=add(g[x],1);
}
inline void del(int x){
	g[x]=add(g[x],mod-1);
}
int main(){
//	system("fc ex_b1.out ex_b1.ans");
//	system("fc ex_b2.out ex_b2.ans");
//	system("fc ex_b3.out ex_b3.ans");
//	system("fc ex_b4.out ex_b4.ans");
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		if(i>1) f[0][i]=read();
		G[0][f[0][i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		if(i>1) f[1][i]=read();
		G[1][f[1][i]].push_back(i);
	}
	dfs(1,0),dfs(1,1);
	for(int i=1;i<=n;i++){
		int t=i;
		stx[i]=i;
		while(t&&chk(f[0][t],i,0)) t=f[0][t],stx[t]=i;
	}
	for(int i=1;i<=m;i++){
		int t=i;
		sty[i]=i;
		while(t&&chk(f[1][t],i,1)) t=f[1][t],sty[t]=i;
	}
	f[1][0]=-1;
	Prefix(N-10);
	g.resize(max(n,m)+1);
	q=read();
	while(q--){
		int op=read(),x=read();
		if(op==1) ins(x);
		else del(x);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				F[i][j]=T[i][j]=-1;
		write(solve(0,0)),putc('\n');
		flush();
	}
	flush();
}
