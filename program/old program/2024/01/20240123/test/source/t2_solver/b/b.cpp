#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=805,mod=1e9+7;
int n1,n2,q;
vector<int> e1[maxn],e2[maxn];
int f[maxn][maxn],son[maxn][maxn];
vector<int> cur;
set<int> st;
int dfs(int u,int v){
	if(f[u][v]!=-1)return f[u][v];
	f[u][v]=0;
	for(auto len:cur){
		if(!son[v][len])continue;
		int res=1,x=son[v][len];
		if(e1[u].size()!=e2[x].size())continue;
		for(int i=0;i<e1[u].size();i++)res=res*dfs(e1[u][i],e2[x][i])%mod;
		(f[u][v]+=res)%=mod;
	}
	return f[u][v];
}
void qsy(int u){
	son[u][1]=u;
	int now=u,d=1;
	while(e2[now].size()==1){
		now=e2[now][0];
		d++;
		son[u][d]=now;
	}
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n1>>n2;
	for(int i=2;i<=n1;i++){
		int x;cin>>x;
		e1[x].push_back(i);
	}
	for(int i=2;i<=n2;i++){
		int x;cin>>x;
		e2[x].push_back(i);
	}
	for(int i=1;i<=n2;i++)qsy(i);
	cin>>q;
	while(q--){
		int tp,x;
		cin>>tp>>x;
		if(tp==1){
			st.insert(x);
		}else st.erase(x);
		cur.clear();
		for(auto u:st)cur.push_back(u);
		for(int i=1;i<=n1;i++)for(int j=1;j<=n2;j++)f[i][j]=-1;
		dfs(1,1);
		cout<<f[1][1]<<"\n";
	}
	return 0;
}