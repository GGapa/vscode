#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
constexpr int N=805,mod=1e9+7;
int n1,n2,q,d1[N],d2[N],f[N][N];set<int>s;
vector<int>T1[N],T2[N];
inline void add(int&x,const int y){x+=y;if(x>=mod)x-=mod;}
struct poly{
	int n,f[N];
	poly(){memset(f,0,sizeof f);}
	inline poly operator*(const poly&other)const{
		poly res=poly();
		res.n=n;
		rep(i,0,n)if(f[i]){
			const int tmp=f[i];
			rep(j,0,n-i)add(res.f[i+j],(ll)tmp*other.f[j]%mod);
		}
		return res;
	}
}g,ans;
inline int calcf(int l1,int l2){
	g=poly(),ans=poly();
	g.n=ans.n=l2;
	for(auto x:s)if(x<=l2)g.f[x]=1;
	ans.f[0]=1;
	for(;l1;l1>>=1,g=g*g)if(l1&1)ans=ans*g;
	return ans.f[l2];
}
inline int dfs(int x,int y){
	int len1=1,len2=1;
	while(d1[x]==1)x=T1[x][0],++len1;
	while(d2[y]==1)y=T2[y][0],++len2;
	if(d1[x]!=d2[y])return 0;
	int coef=calcf(len1,len2);
	const int z=d1[x];
	rep(i,0,z-1)coef=(ll)coef*dfs(T1[x][i],T2[y][i])%mod;
	return coef;
}
int main(){
	cin>>n1>>n2;
	rep(i,2,n1){int x;cin>>x,T1[x].emplace_back(i);}
	rep(i,2,n2){int x;cin>>x,T2[x].emplace_back(i);}
	rep(i,1,n1)d1[i]=T1[i].size();
	rep(i,1,n2)d2[i]=T2[i].size();
	cin>>q,f[0][0]=1;
	while(q--){
		int op,x;cin>>op>>x;
		if(op&1)s.insert(x);
		else s.erase(x);cout<<dfs(1,1)<<'\n';
	}
	return 0;
}
