#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+605,mod=998244353;

int f[N],n,m,t;

int ksm(int a,int b)
{
	int ans=1;
	while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;}
	return ans;
}

main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>m>>t;
	int inv=ksm(m,mod-2);
	for(int i=1;i<m;i++)f[i+1]=(f[i]*(m+(n-4)*i%mod+2*i*i%mod*inv%mod)%mod-f[i-1]*((n-2)*m%mod*i%mod+i*i%mod)%mod*inv%mod-i*(n-1)%mod+mod*2)%mod*ksm((m-i)*(m-i)%mod,mod-2)%mod*m%mod;
	while(t--)
	{
		int ans=mod-f[m];
		for(int i=1,x;i<=n;i++)cin>>x,ans+=f[x];
		cout<<ans%mod<<'\n';
	}
}
