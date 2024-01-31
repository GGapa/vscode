#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
#include<bitset>
#include<random>
#include<ctime>
using namespace std;
const int maxn=805;
const int mod=1000000007;
int n,m,T,fa1[maxn],fa2[maxn],dep[maxn],yd[maxn],dep_[maxn],p[105]={1},cnt,jp[maxn][105];
long long dp[maxn][maxn];
vector<int> tree1[maxn],tree2[maxn];
void dfs(int s){
	for(int j=0;j<tree2[s].size();++j){
		int s_=tree2[s][j];
		dep[s_]=dep[s]+1;
		dfs(s_);
	}
	if(tree2[s].size()==1)yd[s]=yd[tree2[s][0]];
	else yd[s]=dep[s];
}
void dfs_(int s){
	for(int j=0;j<tree1[s].size();++j){
		int s_=tree1[s][j];
		dep_[s_]=dep_[s]+1;
		dfs_(s_);
	}
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=2;i<=n;++i){
		cin>>fa1[i];
		tree1[fa1[i]].push_back(i);
	}
	for(int i=2;i<=m;++i){
		cin>>fa2[i];
		tree2[fa2[i]].push_back(i);
	}
	dfs(1);
	dfs_(1);
	cin>>T;
	while(T--){
		int op,x;cin>>op>>x;
		if(op==1){
			p[++cnt]=x;
			sort(p+1,p+cnt+1);
		}
		else{
			int pos;
			for(int i=1;i<=cnt;++i)if(p[i]==x){
				pos=i;
				break;
			}
			for(int i=pos;i<cnt;++i)p[i]=p[i+1];
			cnt--;
		}
		for(int i=1;i<=m;++i){
			jp[i][0]=i;
			for(int j=1;j<=cnt;++j){
				int x=p[j]-p[j-1];
				jp[i][j]=jp[i][j-1];
				while(x--)jp[i][j]=fa2[jp[i][j]];
			}
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)dp[i][j]=0;
		for(int i=n;i>=1;--i)for(int j=m;j>=1;--j)if(dep_[i]<=dep[j]){
			dp[i][j]%=mod;
			if(tree1[i].size()==tree2[j].size()){
				int tmp=1;
				for(int u=0;u<tree1[i].size();++u){
					tmp=dp[tree1[i][u]][tree2[j][u]]*tmp%mod;
				}
				if(!tmp)continue;
				for(int u=1;u<=cnt;++u){
					if(!jp[j][u]||yd[jp[j][u]]<dep[j])break;
					dp[i][jp[j][u]]+=(long long)tmp;
				}
			}
		}
		cout<<dp[1][1]<<'\n';
	}
	return 0;
}
