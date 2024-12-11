// created:  Jan/23/2024 08:51:22
#include<cstdio>
#include<cstring>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=805,MOD=1000000007;
struct tree
{
	int n,fa[N],col[N],cc,rfa[N],siz[N];
	vector<int> adj[N];
	void dfs(int u)
	{
		for(int v:adj[u])dfs(v);
		if(adj[u].size()==1)col[u]=col[adj[u][0]];
		else col[u]=cc++;
	}
	void init()
	{
		F(i,1,n)adj[--read(fa[i])].emplace_back(i);
		dfs(0);
		rfa[col[0]]=-1;
		F(i,1,n)if(col[i]!=col[fa[i]])rfa[col[i]]=col[fa[i]];
		F(i,0,n)++siz[col[i]];
	}
	friend bool operator==(const tree &u,const tree &v)
	{
		if(u.cc!=v.cc)return false;
		F(i,0,u.cc)if(u.rfa[i]!=v.rfa[i])return false;
		return true;
	}
}t1,t2;
int pr[N][2],pc,f[N][N],n,m;
long long g[N];
vector<int> a;
int q;
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
#endif
	read(t1.n,t2.n);
	t1.init();t2.init();
	if(!(t1==t2))
	{
		read(q);
		while(q--)puts("0");
		return 0;
	}
	F(i,0,pc=t1.cc)pr[i][0]=t1.siz[i],pr[i][1]=t2.siz[i],n=max(n,pr[i][0]),m=max(m,pr[i][1]);
	f[0][0]=1;
	a.reserve(m);
	read(q);
	while(q--)
	{
		int opt,x;read(opt,x);
		f[1][x]+=opt==1?1:-1;
		a.clear();
		F(i,1,m+1)if(f[1][i])a.emplace_back(i);
		F(i,1,n)
		{
			F(j,0,m+1)g[j]=0;
			for(int j:a)F(k,i,m+1-j)g[k+j]+=f[i][k];
			F(j,0,m+1)f[i+1][j]=(int)(g[j]%MOD);
		}
		int ans=1;
		F(i,0,pc)ans=(int)((long long)ans*f[pr[i][0]][pr[i][1]]%MOD);
		printf("%d\n",ans);
	}
	return 0;
}
