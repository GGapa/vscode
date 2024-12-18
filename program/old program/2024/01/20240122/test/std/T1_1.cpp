#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int M=2e6+5,mod=998244353;string s;
int n,m,ans,cnt,sum,a[M],f[M],g[M],fac[M],inv[M];
int qpow(int x,int n){int s=1;while (n){if (n&1) s=(ll)s*x%mod;x=(ll)x*x%mod;n>>=1;} return s;}
int c(int n,int m){return n<m||m<0?0:(ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
void init(int n){
	for (int i=fac[0]=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for (int i=n;i;i--) inv[i-1]=(ll)inv[i]*i%mod;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;n=s.length();s=" "+s;
	for (int i=1;i<=n;i++) f[i]=f[i-1]+(s[i]!='+'),g[i]=g[i-1]+(s[i]=='?');
	init(g[n]); for (int x=0;x<=g[n];x++)
		ans=(ans+(ll)c(g[n],x)*f[x+n-f[n]]-(ll)c(g[n]-1,x-1)*g[x+n-f[n]])%mod;
	if (ans<0) ans+=mod;
	printf("%d\n",ans);	
	return 0;
} 