#include<bits/stdc++.h>
using namespace std;
using LL=long long;
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int res,f=1;
	char c;
	while((c=gc())<'0'||c>'9')if(c=='-')f=-1;
	res=c-'0';
	while((c=gc())>='0'&&c<='9')res=res*10+c-'0';
	return res*f;
}
const int N=5e3+5,M=1e5+5,mod=998244353;
LL POW(LL a,LL b){
	LL res=1;a%=mod;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
LL divi(LL a,LL b){return a%mod*POW(b,mod-2)%mod;}
int n,m,T,a[N];
namespace sub1{
	LL dp[M],A[M],B[M],C[M],x[M],y[M];
	void solve(){
		while(T--){
			for(int i=1;i<=n;i++)a[i]=read();
			for(int i=1;i<m;i++){
				LL t1=divi(i,m),t2=(mod+1-t1)%mod,t3=divi(m-i,(n-1)*m),t4=(mod+1-t3)%mod;
				LL p1=t1*t4%mod,p2=(t1*t3+t2*t4)%mod,p3=t2*t3%mod;
				A[i]=divi(p1,mod+1-p2),B[i]=divi(p3,mod+1-p2),C[i]=divi(1,mod+1-p2);
				x[i]=divi(B[i],mod+1-A[i]*x[i-1]%mod),y[i]=divi((C[i]+A[i]*y[i-1])%mod,mod+1-A[i]*x[i-1]%mod);
			}
			for(int i=m-1;i>=1;i--)dp[i]=(x[i]*dp[i+1]+y[i])%mod;
			printf("%lld\n",dp[a[1]]);
		}
	}
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(),m=read(),T=read();
	if(n==2)return sub1::solve(),0;
	return 0;
}