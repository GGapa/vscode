#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e6+5,mod=998244353;
int n,q,n0,d0[N],d1[N],fac[N],ifac[N];char s[N];
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ans=(ll)ans*a%mod;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s+1,n=strlen(s+1);
	rep(i,1,n)q+=(s[i]=='?'),n0+=(s[i]=='+');
	ll ans=0;
	const int p0=qpow(2,q),p1=q?qpow(2,q-1):0;
	rep(i,1,n0){
		if(s[i]=='-')ans+=p0;
		if(s[i]=='?')ans+=p1;
	}
	rep(i,n0+1,n){
		if(s[i]=='-')++d0[i-n0];
		if(s[i]=='?')++d1[i-n0];
	}
	fac[0]=1;
	rep(i,1,q)fac[i]=(ll)fac[i-1]*i%mod;
	ifac[q]=qpow(fac[q],mod-2);
	per(i,q-1,0)ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
	const int q0=fac[q],q1=fac[q-1];
	ll s1=0,s2=0;
	int sd0=0,sd1=0;
	rep(i,1,q-1){
		sd0+=d0[i],sd1+=d1[i];
		if(sd0)s1+=(ll)sd0*ifac[i]%mod*ifac[q-i]%mod;
		if(sd1)s2+=(ll)sd1*ifac[i]%mod*ifac[q-1-i]%mod;
	}
	s1=s1%mod*q0+sd0+d0[q];
	return cout<<(ans+s1+s2%mod*q1)%mod<<'\n',0;
}