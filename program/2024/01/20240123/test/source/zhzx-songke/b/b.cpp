#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
using namespace std;
const int mod=1e9+7;
int dp[809][809];int n;int Nx,Mx;
struct TREE
{
	int n;
	vector<int> E[809];
	int fa[809];
}N,Z;
int fac[1009],inv[1009];
void reduce(int &a)
{
	if(a>=mod)a-=mod;
}
void add(int x)
{
	G(i,Nx,1)
	F(j,x,Mx)
	F(k,1,min(i,j/x))
	reduce(dp[i][j]+=1ll*dp[i-k][j-k*x]*inv[k]%mod);
}

void del(int x)
{
	F(i,1,Nx)
	F(j,x,Mx)
	F(k,1,min(i,j/x))
		reduce(dp[i][j]+=mod-1ll*inv[k]*dp[i-k][j-x*k]%mod);	
}
vector<pair<int,int>> ans;
bool chk=true;
void dfs(int x,int y)
{
	int cnt=1,cnt1=1;
	while(N.E[x].size()==1) x=N.E[x][0],cnt++;
	while(Z.E[y].size()==1) y=Z.E[y][0],cnt1++;
	if(N.E[x].size()!=Z.E[y].size()) chk=false;
	if(!chk)return ;
	if(cnt>cnt1) chk=false; 
	ans.emplace_back(make_pair(cnt,cnt1));
	F(i,0,(int)N.E[x].size()-1)
		dfs(N.E[x][i],Z.E[y][i]);
	}
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod; 
		y>>=1;
	}
	return res;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N.n>>Z.n;dp[0][0]=1;
	fac[0]=1;int MK=max(N.n,Z.n);
	F(i,1,MK)fac[i]=1ll*fac[i-1]*i%mod;
	inv[MK]=qpow(fac[MK],mod-2);
	G(i,MK,1) inv[i-1]=1ll*inv[i]*i%mod;
	F(i,2,N.n)
	{
		int x;
		cin>>x;
		N.E[x].emplace_back(i);
		N.fa[i]=x;
	}
	F(i,2,Z.n)
	{
		int x;
		cin>>x;
		Z.E[x].emplace_back(i);
		Z.fa[i]=x;
	}
	dfs(1,1);
	int q;
	cin>>q;
	sort(ans.begin(),ans.end(),[&](auto A,auto B){return A.first<B.first;});
	for(auto u:ans) Nx=max(Nx,u.first),Mx=max(Mx,u.second); 
	F(i,1,q)
	{
		int op,x;
		cin>>op>>x;
		if(chk)
		{
			if(op==1) add(x);
			else del(x);
		}//nz.dp[x]^=1;
		if(!chk) cout<<0<<endl;
		else
		{
			int out=1;
		//	cerr<<"chk is hand?";
			for(auto u:ans) out=1ll*out*dp[u.first][u.second]%mod*fac[u.first]%mod;
			cout<<out<<endl;
		}
		 
	}
}
