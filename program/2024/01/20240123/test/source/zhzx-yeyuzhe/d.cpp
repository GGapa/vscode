#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=905,Mod=998244353;
int N,M,K,P,T,A[maxn],Fa[maxn];
vector<pair<int,int>> E[maxn];
LL QSM(LL x,LL y){
	LL ret=1;x%=Mod;
	while(y){
		if(y&1) ret=ret*x%Mod;
		x=x*x%Mod;y>>=1;
	}
	return ret;
}
namespace sub1{
	bool check(){
		return P==0&&M==N-1;
	}
	LL F[maxn][2],G[maxn][2];
	void DFS(int root,int fa){
		G[root][0]=G[root][1]=1;
		for(auto son:E[root]) if(son.first!=fa) {
			int v=son.first;
			DFS(son.first,root);
			G[root][0]=G[root][0]*(G[v][0]+G[v][1])%Mod;
			G[root][1]=G[root][1]*G[v][0]%Mod;
		}
		F[root][0]=0;
		F[root][1]=G[root][1]*A[root]%Mod;
		LL ret0=1,ret1=1;bool f=0;
		for(auto son:E[root]) if(son.first!=fa){
			f=1;
			int v=son.first,w=son.second;
			ret0=ret0*(F[v][0]+G[v][0]*w+F[v][1])%Mod;
			ret1=ret1*F[v][0];
		}
		if(f) F[root][0]=ret0,F[root][1]=(F[root][1]+ret1)%Mod;
	}
	LL solve(){
		DFS(1,0);
//		for(int i=1;i<=N;i++) printf("%d %d\n",F[i][0],F[i][1]);
//		puts("");
//		for(int i=1;i<=N;i++) printf("%d %d\n",G[i][0],G[i][1]);
		return (F[1][0]+F[1][1])%Mod;
	}
}
namespace sub2{
	bool check(){
		return P==1&&M==N-1;
	}
	LL solve(){
		LL Ret=0,Cnt=0;
		for(int i=1;i<=N;i++)
		for(auto &son:E[i])
		 if(Fa[son.first]==i) son.second+=T,(Ret+=sub1::solve())%=Mod,Cnt++,son.second-=T;
		return Ret*QSM(Cnt,Mod-2)%Mod; 
	}
}
void DFS1(int root,int fa){
	Fa[root]=fa;
	for(auto son:E[root]) if(son.first!=fa) DFS1(son.first,root);
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>N>>M>>K>>P>>T;
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1,x,y,w;i<N;i++) cin>>x>>y>>w,E[x].emplace_back(make_pair(y,w)),E[y].emplace_back(make_pair(x,w));
	DFS1(1,0) ;
	if(sub1::check()) printf("%lld\n",sub1::solve());else
	if(sub2::check()) printf("%lld\n",sub2::solve());
	return 0;
}
