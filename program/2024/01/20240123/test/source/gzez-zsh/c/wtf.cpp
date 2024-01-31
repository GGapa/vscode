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

typedef array<int,2> info;
inline info operator + (const info &x,const info &y){return {add(x[0],y[0]),add(x[1],y[1])};}
inline info operator - (const info &x,const info &y){return {sub(x[0],y[0]),sub(x[1],y[1])};}
inline info operator * (const info &x,const int &y){return {1ll*x[0]*y%mod,1ll*x[1]*y%mod};}

int main()
{
	setfile();
	ios::sync_with_stdio(false); cin.tie(0);
	printf("hhh\n");

	int n,m,QQQ; cin>>n>>m>>QQQ;
	int invn=quick_pow(n,mod-2),invm=quick_pow(m,mod-2),invn1=quick_pow(n-1,mod-2);

	auto coef=[&](int a)
	{	
		return 1ll*a*invm%mod;
	};
	auto P=[&](int a)
	{
		return 1ll*a*invm%mod;
	};
	auto Q=[&](int a)
	{
		return 1ll*sub(m,a)*invm%mod*invn1%mod;
	};

	vector<info> f(m+1);
	f[0][0]=1;
	f[1][0]=1,f[1][1]=1ll*coef(0)*quick_pow(Q(0),mod-2)%mod;
	rep(i,1,m-1)
	{
		int p=P(i),q=Q(i);
		info x=(f[i]*(1ll*sub(2ll*p*q%mod,add(p,q)))+(f[i-1]*(1ll*p*sub(1,q)%mod)))*qmo(-1);
		inc(x[1],coef(i));
		assert(sub(1,p)&&q);
		f[i+1]=x*quick_pow(1ll*sub(1,p)*q%mod,mod-2);
	}
	info h=f[m]-f[m-1]; inc(h[1],coef(m));
	rep(i,0,m) printf("f %d : %d %d\n",i,f[i][0],f[i][1]);
	printf("h %d %d\n",h[0],h[1]);
	printf("sub %d v %d\n",sub(f[m][1],f[m-1][1]),qmo(-coef(m)));
	int X=1ll*h[1]*quick_pow(h[0],mod-2)%mod;

	vector<int> g(m+1);
	rep(i,0,m) g[i]=add(1ll*X*f[i][0]%mod,f[i][1]);

	rep(i,1,QQQ)
	{
		int ans=0;
		rep(j,1,n)
		{
			int x; cin>>x;
			inc(ans,g[x]);
		}
		ans=sub(g[m],ans);
		printf("%d\n",ans);
	}

	return 0;
}
