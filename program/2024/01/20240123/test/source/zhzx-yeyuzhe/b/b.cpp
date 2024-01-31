#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int maxn=805,Mod=1000000007;
int N,M,Q,Fa1[maxn],Fa2[maxn],Dep1[maxn],Dep2[maxn],Du1[maxn],Du2[maxn];
vector<int> E1[maxn],E2[maxn];
LL F[maxn][maxn];
int G[maxn][maxn],Max[maxn],id[maxn][maxn],D1[maxn],D2[maxn];
void DFS(int root){
	for(auto son:E2[root]) DFS(son),D2[root]=max(D2[root],D2[son]);
	if(E2[root].size()==1) {
		int v=E2[root][0];
		Max[root]=Max[E2[root][0]]+1;
		int ret=0;id[root][++ret]=v;
		while(E2[v].size()==1) v=E2[v][0],id[root][++ret]=v;
	}
	D2[root]++;
}
void DFS2(int root){
	for(auto son:E1[root]) DFS2(son),D1[root]=max(D1[root],D1[son]);
	D1[root]++;
}
int Get_G(int x,int y){
	if(~G[x][y]) return G[x][y];
	G[x][y]=1;int L=Du1[x];
	for(int i=0;i<L;i++)
	 G[x][y]=G[x][y]*F[E1[x][i]][E2[y][i]]%Mod;
	return G[x][y];
}
vector<int> ss[maxn];
void DP(){
	for(int i=N;i;i--)
	for(int j=M;j;j--){
		if(Du1[i]==Du2[j]){
			G[i][j]=1;
			for(int k=Du1[i]-1;~k;k--)
			 G[i][j]=1ll*G[i][j]*F[E1[i][k]][E2[j][k]]%Mod;
		}
		else G[i][j]=0;
		if(Dep1[i]<=Dep2[j]&&D1[i]<=D2[j]){
			F[i][j]=0;
			for(auto v:ss[j]) {
				if(D1[i]>D2[v]) break;
				F[i][j]+=G[i][v];
			}
			F[i][j]%=Mod;
		}
	}
	printf("%lld\n",F[1][1]);
}
void Push(int w){
	for(int i=1;i<=M;i++)
	 if(id[i][w]) ss[i].emplace_back(id[i][w]),sort(ss[i].begin(),ss[i].end());
}
void del(int w){
	for(int i=1;i<=M;i++)
	for(int j=0;j<(int)ss[i].size();j++)
	 if(ss[i][j]==id[i][w]) {swap(ss[i][j],ss[i][(int)ss[i].size()-1]),ss[i].pop_back();sort(ss[i].begin(),ss[i].end());break;}
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>N>>M;
	for(int i=2;i<=N;i++) cin>>Fa1[i],E1[Fa1[i]].emplace_back(i),Dep1[i]=Dep1[Fa1[i]]+1,Du1[Fa1[i]]++;
	for(int i=2;i<=M;i++) cin>>Fa2[i],E2[Fa2[i]].emplace_back(i),Dep2[i]=Dep2[Fa2[i]]+1,Du2[Fa2[i]]++;
	for(int i=1;i<=M;i++) id[i][0]=i;
	DFS(1);DFS2(1);
//	for(int i=1;i<=M;i++,puts("")) for(int j=0;id[i][j];j++) printf("%d ",id[i][j]);
	cin>>Q;
	while(Q--){
		int a,b;cin>>a>>b;
		if(a==1) Push(b-1);else del(b-1);
		DP();
//		for(int i=1;i<=M;i++,puts("")) for(auto j:ss[i]) printf("%d ",j);
	}
//	cerr<<clock()<<'\n';
	return 0;
}
