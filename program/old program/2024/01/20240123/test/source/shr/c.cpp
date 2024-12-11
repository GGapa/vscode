#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;
int n,m,q,f[N];
int inv(int x){
	int res=1,y=mod-2;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod;
	return res;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>q;
	int c=(n-1ll)*m*m%mod*inv(n)%mod;
	for(int i=1;i<m;i++)
		f[i+1]=(c+(1ll*m*m+(n-4ll+mod)*m%mod*i+2ll*i*i)%mod*f[i]+(mod-((n-2ll+mod)*m%mod+i)*i%mod)*f[i-1])%mod*
		inv(1ll*(m-i)*(m-i)%mod)%mod;
	while(q--){
		int ans=f[m];
		for(int i=0,x;i<n;i++) cin>>x,(ans+=mod-f[x])%=mod;
		cout<<ans<<"\n";
	}
	return 0;
}
