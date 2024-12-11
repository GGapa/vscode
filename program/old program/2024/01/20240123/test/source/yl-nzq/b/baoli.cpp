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
LL dfs(int x1,int x2){
	if(f[x1][x2]!=-1)return f[x1][x2];
//	if(T1.ind[x1]<T2.ind[x2]&&T1.ind[x1]!=0) return 0;
//	if(T1.ind[x1]>T2.ind[x2]&&T2.ind[x2]!=1) return 0;
	LL ans=0;
	if(T1.ind[x1]==0){
//		cout<<"1::\n";
		int t=x2,len=0;
		while(T2.ind[t]==1){
			len++;
			t=T2.son[t];
		}
		len++;
		if(T2.ind[t]!=0) return (f[x1][x2]=0);
		if(!box[len]) return (f[x1][x2]=0);
		return (f[x1][x2]=1);
	}
	if(T2.ind[x2]==1){
		int t=x2,len=0;
		while(1){
			len++;
			if(box[len]&&T1.ind[x1]==T2.ind[t]){
				LL sum=1;
				for(int i=0;i<T1.ind[x1];i++){
					sum=sum*dfs(T1.G[x1][i],T2.G[t][i])%mod; 
				}
				ans=(ans+sum)%mod;
			}
			if(T2.ind[t]!=1) break;
			t=T2.son[t];
		}
		return (f[x1][x2]=ans);
	}
	if(T1.ind[x1]==T2.ind[x2]){
		if(box[1]!=1) return 0;
		LL sum=1;
		for(int i=0;i<T1.ind[x1];i++) sum=sum*dfs(T1.G[x1][i],T2.G[x2][i])%mod;
		return (f[x1][x2]=sum);
	}
	return (f[x1][x2]=0);
}
void work(){
	cin>>q;
	int o,x;
	for(int _=1;_<=q;_++){
		cin>>o>>x;
		if(o==1) box[x]=1;
		if(o==2) box[x]=0;
		for(int i=1;i<=T1.n;i++)for(int j=1;j<=T2.n;j++) f[i][j]=-1;
//		memset(f,-1,sizeof(f));
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
	return 0;
}
