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
const int N=1e5+10,mod=998244353;
int n,m,t,f[N],a[N];
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
int main(){
//	system("fc ex_c1.out ex_c1.ans");
//	system("fc ex_c2.out ex_c2.ans");
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(),m=read(),t=read();
	int pm=qpow(m,mod-2),pmn=qpow(1ll*m*(n-1)%mod,mod-2),pn=qpow(n,mod-2);
	f[1]=mod-1ll*(n-1)*pn%mod;
	for(int i=1;i<m;i++){
		int A=1ll*i*pm%mod,B=1ll*(m-i)*pmn%mod,C=add(1,mod-A),D=add(1,mod-B);
		int s=(((1+mod-(1ll*A*B+1ll*C*D)%mod)*f[i]-1ll*A*D%mod*f[i-1]%mod-pn)%mod+mod)%mod;
		f[i+1]=1ll*s*qpow(1ll*B*C%mod,mod-2)%mod;
	}
	while(t--){
		int s=mod-f[m];
		for(int i=1;i<=n;i++)
			s=add(s,f[read()]);
		write(s),putc('\n');
	}
	flush();
}
