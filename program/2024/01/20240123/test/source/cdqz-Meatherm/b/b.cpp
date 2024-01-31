# include <bits/stdc++.h>

const int N=2010,INF=0x3f3f3f3f,mod=1e9+7;

inline int read(void){
	int res,f=1;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	res=c-48;
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-48;
	return res*f;
}


typedef std::vector <int> vei;

struct Tree{
	vei G[N];
	
	std::vector <std::pair <int,int> > H[N];
	
	int n,f[N];
	
	bool del[N];
	
	inline void read(void){
		for(int i=2;i<=n;++i) f[i]=::read(),G[f[i]].push_back(i);
		return;
	}
	
	void rebuild(int x){		
//		if(n==800) printf("rebuilding = %d\n",x);
		for(auto y:G[x]) rebuild(y);
		if(del[x]||x==1) return;
		del[x]=true;
		int y=f[x],len=2;
		while(f[y]&&G[y].size()==1) del[y]=true,y=f[y],++len;
//		printf("rebuilding = %d %d\n",x,y);
		H[y].push_back(std::make_pair(x,len));
		return;
	}
	
	
}A,B;

std::bitset <N> bs,b[N];

std::vector <int> va;

int q;

int f[N][N];

int mn;

inline void ins(int x){
	
	return;
	for(int i=1;i<=mn;++i){
		for(int j=x;j<=mn;++j) f[i][j]=(f[i][j]+f[i-1][j-x])%mod;//,printf("%d ",f[i][j]);
//		puts("");
	}
	
	for(int i=0;i<=mn;++i,puts("")) for(int j=0;j<=mn;++j) printf("%d ",f[i][j]);
	
	
	return;
}

inline void del(int x){
	
	return;
	for(int i=mn;i;--i){
		for(int j=x;j<=mn;++j) f[i][j]=(f[i][j]-f[i-1][j-x]+mod)%mod;
	}
	
	return;
}

inline void recalc(void){
	
	va.clear();
	
	for(int v=1;v<=mn;++v) if(bs[v]) va.push_back(v);
	
	for(int i=1;i<=mn;++i){
		for(int j=i;j<=mn;++j){
			f[i][j]=0;
			for(auto v:va){
				if(v>j) break;
				f[i][j]=(f[i][j]+f[i-1][j-v]+mod)%mod;
				
//				printf("i = %d j = %d v = %d\n",i,j,v);
			}
		}
	}
	
	
	return;
}

int calc(int u,int v){
	int sz=A.H[u].size(),ans=1;
	
	if(A.H[u].size()!=B.H[v].size()){
		if(u!=1||B.H[v].size()!=1) return 0; // u = 1 sz[u] > 1 sz[v] = 1 
		return 1ll*f[1][B.H[v][0].second]*calc(u,B.H[v][0].second)%mod;
	}
	
	
	
	for(int i=0;i<sz;++i){
		auto x=A.H[u][i],y=B.H[v][i];
		
		if(x.second>y.second) return puts("seg failed"),0;
		
		if(sz==1) ans=1ll*ans*f[x.second][y.second]%mod,printf("x = %d y = %d\n",x.second,y.second);
		else ans=1ll*ans*f[x.second-1][y.second-1]%mod;
		
		ans=1ll*ans*calc(x.first,y.first)%mod;
	}
	
	return ans;
}

int main(void){
	freopen("bx.in","r",stdin);
	
	f[0][0]=1;
	
	A.n=read(),B.n=read(),A.read(),B.read(),mn=std::max(A.n,B.n);
	
	A.rebuild(1),B.rebuild(1);
	
	b[0]=1;
	
	for(int i=1;i<=A.n;++i){
		for(auto v:A.H[i]) printf("(%d -> %d len = %d) ",i,v.first,v.second);
		puts("");
		
	}

	for(int i=1;i<=B.n;++i){
		for(auto v:B.H[i]) printf("(%d -> %d len = %d) ",i,v.first,v.second);
		puts("");
		
	}
	
//	calc(1,1);
//	return 0;
	
	
	q=read();
	
	while(q--){
		int op=read(),x=read();
		
		if(op==1) bs[x]=1,ins(x);
		else bs[x]=0,del(x);
		
		recalc();
		
//		for(int i=0;i<=mn;++i){
//			for(int j=0;j<=mn;++j) printf("%d ",f[i][j]);
//			puts("");
//		}
		
		printf("%d\n",calc(1,1));
	}



	return 0;
}
