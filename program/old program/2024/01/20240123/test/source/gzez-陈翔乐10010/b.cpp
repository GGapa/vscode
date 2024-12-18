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
const int mxn=805;
const int mod=1e9+7;
inline void getmod(int &x)
{
	x-=(x>=mod)*mod;
}
vector<int> t1[mxn],t2[mxn],d0[mxn],dl[mxn];
int dp[mxn][mxn];
set<int> st;
int n1,n2;
struct poly
{
	int a[mxn];
	int l;
	poly(int len)
	{
		l=len;
		memset(a,0,sizeof(a));
	}
	friend poly operator *(const poly &x,const poly &y)
	{
		int i,j;
		poly res(x.l);
		for(i=0;i<=x.l;i++)
			for(j=0;i+j<=x.l;j++)
				res.a[i+j]=(res.a[i+j]+1ll*x.a[i]*y.a[j])%mod;
		return res;
	}
};
int solve(int x,int y)
{
	poly a(y),mul(y);
	mul.a[0]=1;
	for(auto i:st)
		a.a[i]=1;
	for(;x;x>>=1)
	{
		if(x&1) mul=mul*a;
		a=a*a;
	}
	return mul.a[y];
}
void dfs(int x,int y)
{
	if(~dp[x][y]) return;
//	if(t1[x].empty()&&t2[x].empty())
//	{
//		dp[x][y]=1;
//		return;
//	}
	dp[x][y]=0;
	int p=d0[x].back(),q=dl[y].back();
	if(t1[p].size()==t2[q].size())
	{
		int mul=solve(d0[x].size(),dl[y].size());
		for(int j=0;j<t1[p].size();j++)
			dfs(t1[p][j],t2[q][j]),mul=1ll*mul*dp[t1[p][j]][t2[q][j]]%mod;
		dp[x][y]=mul;
	}
//	for(auto i:v)
//	{
//		if(i>dl[y].size()) break;
//		if(t2[dl[y][i-1]].size()==t1[x].size())
//		{
//			int mul=1;
//			for(int j=0;j<t1[x].size();j++)
//				dfs(t1[x][j],t2[dl[y][i-1]][j]),mul=1ll*mul*dp[t1[x][j]][t2[dl[y][i-1]][j]]%mod;
////			cout<<x<<' '<<y<<':'<<x<<' '<<dl[y][i-1]<<endl;
//			getmod(dp[x][y]+=mul);
//		}
//	}
//	cout<<x<<' '<<y<<':'<<dp[x][y]<<endl;
}	
int c[mxn*2][mxn*2]; 
const int B=10;
int main()
{
//	system("fc out ex_b3.ans");
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n1=read(),n2=read();
	int i,j,q;
	c[0][0]=1;
	for(i=1;i<=n1+n2;i++)
		for(j=c[i][0]=1;j<=i;j++)
			getmod(c[i][j]=c[i-1][j]+c[i-1][j-1]);
	for(i=2;i<=n1;i++)
		t1[read()].push_back(i);
	for(i=2;i<=n2;i++)
		t2[read()].push_back(i);
	for(i=1;i<=n1;i++)
	{
		for(j=i;;)
		{
			d0[i].push_back(j);	
			if(t1[j].size()>1) break;
			if(t1[j].empty()) break;
			j=t1[j][0];
		}
	}
	for(i=1;i<=n2;i++)
	{
		for(j=i;;)
		{
			dl[i].push_back(j);	
			if(t2[j].size()>1) break;
			if(t2[j].empty()) break;
			j=t2[j][0];
		}
	}
	q=read();
	while(q--)
	{
		i=read(),j=read();
		if(i==1) st.insert(j);
		else st.erase(j);
		memset(dp,-1,sizeof(dp));
		dfs(1,1),printf("%d\n",dp[1][1]);
	}	
}
/*
5 8
1 1 3 3
1 1 2 3 3 5 6
5
1 1
1 2
1 3
2 1
2 2

5 5
1 2 3 3
1 2 3 3

*/
