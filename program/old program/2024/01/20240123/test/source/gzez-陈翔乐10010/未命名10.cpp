#include<bits/stdc++.h>
#define Yukinoshita namespace
#define Yukino std;
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
const int mod=998244353;
const int mxn=5000; 
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
inline void getmod(int &x)
{
	x-=(x>=mod)*mod;
}
#define x first
#define y second
pair<int,int> e[mxn]; 
int a[mxn],b[mxn];
int btc[1000000];
int C[60][60];
int K;
vector<int> t[mxn];
struct poly
{
	int a[60];
	poly()
	{
		memset(a,0,sizeof(a));
	}
	friend poly operator *(const poly &x,const poly &y)
	{
		poly res;
		int i,j;
		for(i=0;i<=K;i++)
			for(j=0;i+j<=K;j++)
				res.a[i+j]=(res.a[i+j]+1ll*x.a[i]*y.a[j])%mod;
		return res;
	}
	friend poly operator +(const poly &x,const poly &y)
	{
		poly res;
		int i,j;
		for(i=0;i<=K;i++)
			getmod(res.a[i]=x.a[i]+y.a[i]);
		return res;
	}
	void add(int t)
	{
		int i,j,mul[60],b[60]={0};
		mul[0]=1;
		for(i=1;i<=K;i++)
			mul[i]=1ll*mul[i-1]*t%mod;
		for(i=0;i<=K;i++)
			for(j=0;j<=i;j++)
				b[j]=(b[j]+1ll*a[i]*mul[i-j]%mod*C[i][j])%mod;
		memcpy(a,b,sizeof(a)); 
	}
	int get(int t)
	{
		int mul=0,i;
		for(i=K;~i;i--)
			mul=(1ll*mul*t+a[i])%mod;
		return mul;
	}
	void print()
	{
		for(int i=0;i<=K;i++)
			cout<<((abs(a[i]-mod)<abs(a[i]))?a[i]-mod:a[i])<<' ';
		cout<<endl;
	}
}dp[mxn][2];
void dfs(int d,int fa)
{
//	dp[d][1].a[K]=1;
	dp[d][0].a[K]=1;
	for(int i=0;i<=K;i++)
		dp[d][1].a[i]=1ll*C[K][i]*a[d]%mod;
//	dp[d][1].add(a[d]);
//	cout<<d<<':'<<endl;
//	dp[d][0].print();
//	dp[d][1].print();
	for(auto x:t[d])
		if(x!=fa)
			dfs(x,d),dp[d][1]=dp[d][1]*dp[x][0],
			dp[d][0]=dp[d][0]*(dp[x][0]+dp[x][1]);
	cout<<d<<':'<<endl;
	dp[d][0].print();
	dp[d][1].print();
}
int main()
{
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	int n=read(),m=read(),K=read(),p=read(),t=read(),i,j,k,l,as=0,w,ans=0,sum;
	::K=K;
	C[0][0]=1;
	for(i=1;i<60;i++)
		for(j=C[i][0]=1;j<=i;j++)
			getmod(C[i][j]=C[i-1][j]+C[i-1][j-1]);
	for(i=1;i<=n;i++)
		a[i]=read();
	for(i=1;i<=m;i++)
		e[i].x=read(),e[i].y=read(),w=read(),getmod(as+=w),a[e[i].x]=(a[e[i].x]-w+mod)%mod,a[e[i].y]=(a[e[i].y]-w+mod)%mod,::t[e[i].x].push_back(e[i].y),::t[e[i].y].push_back(e[i].x);
	if(0)
	//if(n<=6&&m<=12&&p<=6)
	{
		int cnt=0;
		for(i=1;i<(1<<max(n,m));i++)
			btc[i]=btc[i/2]+i%2;
		for(i=0;i<(1<<m);i++)
			if(btc[i]<=p)
			{
				for(j=0;j<(1<<n);j++)
					if(btc[i]+btc[j]==p)
					{
						cnt++;
						for(k=0;k<n;k++)
							b[k]=a[k+1];
						for(k=0;k<m;k++)
							if(i>>k&1)
								b[e[k+1].x-1]=(b[e[k+1].x-1]-t+mod)%mod,
								b[e[k+1].y-1]=(b[e[k+1].y-1]-t+mod)%mod;
						for(k=0;k<n;k++)
							if(j>>k&1)
								b[k]=(b[k]+t)%mod;
						for(k=0;k<(1<<n);k++)
						{
							for(l=0;l<m;l++)	
								if((k>>e[l+1].x-1&1)&&(k>>e[l+1].y-1&1))
									goto bre;
							sum=(as+1ll*t*btc[i])%mod;
							for(l=0;l<n;l++)
								if(k>>l&1)
									getmod(sum+=b[l]);
//							cout<<i<<' '<<j<<' '<<k<<':'<<as<<' '<<sum<<endl;
							getmod(ans+=qpow(sum,K));
							bre:;
						}
					}
			}
		cout<<1ll*ans*qpow(cnt,mod-2)%mod;
		return 0;
	}
	if(p==0&&m==n-1)
	{
		for(i=1;i<=n;i++)
			cout<<((abs(a[i]-mod)<abs(a[i]))?a[i]-mod:a[i])<<' ';
		cout<<endl;
		dfs(1,0);
		cout<<(dp[1][0].get(as)+dp[1][1].get(as))%mod;
		return 0;
	}
}
/*
12 13 7 4 11
123 234 345 456 567 678 789 987 876 765 654 543
1 2 111
2 3 434
3 4 767
4 1 556
4 7 999
3 5 238
5 12 648
5 6 993
6 10 943
10 9 234
8 9 555
8 6 666
11 8 233

3 2 1 0 1
1 1 1
1 2 1
2 3 2

*/
