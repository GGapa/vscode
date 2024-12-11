#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305,M=25,mod=998244353;
int a[N];
map<vector<int>,int>mp;
vector<int> jl;
int n,m,T,cnt,ivm,ivm2;
int A[N][N],B[N];
void dfs(int x,int lf,int pr){
	if(x>n){
		if(!lf)mp[jl]=++cnt;
		return;
	}
	if(pr*(n-x+1)<lf)return;
	for(int i=0;i<=pr;i++){
		if(lf-i<0)continue;
		jl.push_back(i);
		dfs(x+1,lf-i,i);
		jl.pop_back();
	}
}
int get(vector<int> v){
	sort(v.begin(),v.end());reverse(v.begin(),v.end());
	return mp[v];
}
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
void det(){
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(i==j)continue;
			int iv=A[j][i]*ksm(A[i][i],mod-2)%mod;
			for(int k=1;k<=cnt;k++)
				A[j][k]=(A[j][k]-A[i][k]*iv%mod+mod)%mod;
			B[j]=(B[j]-B[i]*iv%mod+mod)%mod;
		}
	}
	for(int i=1;i<=cnt;i++)B[i]=B[i]*ksm(A[i][i],mod-2)%mod;
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>T;
	ivm=ksm(m,mod-2);
	ivm2=ksm((n-1)*m%mod,mod-2);
	dfs(1,m,m);
	for(auto i:mp){
		vector<int>v=i.first;
		int x=get(v);
		if(x==cnt)continue;
		A[x][x]=1;
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				vector<int>g=v;
				if(!g[j])continue;
				g[j]--,g[k]++;
				int y=get(g);
				B[x]+=ivm*ivm2%mod*(m-v[k])%mod*v[j]%mod;B[y]%=mod;
				if(y!=cnt)A[x][y]+=mod-ivm*ivm2%mod*(m-v[k])%mod*v[j]%mod,A[x][y]%=mod;
			}
	}
	cnt--;
	det();
	while(T--){
		vector<int>v;
		for(int i=1,x;i<=n;i++)cin>>x,v.push_back(x);
		cout<<B[get(v)]<<'\n';
	}
	return 0;
}
