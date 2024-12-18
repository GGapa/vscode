#include<bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;
const ll mod1=1000000007,mod2=1621836843;
ll n,p,k[N];

ll qkm(ll x,ll y,ll mod){
	ll ans=1;
	for(;y;y>>=1,x=(x*x)%mod)
	    if(y&1)ans=(ans*x)%mod;
	return ans;
}

int main(){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&p);
		for(ll i=1;i<=n;i++)scanf("%lld",&k[i]);
		if(p==1){
			printf("%lld\n",n&1);
			continue;
		}
		sort(k+1,k+n+1);
		ll sum1=0,sum2=0;
		for(ll i=n;i>=1;i--)
		    if(!sum1&&!sum2){
		    	sum1=qkm(p,k[i],mod1);
		    	sum2=qkm(p,k[i],mod2);
			}
			else{
				sum1=(sum1-qkm(p,k[i],mod1)+mod1)%mod1;
				sum2=(sum2-qkm(p,k[i],mod2)+mod2)%mod2;
			}
		printf("%lld\n",sum1);
	} 
	return 0;
}