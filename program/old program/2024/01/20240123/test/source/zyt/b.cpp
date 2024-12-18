#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=800+5,mod=998244353;
int n1,n2,n,q;
int f1[N],f2[N];
vector<int>e1[N],e2[N];
vector<pair<int,int>>rec;
bool dfs(int v1,int v2){
	if(e1[v1].size()!=e2[v2].size())return false;
	for(int i=0;i<(int)e1[v1].size();i++){
		int u1=e1[v1][i],u2=e2[v2][i];
		int cnt1=1,cnt2=1;
		while(e1[u1].size()==1)cnt1++,u1=e1[u1].front();
		while(e2[u2].size()==1)cnt2++,u2=e2[u2].front();
		if(cnt1>cnt2)return false;
		rec.push_back({cnt1,cnt2-cnt1});
		if(!dfs(u1,u2))return false;
	}
	return true;
}
int dp[N][N];
bool fl[N];
int st[N],top;
int A,B;
void solve(){
	for(int i=0;i<=A;i++)for(int j=0;j<=B;j++)dp[i][j]=0;
	top=0;
	for(int i=0;i<=n;i++)if(fl[i])st[++top]=i;
	dp[0][0]=1;
	for(int i=1;i<=A;i++)
		for(int j=0;j<=B;j++)
			for(int k=1;k<=top&&j+st[k]<=B;k++)
				(dp[i][j+st[k]]+=dp[i-1][j])%=mod;

}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n1,&n2);
	n=max(n1,n2);
	for(int i=2;i<=n1;i++){
		scanf("%d",&f1[i]);
		e1[f1[i]].push_back(i);
	}
	for(int i=2;i<=n2;i++){
		scanf("%d",&f2[i]);
		e2[f2[i]].push_back(i);
	}
	for(int i=1;i<=n1;i++)sort(e1[i].begin(),e1[i].end());
	for(int i=1;i<=n2;i++)sort(e2[i].begin(),e2[i].end());
	int rt1=1,rt2=1,cnt1=1,cnt2=1;
	while(e1[rt1].size()==1)cnt1++,rt1=e1[rt1].front();
	while(e2[rt2].size()==1)cnt2++,rt2=e2[rt2].front();
	if(cnt1>cnt2){
		scanf("%d",&q);
		while(q--)puts("0");
		return 0;
	}
	rec.push_back({cnt1,cnt2-cnt1});
	if(!dfs(rt1,rt2)){
		scanf("%d",&q);
		while(q--)puts("0");
		return 0;
	}
	for(auto i:rec)A=max(A,i.first),B=max(B,i.second);
	scanf("%d",&q);
	while(q--){
		int opt,x;scanf("%d%d",&opt,&x);
		fl[x-1]=opt==1?1:0;
		solve();
		LL ans=1;
		for(auto i:rec)ans=ans*dp[i.first][i.second]%mod;
		printf("%lld\n",ans);
	}
	return 0;
}