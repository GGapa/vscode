#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=1e5+5,mod=998244353;
int n,m,t,a[N],f[N],g[N],inv[N];
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ans=(ll)ans*a%mod;
	return ans;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>m>>t;
	inv[0]=inv[1]=1;
	rep(i,2,m)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
//	g[0]=qpow((ll)(n-2)*m%mod,mod-2);
//	g[0]=(ll)(n-1)*m%mod*qpow(((ll)(n-2)*m+1)%mod,mod-2)%mod;
	g[0]=0;
	rep(i,1,m){
		int val=mod-(((ll)(n-1)*m%mod-(ll)g[i-1]*((ll)(n-2)*m%mod+i))%mod+mod)%mod;
		g[i]=(ll)inv[m-i]*inv[m-i]%mod*i%mod*val%mod;
	}
	f[0]=0;
	rep(i,1,m)f[i]=(f[i-1]+g[i-1])%mod;
	while(t--){
		ll ans=0;
		rep(i,1,n)cin>>a[i],ans+=f[a[i]];
		cout<<(ans%mod+mod-f[m])%mod<<'\n';
	}
	return 0;
}
