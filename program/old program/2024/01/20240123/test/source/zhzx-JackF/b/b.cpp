#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
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
//	puts("g.f");
//	rep(i,0,g.n)if(g.f[i])printf("%d ",i);puts("");
	ans.f[0]=1;
	for(;l1;l1>>=1,g=g*g)if(l1&1)ans=ans*g;
	return ans.f[l2];
}
inline int dfs(int x,int y){
//	printf("dfs(x=%d y=%d)\n", x, y);
	int len1=1,len2=1;
	while(d1[x]==1)x=T1[x][0],++len1;
	while(d2[y]==1)y=T2[y][0],++len2;
	if(d1[x]!=d2[y])return 0;
//	printf("len1=%d len2=%d\n",len1,len2);
	int coef=calcf(len1,len2);
	const int z=d1[x];
	rep(i,0,z-1)coef=(ll)coef*dfs(T1[x][i],T2[y][i])%mod;
	return coef;
}
inline void solve(){
//	vector<int>vec;
//	for(auto x:s)vec.emplace_back(x);
//	const int z=vec.size();
//	f[0][0]=1;
//	rep(i,1,n1){
//		memset(f[i],0,sizeof(int)*(n2+1));
//		int*F=f[i-1];
//		rep(j,0,z-1){
//			const int tmp=vec[j];
//			rep(k,tmp,n2){
//				const int v=F[k-tmp];
//				if(v)add(f[i][k],v);
//			}
//		}
//	}
	cout<<dfs(1,1)<<'\n';
}
//inline void add(int x){rep(i,1,n1)rep(j,x,n2)add(f[i][j],f[i-1][j-x])}
//inline void del(int x){per(i,n1,1)per(j,n2,x)add(f[i][j],mod-f[i-1][j-x]);}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n1>>n2;
	int n=max(n1,n2);
	rep(i,2,n1){int x;cin>>x,T1[x].emplace_back(i);}
	rep(i,2,n2){int x;cin>>x,T2[x].emplace_back(i);}
	rep(i,1,n1)d1[i]=T1[i].size();
	rep(i,1,n2)d2[i]=T2[i].size();
	cin>>q;
	f[0][0]=1;
	while(q--){
		int op,x;cin>>op>>x;
		if(op&1)s.insert(x);
		else s.erase(x);solve();
	}
	return 0;
}
