/*
有一棵仙人掌。点有点权，边有边权。
一个独立集的权值为内部点的点权和 加上 没有端点被选的边权和。
给出 p,a，求若把随机 p 个不同的点或边的权值加上 a，所有独立集权值的 k 次方和 的期望。

考虑先统计出 f[c][k] 表示恰好包含 c 个点或边的独立集的权值的 k 次方和。
枚举有 x 个点或边落在了 c 个内，答案为 sum(x) { (C(c,x)C(n+m-c,p-x))/C(n+m,p) E((s+xa)^k) }
	统计答案是 O(n^3)。

对于求 f，考虑在圆方树上 DP。设 g[u][0/1][c][k] 表示是否选 u，u 的子树内现在有 c 个点/边，所有方案点/边权和的 k 次方和。
应该是 O(n^3 k)？。是不是可以用类似树形背包来分析到 O(n^2 k)。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int md=998244353;
int quickPow(int x,int k)
{
	int ans=1;
	for(;k;k>>=1,x=x*x%md)
	{
		if(k&1)
			ans=ans*x%md;
	}
	return ans;
}
int n,m,k,p,a;
int C[2800][2800];
void getC(const int lim=2710)
{
	// cout<<"GetC begin"<<endl;
	C[0][0]=1;
	for(int i=1;i<=lim;i++)
	{
		for(int j=0;j<=i;j++)
		{
			C[i][j]=(C[i-1][j]+(j==0?0:C[i-1][j-1]))%md;
		}
	}
	// cout<<"GetC done"<<endl;
}
struct Data
{
	int v[35];
	Data(int x=-1)
	{
		for(int i=0,p=1;i<=k;i++,p=p*x%md)
			v[i]=(x==-1?0:p);
	}
	friend ostream& operator<<(ostream &os,Data d)
	{
		os<<"< ";
		for(int i=0;i<=k;i++)
			os<<d.v[i]<<" ";
		os<<">";
		return os;
	}
	friend int mergeK(Data a,Data b)
	{
		int res=0;
		for(int i=0;i<=k;i++)
			res=(res+a.v[i]*b.v[k-i]%md)%md;
		return res;
	}
	friend Data merge(Data a,Data b)
	{
		Data res(-1);
		for(int i=0;i<=k;i++)
		{
			for(int j=0;i+j<=k;j++)
			{
				res.v[i+j]=(res.v[i+j]+a.v[i]*b.v[j]%md)%md;
			}
		}
		return res;
	}
	friend Data operator+(Data a,Data b)
	{
		for(int i=0;i<=k;i++)
			a.v[i]=(a.v[i]+b.v[i])%md;
		return a;
	}
};
vector<int> t[910];
int val[910];
int edg[910][910];
vector<Data> f[910][2];
vector<Data> st;
int dfn[910],low[910],clk;
void doDP(int u,bool chsu,vector<int> p)
{
	vector<vector<vector<Data>>> tf(p.size(),vector<vector<Data>>(2,vector<Data>(0)));
	tf[0][0]=vector<Data>({Data(0)}),tf[0][1]=vector<Data>({Data(-1)});
	for(int i=1;i<p.size();i++)
	{
		tf[i][0]=vector<Data>(tf[i-1][0].size()-1+f[p[i]][0].size()-1+1+1);
		tf[i][1]=vector<Data>(tf[i-1][0].size()-1+f[p[i]][1].size()-1+1);
		for(int c=0;c<tf[i-1][0].size();c++)
		{
			for(int c1=0;c1<f[p[i]][0].size();c1++)
			{
				tf[i][0][c+c1+1]=tf[i][0][c+c1]+merge(merge(tf[i-1][0][c],Data(edg[p[i-1]][p[i]])),f[p[i]][0][c1]);
			}
		}
		for(int c=0;c<tf[i-1][1].size();c++)
		{
			for(int c1=0;c1<f[p[i]][0].size();c1++)
			{
				tf[i][0][c+c1]=tf[i][0][c+c1]+merge(tf[i-1][1][c],f[p[i]][0][c1]);
			}
		}
		for(int c=0;c<tf[i-1][0].size();c++)
		{
			for(int c1=0;c1<f[p[i]][1].size();c1++)
			{
				tf[i][1][c+c1]=tf[i][1][c+c1]+merge(tf[i-1][0][c],f[p[i]][1][c1]);
			}
		}
	}
	if(chsu==0)
	{
		vector<Data> fu0=f[u][0];
		f[u][0]=vector<Data>(fu0.size()-1+max<int>(tf.back()[0].size()+1,tf.back()[1].size())-1+1,Data(-1));
		for(int cu=0;cu<fu0.size();cu++)
		{
			for(int c1=0;c1<max<int>(tf.back()[0].size()+1,tf.back()[1].size());c1++)
			{
				Data th(-1);
				if(c1>=1&&c1<tf.back()[0].size()+1) th=th+merge(tf.back()[0][c1-1],edg[p.back()][u]);
				if(c1<tf.back()[1].size()) th=th+tf.back()[1][c1];
				f[u][0][cu+c1]=f[u][0][cu+c1]+merge(fu0[cu],th);
			}
		}
	}
	if(chsu==1)
	{
		vector<Data> fu1=f[u][1];
		f[u][1]=vector<Data>(fu1.size()-1+tf.back()[0].size()-1+1,Data(-1));
		for(int cu=0;cu<fu1.size();cu++)
		{
			for(int c1=0;c1<tf.back()[0].size();c1++)
			{
				f[u][1][cu+c1]=f[u][1][cu+c1]+merge(fu1[cu],tf.back()[0][c1]);
			}
		}
	}
}
void tarjan(int u,int fth)
{
	static stack<int> stk={};
	dfn[u]=low[u]=++clk;
	stk.push(u);
	f[u][0]=vector<Data>({Data(0)});
	f[u][1]=vector<Data>({Data(-1),Data(val[u])});
	for(int i=0;i<t[u].size();i++)
	{
		int v=t[u][i];
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min<int>(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				vector<int> p({u});
				int tmp=0;
				do
				{
					tmp=stk.top(),p.push_back(tmp);
					stk.pop();
				}
				while(tmp!=v);
				doDP(u,0,p);
				doDP(u,1,p);
			}
		}
		else if(v!=fth)
			low[u]=min<int>(low[u],dfn[v]);
	}
	// for(int x=0;x<=1;x++)
	// {
	// 	for(int c=0;c<f[u][x].size();c++)
	// 	{
	// 		cout<<"f u="<<u<<" x="<<x<<" c="<<c<<" = "<<f[u][x][c]<<endl;
	// 	}
	// }
}
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	getC();
	cin>>n>>m>>k>>p>>a;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		t[a].push_back(b),t[b].push_back(a);
		edg[a][b]=edg[b][a]=w;
	}
	t[1].push_back(0),t[0].push_back(1);
	tarjan(0,0);
	st=vector<Data>(max<int>(f[1][0].size(),f[1][1].size()));
	for(int x=0;x<=1;x++)
	{
		for(int c=0;c<f[1][x].size();c++)
		{
			st[c]=st[c]+f[1][x][c];
		}
	}
	int sum=0,cnt=0;
	for(int c=0;c<st.size();c++)
	{
		for(int x=0;x<=min<int>(p,c);x++)
		{
			sum=(sum+(C[c][x]*C[n+m-c][p-x]%md)*mergeK(st[c],Data(x*a))%md)%md;
			// cnt=(cnt+(C[c][x]*C[n+m-c][p-x]%md)*st[c].v[0]%md)%md;
		}
	}
	cout<<sum*quickPow(C[n+m][p],md-2)%md<<endl;
}