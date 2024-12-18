/*
给出两棵树 T1、T2 树的儿子顺序确定。
可以把 T1 的每个点替换为一条长度在 S 中的链，链头接父亲，链尾接儿子，使 T1 与 T2 除标号外完全相同。
每次在 S 中插入/删除一个数，求替换方案数。
S 中的数在 [1,n2] 中。

考虑 T1 与 T2 的每次分叉。每次分叉的位置与叉数必须完全对应，否则无解。可以预处理一下每个点下方第一个分叉点，然后可以得到对应关系。
	现在 T1 一条链上的若干个点对应 T2 的一条链。即求 S 中 c 个点和为 s 的方案数。显然 s<=n2。
这个背包的方案数是带顺序的。
每次重构可以做到 O(q^2 n^2)。把 GF 用二项式定理展开是 O(q n^3)。
二维 FFT 或许可以做到 O(q n^2 log)？
*/
#include<bits/stdc++.h>
using namespace std;
const int md=1e9+7;
int n[2],q;
vector<int> t[2][810];
int dep[2][810],brp[2][810];
vector<pair<int,int>> ned;
vector<int> len;
int f[810][810];
void throwError()
{
	for(int i=1;i<=q;i++)
		cout<<0<<endl;
	exit(0);
}
void dfs(int tid,int u)
{
	for(int v:t[tid][u])
	{
		dep[tid][v]=dep[tid][u]+1;
		dfs(tid,v);
	}
	if(t[tid][u].size()!=1)
		brp[tid][u]=u;
	else
		brp[tid][u]=brp[tid][t[tid][u][0]];
	// cout<<"brp tid="<<tid<<" u="<<u<<" = "<<brp[tid][u]<<endl;
}
void getNeeds(int u0,int u1)
{
	// cout<<"getNeeds u0="<<u0<<" u1="<<u1<<endl;
	if(t[0][u0].size()!=t[1][u1].size())
		throwError();
	for(int i=0;i<t[0][u0].size();i++)
	{
		int v0=brp[0][t[0][u0][i]],v1=brp[1][t[1][u1][i]];
		int c0=dep[0][v0]-dep[0][u0],c1=dep[1][v1]-dep[1][u1];
		ned.push_back(make_pair(c0,c1));
		// cout<<"Need u0="<<u0<<" v0="<<v0<<" u1="<<u1<<" v1="<<v1<<" => "<<c0<<" "<<c1<<endl;
		getNeeds(v0,v1);
	}
}
void rebuildF()
{
	for(int c=1;c<=n[0];c++)
	{
		for(int s=n[1];s>=0;s--)
		{
			f[c][s]=0;
			for(int x:len)
			{
				if(s>=x)
					f[c][s]=(f[c][s]+f[c-1][s-x])%md;
			}
		}
	}
	// for(int c=0;c<=n[0];c++)
	// {
	// 	for(int s=0;s<=n[1];s++)
	// 		cout<<f[c][s]<<" ";
	// 	cout<<endl;
	// }
}
// void insertLength(int x)
// {
// 	for(int c=1;c<=n[0];c++)
// 	{
// 		for(int s=x;s<=n[1];s++)
// 		{
// 			f[c][s]=(f[c][s]+f[c-1][s-x])%md;
// 		}
// 	}
// 	for(int c=0;c<=n[0];c++)
// 	{
// 		for(int s=0;s<=n[1];s++)
// 			cout<<f[c][s]<<" ";
// 		cout<<endl;
// 	}
// }
// void removeLength(int x)
// {
// 	for(int c=n[0];c>=1;c--)
// 	{
// 		for(int s=x;s<=n[1];s++)
// 		{
// 			f[c][s]=(f[c][s]-f[c-1][s-x]+md)%md;
// 		}
// 	}
// }
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	// clock_t c1=clock();
	cin>>n[0]>>n[1];
	for(int tid=0;tid<=1;tid++)
	{
		for(int i=1;i<=n[tid];i++)
		{
			int f=0;
			if(i>=2)
				cin>>f;
			t[tid][f].push_back(i);
		}
	}
	cin>>q;
	dep[0][0]=dep[1][0]=1,dfs(0,0),dfs(1,0);
	getNeeds(0,0);
	for(int i=1;i<=q;i++)
	{
		int ty,x;
		cin>>ty>>x;
		if(ty==1)
			len.push_back(x);
		else
			len.erase(find(len.begin(),len.end(),x));
		f[0][0]=1;
		rebuildF();
		int ans=1;
		for(pair<int,int> x:ned)
			ans=1LL*ans*f[x.first][x.second]%md;
		cout<<ans<<endl;
	}
	// cerr<<1000*(clock()-c1)/CLOCKS_PER_SEC<<" ms"<<endl;
}
/*
6 9
1 1 3 3 5
1 1 2 3 3 5 6 8
5
1 1
1 2
1 3
2 1
2 2
*/