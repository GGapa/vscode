#include <bits/stdc++.h>
#define rfor(i,l,r) for(int i=l;i<=r;i++)
#define irfor(i,r,l) for(int i=r;i>=l;i--)
#define y0 hfgdsgxdhrarsgtiddfndksgrsgilhfs
#define y1 qwertyuioplkjhgfdsazxcvbnmafdzds
#define ls(p) p<<1
#define rs(p) p<<1|1
#define mkp make_pair
using namespace std;typedef long long ll;typedef long double ld;typedef unsigned long long ull;typedef pair<int,int> pii;
inline ll read(){ll x=0,f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}return x*f;}
inline ll qpow(ll a,ll b,ll p){ll ans=1;while(b){if(b&1)ans=ans*a%p;a=a*a%p;b>>=1;}return ans;}
inline void gmin(int &a,int b){if(b<a)a=b;}inline void gmin(ll &a,ll b){if(b<a)a=b;}
inline void gmax(int &a,int b){if(b>a)a=b;}inline void gmax(ll &a,ll b){if(b>a)a=b;}
inline int max(int a,int b){return a>b?a:b;}inline int min(int a,int b){return a<b?a:b;}
inline ll max(ll a,ll b){return a>b?a:b;}inline ll min(ll a,ll b){return a<b?a:b;}
const int N = 805,mod=1e9+7;
inline void add(int &a,int b){a = a+b>mod?a+b-mod:a+b;}
struct Tree{
	int n,fa[N];
	vector<int> adj[N];
	void init()
	{
		rfor(i,2,n)
		{
			fa[i] = read();
			adj[fa[i]].push_back(i);
		}
		rfor(i,1,n) sort(adj[i].begin(),adj[i].end());
	}
	pii getnxt(int p)
	{
		int len = 1;
		while(adj[p].size() == 1) p = adj[p][0],len++;
		return mkp(p,len);
	}
}t1,t2;
vector<pii> vc;
int mc1,mc2;
bool dfs(int p1,int p2)
{
	pii tp1 = t1.getnxt(p1),tp2 = t2.getnxt(p2);
	vc.push_back(mkp(tp1.second,tp2.second));
	gmax(mc1,tp1.second),gmax(mc2,tp2.second);
	if(tp1.second > tp2.second) return false;
	p1 = tp1.first,p2 = tp2.first;
	if(t1.adj[p1].size() != t2.adj[p2].size()) return false;
	int sz = t1.adj[p1].size();
	rfor(i,0,sz-1) if(!dfs(t1.adj[p1][i],t2.adj[p2][i])) return false;
	return true;
}
int q;
set<int> st;
vector<int> vst;
int vnum;
int notim;
int dp[N][N];
/*
int tim[N][N];
int dfsdp(int x,int y)
{
	if(x == 0 || y == 0) return (x==0 && y==0);
	if(tim[x][y] == notim) return dp[x][y];
	tim[x][y] = notim;
	if(x*vst[vnum-1] < y || x*vst[0] > y) return dp[x][y] = 0;
	if(x*vst[0] == y || x*vst[vnum-1] == y) return dp[x][y] = 1;
	dp[x][y] = 0;
	for(int tp:vst)
	{
		if(tp > y) break;
		add(dp[x][y],dfsdp(x-1,y-tp));
	}
	return dp[x][y];
}
*/
inline void solve()
{
	t1.n = read(),t2.n = read();
	t1.init();t2.init();
	q = read();
	if(!dfs(1,1))
	{
		while(q--) cout << "0\n";
		return;
	}
	int op,x;
	rfor(nt,1,q)
	{
		notim = nt;
		op = read(),x = read();
		if(op == 1) st.insert(x);
		else st.erase(x);
		vst.clear();
		for(int x:st) vst.push_back(x);
		vnum = vst.size();
		if(vnum == 0)
		{
			cout << "0\n";
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		rfor(i,1,mc1)
		{
			int tmpl = (i-1)*vst[0],tmpr = min(i*vst[vnum-1],mc2);
			for(int k:vst) rfor(j,tmpl+k,tmpr) add(dp[i][j],dp[i-1][j-k]);
		}
		ll ans = 1;
		for(pii x:vc)
		{
			ans = ans*dp[x.first][x.second]%mod;
			if(ans == 0) break;
		}
		cout << (ans%mod+mod)%mod << '\n';
	}
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;//cin >> t;
	while(t--) solve();
	return 0;
}

