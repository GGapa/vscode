#include<bits/stdc++.h>
#define Yukinoshita namespace
#define Yukino std;
#define int long long
using Yukinoshita Yukino;
using ll=long long;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
const int mxn=1e5+5;
const int mod=998244353;
int qpow(int a,int p)
{
	int mul=1;
	for(;p;p>>=1)
	{
		if(p&1) mul=1ll*mul*a%mod;
		a=1ll*a*a%mod;
	}
	return mul;
}
int f[mxn];
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n=read(),m=read(),t=read(),i,j,mv=qpow(m,mod-2),nmv=qpow((n-1ll)*m%mod,mod-2);
	for(i=1;i<=m;i++)
	{
		int f1=1ll*i*mv%mod,f2=(1-f1+mod)%mod;
		int g1=1ll*(m-i)*nmv%mod,g2=(1-g1+mod)%mod;
		int s=((f[i]-f1-f[i]*(f1*g1%mod+f2*g2%mod)%mod-f[i-1]*(f1*g2%mod)%mod)%mod+mod)%mod;
		f[i+1]=1ll*s*qpow(1ll*f2*g1%mod,mod-2)%mod;
	}
	while(t--)
	{
		int s=0;
		for(i=0;i<n;i++)
			s=(s+f[read()])%mod;
		printf("%lld\n",((s-f[m]-f[0]*(n-1ll))%mod+mod)%mod);
	}
}
