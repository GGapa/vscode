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
vector<int> t1[mxn],t2[mxn],dl[mxn];
int dp[mxn][mxn];
set<int> v;
int cnt;
void dfs(int x,int y)
{
	if(~dp[x][y]) return;
//	cout<<x<<' '<<y<<endl;
//	if(t1[x].empty()&&t2[x].empty())
//	{
//		dp[x][y]=1;
//		return;
//	}
	dp[x][y]=0;
	for(auto i:v)
	{
		if(i>dl[y].size()) break;
		if(t2[dl[y][i-1]].size()==t1[x].size())
		{
			int mul=1;
			for(int j=0;j<t1[x].size();j++)
				dfs(t1[x][j],t2[dl[y][i-1]][j]),mul=1ll*mul*dp[t1[x][j]][t2[dl[y][i-1]][j]]%mod;
//			cout<<x<<' '<<y<<':'<<x<<' '<<dl[y][i-1]<<endl;
			getmod(dp[x][y]+=mul);
		}
	}
//	cout<<x<<' '<<y<<':'<<dp[x][y]<<endl;
}	
int main()
{
//	system("fc out ex_b3.ans");
//	freopen("ex_b3.in","r",stdin);
	freopen("out","w",stdout);
	int n1=800,n2=800,i,j,q;
	for(i=2;i<=n1;i++)
		t1[i-1].push_back(i);
	for(i=2;i<=n2;i++)
		t2[i-1].push_back(i);
	for(i=1;i<=n2;i++)
	{
		for(j=i;;)
		{
			dl[i].push_back(j);	
			if(t2[j].size()>1) break;
			if(t2[j].empty()) break;
			j=t2[j][0];
		}
//		cout<<i<<':';
//		for(auto j:dl[i])
//			cout<<j<<' ';
//		cout<<endl;
	}
	q=100;
	for(j=1;j<=q;j++)
	{
		i=1;
		if(i==1) v.insert(j);
		else v.erase(j);
		cnt=0;
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
