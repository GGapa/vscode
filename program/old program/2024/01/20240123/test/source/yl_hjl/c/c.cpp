#include<bits/stdc++.h>
#define db double
#define int ll
#define ll long long
#define ull unsigned long long
#define pb emplace_back
#define MP make_pair
#define pii pair<int, int>
#define vec vector<int>
#define fi first
#define se second
#define ls k<<1
#define rs k<<1|1
#define CLK (double)clock()/(double)CLOCKS_PER_SEC
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(register int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int N=1e5+5,mod=998244353;
int n,m,t,f[N];pii p[N];
pii operator *(pii a,int b){return MP(a.fi*b%mod,a.se*b%mod);}
pii operator -(pii a,pii b){return MP((a.fi-b.fi)%mod,(a.se-b.se)%mod);}
pii operator -(pii a,int b){return MP(a.fi,(a.se-b)%mod);}
int Qpow(int b,int p){
    int res=1ll;
    while(p){
        if(p&1)(res*=b)%=mod;
        (b*=b)%=mod;p>>=1;
    }
    return res;
}
pii approx(int p,int q,int A){
    int x=q,y=p,a=1,b=0;
    while(x>A){
        swap(x,y),swap(a,b);
        a-=x/y*b;x%=y;
    }
    return MP(x,a);
}
void MAIN(){
    // pii res=approx(mod,499122176,1000);cout<<res.fi<<' '<<res.se<<"\n";
    n=read(),m=read(),t=read();int P=m*(n-1)%mod*m%mod,ivP=Qpow(P,mod-2),ivn=Qpow(n,mod-2);
    auto A=[&](int x){return (m-x)*(m-x)%mod*ivP%mod;};
    auto B=[&](int x){return x*((n-1)*m-(m-x))%mod*ivP%mod;};
    f[0]=0,f[1]=((A(0)+B(0))*f[0]%mod-ivn)*Qpow(A(0),mod-2)%mod;
    for(int i=1;i<m;i++)f[i+1]=((A(i)+B(i))*f[i]%mod-B(i)*f[i-1]%mod-ivn)*Qpow(A(i),mod-2)%mod;
    for(int i=0;i<=m;i++)f[i]=(f[i]+mod)%mod;
    // for(int i=0;i<m;i++)cout<<A(i)<<' '<<B(i)<<"\n";
    // for(int i=0;i<m;i++){
    //     int x=f[i],y=(A(i)*f[i+1]%mod+B(i)*f[i-1]%mod+(P-A(i)-B(i))*f[i]%mod)*Qpow(P,mod-2)%mod+1;
    //     cerr<<i<<' '<<x<<' '<<y<<"\n";
    // }
    // for(int i=0;i<=m;i++)cerr<<f[i]<<' ';cout<<"\n";
    while(t--){
        int ans=mod-f[m];
        for(int i=1;i<=n;i++)(ans+=f[read()])%=mod;
        cout<<(ans+mod)%mod<<"\n";
    }
}
signed main(){
   freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
    int T=1;while(T--)MAIN();
//  printf("\nTIME:%lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
