#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define drep(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
inline void setfile()
{
	#ifndef pbtxdy
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	#endif
}

const int mod=998244353;
inline int qmo(int x){return x+((x>>31)&mod);}
inline int add(int x,int y){return qmo(x+y-mod);}
inline int sub(int x,int y){return qmo(x-y);}
inline void inc(int &x,int y){x=add(x,y);}
inline void dec(int &x,int y){x=sub(x,y);}
inline int quick_pow(int x,int k){int res=1; for (;k;k>>=1,x=1ll*x*x%mod) if (k&1) res=1ll*res*x%mod; return res;}

int main()
{
	setfile();
	ios::sync_with_stdio(false); cin.tie(0);

	int n,m,QQQ; cin>>n>>m>>QQQ;
	int invn=quick_pow(n,mod-2),invm=quick_pow(m,mod-2),invn1=quick_pow(n-1,mod-2);

	auto coef=[&](int a)
	{	
		return invn;
	};
	auto P=[&](int a)
	{
		return 1ll*a*invm%mod;
	};
	auto Q=[&](int a)
	{
		return 1ll*sub(m,a)*invm%mod*invn1%mod;
	};

	vector<int> f(m+1);
	f[0]=0,f[1]=1ll*coef(0)*quick_pow(Q(0),mod-2)%mod;
	rep(i,1,m-1)
	{
		int p=P(i),q=Q(i);
		int x=sub(coef(i),add(1ll*f[i]*sub(2ll*p*q%mod,add(p,q))%mod,1ll*f[i-1]*p%mod*sub(1,q)%mod));
		f[i+1]=1ll*x*quick_pow(1ll*sub(1,p)*q%mod,mod-2)%mod;
	}

	rep(i,1,QQQ)
	{
		int ans=0;
		rep(j,1,n)
		{
			int x; cin>>x;
			inc(ans,f[x]);
		}
		ans=sub(f[m],ans);
		printf("%d\n",ans);
	}

	return 0;
}
