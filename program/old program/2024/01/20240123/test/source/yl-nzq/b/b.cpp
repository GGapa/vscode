#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=810,mod=1e9+7;
LL f[N][N];
struct Tree{
	int n,fa[N],ind[N],son[N];
	vector<int> G[N];
	void init(){
		for(int i=2;i<=n;i++) G[fa[i]].push_back(i);
		for(int i=1;i<=n;i++){
			sort(G[i].begin(),G[i].end());
			ind[i]=G[i].size();
			if(ind[i]==1) son[i]=G[i][0];
		}
	}
}T1,T2;
int q,box[N];
void read(){
	cin>>T1.n>>T2.n;
	for(int i=2;i<=T1.n;i++) cin>>T1.fa[i];
	for(int i=2;i<=T2.n;i++) cin>>T2.fa[i];
	T1.init(); T2.init();
}
LL g(int i,int j){
	if(f[i][j]!=-1) return f[i][j];
	f[i][j]=0;
	int L=(i>>1),R=i-L;
	for(int k=0;k<=j;k++){
		f[i][j]=(f[i][j]+g(L,k)*g(R,j-k)%mod);
	}
	f[i][j]%=mod;
	return f[i][j];
}
LL dfs(int x1,int x2){
	if(x1==0&&x2==0) return 1;
	int len1=0,len2=0;
	while(1){
		len1++;
		if(T1.ind[x1]!=1) break;
		x1=T1.son[x1];
	}
	while(1){
		len2++;
		if(T2.ind[x2]!=1) break;
		x2=T2.son[x2];
	}
	if(T1.ind[x1]!=T2.ind[x2]) return 0;
	LL sum=g(len1,len2);
	for(int i=0;i<T1.ind[x1];i++) sum=sum*dfs(T1.G[x1][i],T2.G[x2][i])%mod;
	return sum;
}
void work(){
	int o,x;
	cin>>q;
	while(q--){
		cin>>o>>x;
		if(T1.n>T2.n){
			cout<<"0\n";
			continue;
		}
		if(o==1) box[x]=1;
		if(o==2) box[x]=0;
		memset(f,-1,sizeof(f));
		f[0][0]=1;
		for(int i=1;i<=T2.n;i++) f[1][i]=box[i];
		cout<<dfs(1,1)<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read();
	work();
//	cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
	return 0;
}
