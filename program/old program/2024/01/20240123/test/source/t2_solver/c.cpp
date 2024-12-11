#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5,mod=998244353;
int f[maxn],g[maxn],a[maxn],n,m,t;
int qp(int a,int b){
	if(b==0)return 1;
	int T=qp(a,b>>1);T=T*T%mod;
	if(b&1)return T*a%mod;
	return T;
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>t;
	int C=(mod-(n-1)*m%mod*m%mod)*qp(n,mod-2)%mod;
	g[0]=C*qp(m*m%mod,mod-2)%mod;
	for(int i=1;i<m;i++)g[i]=qp((m-i)*(m-i),mod-2)*(C+(n-1)*m%mod*i%mod*g[i-1]%mod-i*(m-i)%mod*g[i-1]%mod+mod)%mod;
	f[0]=0;
	for(int i=1;i<=m;i++)f[i]=(f[i-1]+g[i-1])%mod;
	while(t--){
		int res=0;
		for(int i=1;i<=n;i++)cin>>a[i],(res+=f[a[i]])%=mod;
		res=(res-f[m]+mod)%mod;
		cout<<res<<"\n";
	}
	return 0;
}