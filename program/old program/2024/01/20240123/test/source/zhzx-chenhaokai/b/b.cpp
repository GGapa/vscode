#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back
const int mod=1e9+7,N=805;
int n1,n2,nxt1[N],nxt2[N],flag,top,q,f[N][N],ok[N],mx[N];
vector<int>E[N],G[N],Q[N]; 
pair<int,int>st[N];
int Mod(int x){return x>=mod?x-mod:x;}
void dfs(int u,int v){
	int l1=1,l2=1;
	while(nxt1[u])u=nxt1[u],l1++;
	while(nxt2[v])v=nxt2[v],l2++;
	if(E[u].size()!=G[v].size()||l1>l2){flag=0;return;}
	st[++top]=mkp(l1,l2-l1);
	for(int i=0;i<E[u].size();i++)dfs(E[u][i],G[v][i]);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n1,&n2);
	for(int i=2,f;i<=n1;i++){
		scanf("%d",&f);
		E[f].pb(i);		
	}for(int i=2,f;i<=n2;i++){
		scanf("%d",&f);
		G[f].pb(i);
	}for(int i=1;i<=n1;i++)
		if(E[i].size()==1)nxt1[i]=*E[i].begin();
	for(int i=1;i<=n2;i++)
		if(G[i].size()==1)nxt2[i]=*G[i].begin();
	flag=1;dfs(1,1);scanf("%d",&q);
	if(!flag){while(q--)puts("0");return 0;}
	f[0][0]=1;int n=max(n1,n2);
	for(int i=1;i<=top;i++){
		mx[st[i].first]=max(mx[st[i].first],st[i].second);
		Q[st[i].first].pb(st[i].second);
	}
	for(int i=n;i>=1;i--)mx[i]=max(mx[i],mx[i+1]);
	for(int op,x;q--;){
		scanf("%d%d",&op,&x);
		x--;ok[x]^=1;int ans=1;
		for(int i=1;i<=n&&ans;i++){
			for(int j=0;j<=mx[i];j++)f[i][j]=0;
			for(int j=0;j<=n;j++)if(ok[j])
				for(int k=j;k<=mx[i];k++)f[i][k]=Mod(f[i-1][k-j]+f[i][k]);
			for(auto w:Q[i])ans=1ll*ans*f[i][w]%mod;
		}printf("%d\n",ans);
	}
}
