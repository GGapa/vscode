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
set<int> v;
int dp1[mxn][mxn],dp2[mxn][mxn];//用了i个数，和为j
void dfs(int x,int y)
{
	if(~dp[x][y]) return;
	dp[x][y]=0;
	int p=d0[x].back(),q=dl[y].back();
	if(t1[p].size()==t2[q].size())
	{
		int mul=dp2[d0[x].size()][dl[y].size()];
		if(!mul) return;
		for(int j=0;j<t1[p].size();j++)
		{
			dfs(t1[p][j],t2[q][j]);
			if(!dp[t1[p][j]][t2[q][j]]) return;
			mul=1ll*mul*dp[t1[p][j]][t2[q][j]]%mod;
		}
			
		dp[x][y]=mul;
	}
}	
int c[mxn*2][mxn*2]; 
int n1,n2;
const int B=7;
set<int> st;
void ins(int x)
{
	if(x<=B)
	{
		st.insert(x);
		return;
	}
	int i,j,k;
	for(j=n1;~j;j--)
		for(k=n2;~k;k--)
			if(dp1[j][k])
				for(i=1;i*x+k<=n2&&i+j<=n1;i++)
					dp1[j+i][k+i*x]=(dp1[j+i][k+i*x]+1ll*dp1[j][k]*c[i+j][i])%mod;
}
void del(int x)
{
	if(x<=B)
	{
		st.erase(x);
		return;
	}
	int i,j,k;
	for(j=0;j<=n1;j++)
		for(k=0;k<=n2;k++)
			for(i=1;i*x<=k&&i<=j;i++)
				dp1[j][k]=(dp1[j][k]-1ll*dp1[j-i][k-i*x]*c[j][i]%mod+mod)%mod;
}
int main()
{
	dp1[0][0]=1;
//	system("fc out ex_b3.ans");
//	freopen("ex_b3.in","r",stdin);
	freopen("out","w",stdout);
	n1=800,n2=800;
	int i,j,q;
	c[0][0]=1;
	for(i=1;i<=n1+n2;i++)
		for(j=c[i][0]=1;j<=i;j++)
			getmod(c[i][j]=c[i-1][j]+c[i-1][j-1]);
	for(i=2;i<=n1;i++)
		t1[i-1].push_back(i);
	for(i=2;i<=n2;i++)
		t2[i-1].push_back(i);
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
	q=100;
	int cnt=0;
	while(q--)
	{
		i=1,j=++cnt;
		if(i==1) ins(j);
		else del(j);
		memset(dp,-1,sizeof(dp));
		memcpy(dp2,dp1,sizeof(dp1));
		for(i=0;i+1<=n1;i++)
			for(j=0;j<=n2;j++)
				for(auto u:st)
					if(j+u<=n2)
						getmod(dp2[i+1][j+u]+=dp2[i][j]);
					else break;
		cout<<dp1[n1][n2]<<endl;
		//dfs(1,1),printf("%d\n",dp[1][1]);
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
