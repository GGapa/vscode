#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=5010,mod=998244353;

int a[maxn],k[maxn],b[maxn],inv[maxn],res[maxn];

long long qpow(long long p,int q)
{
	long long r=1;
	while(q)
	{
		if(q&1) r=r*p%mod;
		p=p*p%mod;
		q>>=1;
	}
	return r;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m,T,i;
	cin>>n>>m>>T;
	int m2=1LL*m*m%mod;
	inv[1]=1;
	for(i=2;i<=m;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	while(T--)
	{
		for(i=1;i<=n;i++) cin>>a[i];
		if(any_of(a+1,a+n+1,[&m](int x){return x==m;}))
		{
			cout<<"0\n";
			continue;
		}
		k[1]=1;
		b[1]=0;
		for(i=1;i<m;i++)
		{
			int x=mod-(m-i+1LL)*(m-i+1)%mod,y=(m2+2LL*(mod-i)*(m-i))%mod;
			k[i+1]=(1LL*y*k[i]+1LL*x*k[i-1])%mod;
			b[i+1]=(1LL*y*b[i]+1LL*x*b[i-1])%mod;
			if(i==a[1]) b[i+1]=(b[i+1]+mod-m2)%mod;
			int iinv=1LL*inv[i+1]*inv[i+1]%mod;
			k[i+1]=1LL*k[i+1]*iinv%mod;
			b[i+1]=1LL*b[i+1]*iinv%mod;
		}
		int ans=0;
		res[1]=(mod-b[m])*qpow(k[m],mod-2)%mod;
		for(i=1;i<m;i++)
		{
			int x=mod-(m-i+1LL)*(m-i+1)%mod,y=(m2+2LL*(mod-i)*(m-i))%mod;
			res[i+1]=(1LL*y*res[i]+1LL*x*res[i-1])%mod;
			if(i==a[1]) res[i+1]=(res[i+1]+mod-m2)%mod;
			res[i+1]=1LL*res[i+1]*inv[i+1]%mod*inv[i+1]%mod;
			ans=(ans+res[i])%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
