#define NDEBUG
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int mod=1000000007;
void modp(int&x){
	x>=mod&&(x-=mod);
}
constexpr int max_n=800;
vector<int>vec[max_n+1],arr;
vector<int>ga[max_n+1],gb[max_n+1];
int para[max_n+1],parb[max_n+1];
int mx[max_n+1];
bool dfsa(int ua,int ub){
//	fprintf(stderr,"dfsa %d %d\n",ua,ub);
	int cnta=1,cntb=1;
	for(; ga[ua].size()==1; ++cnta,ua=ga[ua][0]);
	for(; gb[ub].size()==1; ++cntb,ub=gb[ub][0]);
//	fprintf(stderr," %d(%d %zd) %d(%d %zd)\n",ua,cnta,ga[ua].size(),ub,cntb,gb[ub].size());
	if(ga[ua].size()!=gb[ub].size()||cnta>cntb)
		return 1;
	vec[cnta].emplace_back(cntb-cnta);
	for(int i=0,ed=ga[ua].size(); i<ed; ++i)
		if(dfsa(ga[ua][i],gb[ub][i]))
			return 1;
	return 0;
}
int f[10][max_n+1];
int fa[max_n+1];
int h[2][max_n+1];
void solve(){
//	fprintf(stderr,"solve\n");
	int cnt=-1;
	for(int i=0,ed=mx[1]; i<=ed; ++i)
		if(f[0][i])
//			fprintf(stderr,"%d: %d\n",cnt+1,i),
			fa[++cnt]=i;
	int mxa=0,now=1;
	memcpy(h[0],f[0],sizeof(h[0]));
	int*hnow=h[0],*hprv=h[1];
	ll ans=1;
	for(const int&x:arr){
		if(x==now){
			for(const int&y:vec[x])
//				fprintf(stderr,"(%d, %d): %d\n",x,y,hnow[y]),
				ans=ans*hnow[y]%mod;
			continue;
		}
//		fprintf(stderr,"%d: %d\n",x,mx[x]);
		const int n=mx[x];
		for(; cnt>=0&&fa[cnt]>n; --cnt);
//		for(int i=0; i<=cnt; ++i)
//			fprintf(stderr,"fa %d: %d\n",i,fa[i]);
		while(now<x){
//			fprintf(stderr,"now: %d\n",now);
//			for(int i=0; i<=n; ++i)
//				if(hnow[i])
//					fprintf(stderr,"hnow[%d]: %d\n",i,hnow[i]);
			swap(hprv,hnow);
			memset(hnow,0,(n+1)<<2);
			for(int i=0; i<=n; ++i){
				const int v=hprv[i];
				for(int j=0; j<=cnt; ++j)
					modp(hnow[i+fa[j]]+=v);
			}
			++now;
		}
		for(const int&y:vec[x])
//			fprintf(stderr,"(%d, %d): %d\n",x,y,hnow[y]),
			ans=ans*hnow[y]%mod;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int na,nb,q;
	scanf("%d%d",&na,&nb);
	vec[1].clear();
	for(int i=2; i<=na; ++i){
		scanf("%d",para+i);
		ga[para[i]].emplace_back(i),vec[i].clear();
	}
	for(int i=2; i<=nb; ++i){
		scanf("%d",parb+i);
		gb[parb[i]].emplace_back(i);
	}
	scanf("%d",&q);
	if(dfsa(1,1)){
//		fprintf(stderr,"asdf\n");
		for(int i=1; i<=q; ++i)
			puts("0");
		return 0;
	}
	int now=-1;
	for(int i=na; i; --i){
		sort(vec[i].begin(),vec[i].end());
		vec[i].shrink_to_fit();
		if(!vec[i].empty()){
			if(vec[i].back()>now)
				now=vec[i].back();
		}
		mx[i]=now;
	}
	arr.clear();
	for(int i=1; i<=na; ++i)
		if(!vec[i].empty())
			arr.emplace_back(i);
	memset(f[0],0,sizeof(f[0]));
	for(int i=1,op,x; i<=q; ++i){
		scanf("%d%d",&op,&x);
//		fprintf(stderr,"%d %d\n",op,x-1);
		if(op==1)
			f[0][x-1]=1;
		else
			f[0][x-1]=0;
		solve();
	}
	return 0;
}
