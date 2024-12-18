#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int mod=998244353;
constexpr int max_n=900,max_k=30,max_p=30;
void modma(int&x,const ll&y,const int&z){
	x=(x+y*z)%mod;
}
void modp(int&x){
	x>=mod&&(x-=mod);
}
ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int k;
int fac[max_n+1],ifac[max_n+1];
void init_fac(const int n){
	ll now=fac[0]=1;
	for(int i=1; i<=n; ++i)
		fac[i]=now=now*i%mod;
	ifac[n]=now=quickpow(now,mod-2);
	for(int i=n; i; ifac[--i]=now)
		now=now*i%mod;
}
struct node{
	private:
	int f[max_k+1];
	public:
	void init0(){
		for(int i=0; i<=k; ++i)
			f[i]=0;
	}
	void init(){
		f[0]=1;
		for(int i=1; i<=k; ++i)
			f[i]=0;
	}
	void init(const int v){
		f[0]=1;
		ll now=v;
		for(int i=1; i<=k; ++i,now=now*v%mod)
			f[i]=now*ifac[i]%mod;
	}
	friend node operator*(const node&x,const node&y){
		node res;
		memset(res.f,0,(k+1)<<2);
		for(int i=0; i<=k; ++i)
			for(int j=k-i; j>=0; --j)
				modma(res.f[i+j],x.f[i],y.f[j]);
		return res;
	}
	friend node operator+(const node&x,const node&y){
		node res;
		for(int i=0; i<=k; ++i)
			modp(res.f[i]=x.f[i]+y.f[i]);
		return res;
	}
	node&operator+=(const node&y){
		for(int i=0; i<=k; ++i)
			modp(f[i]+=y.f[i]);
		return *this;
	}
	int query(const int p){
		return f[p];
	}
};
int m,dif;
struct val_t{
	node v[max_p+1];
	int siz;
	void init(){
		siz=bool(m);
		v[0].init(),v[1].init();
	}
	void init(int val){
		siz=bool(m);
		v[0].init(val);
		modp(val+=dif);
		v[1].init(val);
	}
	friend val_t operator*(const val_t&x,const val_t&y){
		val_t res;
		res.siz=min(x.siz+y.siz,m);
		for(int i=res.siz; i>=0; --i){
			int a=max(i-y.siz,0);
			int b=i-a;
			res.v[i]=x.v[a]*y.v[b];
			while(++a<=x.siz&&--b>=0)
				res.v[i]+=x.v[a]*y.v[b];
		}
		return res;
	}
	friend val_t operator+(const val_t&x,const val_t&y){
		val_t res;
		if(x.siz<=y.siz){
			res.siz=y.siz;
			for(int i=0; i<=x.siz; ++i)
				res.v[i]=x.v[i]+y.v[i];
			for(int i=x.siz+1; i<=y.siz; ++i)
				res.v[i]=y.v[i];
		}
		else{
			res.siz=x.siz;
			for(int i=0; i<=y.siz; ++i)
				res.v[i]=x.v[i]+y.v[i];
			for(int i=y.siz+1; i<=x.siz; ++i)
				res.v[i]=x.v[i];
		}
		return res;
	}
	val_t&operator+=(const val_t&y){
		for(; siz<y.siz; v[++siz].init0());
		for(int i=0; i<=y.siz; ++i)
			v[i]+=y.v[i];
		return *this;
	}
	node query(const int p){
		return v[p];
	}
};
vector<pii>g[max_n+1];
int a[max_n+1];
val_t f[max_n+1][2];
vector<vector<pii> >arr[max_n+1];
int par[max_n+1],vpar[max_n+1],dep[max_n+1];
val_t empval,empval2,empval4;
val_t solve(const pii*l,const pii*const r){
	if(l==r){
		val_t res;
		res.init(l->second);
		return res;
	}
//	for(const pii*i=l; i<=r; ++i)
//		fprintf(stderr,"(%d, %d)\n",i->first,i->second);
	val_t res[2];
	res[0].init(l->second);
	res[0]=res[0]*empval;
	res[1].init(a[(l+1)->first]);
	res[1]=res[1]*empval;
	while(++l!=r){
		val_t nod,edg;
		nod.init(a[(l+1)->first]);
		edg.init(l->second);
		val_t tmp=empval*res[0];
		res[0]=empval2*res[1]+tmp*edg;
		res[1]=tmp*nod;
	}
	val_t edg;
	edg.init(r->second);
	return (res[0]*edg+res[1]*empval);
}
int dfsa(const int u,const int p=0){
	par[u]=p,dep[u]=dep[p]+1;
//	fprintf(stderr,"dfsa %d(%d %d)\n",u,p,dep[u]);
	f[u][0]=empval;
	f[u][1].init(a[u]);
	arr[u].clear();
	int mnlp=0;
	for(const pii&edg:g[u])
		if(edg.first!=p){
			if(dep[edg.first]){
				if(dep[edg.first]<dep[u]){
					vector<pii>comp;
					comp.emplace_back(edg);
					for(int x=u; x!=edg.first; x=par[x])
						comp.emplace_back(x,vpar[x]);
					arr[edg.first].emplace_back(comp);
					mnlp=edg.first;
				}
				continue;
			}
			vpar[edg.first]=edg.second;
			const int resv=dfsa(edg.first,u);
			if(!resv){
				val_t e;
				e.init(edg.second);
				f[u][0]=f[u][0]*(empval*f[edg.first][1]+e*f[edg.first][0]);
				f[u][1]=f[u][1]*empval*f[edg.first][0];
			}
			else
				if(resv!=u)
					mnlp=resv;
		}
	for(const vector<pii>&arrv:arr[u]){
		f[u][1]=f[u][1]*empval4*solve(arrv.data()+1,arrv.data()+arrv.size()-2);
		f[u][0]=f[u][0]*solve(arrv.data(),arrv.data()+arrv.size()-1);
	}
	return mnlp;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int n,m,k,p,t;
	scanf("%d%d%d%d%d",&n,&m,&k,&p,&t);
	init_fac(max(n+m,k)),::k=k,::m=p,::dif=t;
	empval.init();
	empval2=empval*empval;
	empval4=empval2*empval2;
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i),dep[i]=0;
	for(int i=1,u,v,w; i<=m; ++i){
		scanf("%d%d%d",&u,&v,&w);
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	dep[0]=0;
	dfsa(1);
	ll ans=f[1][0].query(p).query(k)+f[1][1].query(p).query(k);
	ans=ans*fac[k]%mod*fac[p]%mod*fac[n+m-p]%mod*ifac[n+m]%mod;
	printf("%lld\n",ans);
	return 0;
}
