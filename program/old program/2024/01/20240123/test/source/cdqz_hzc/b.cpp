#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=810,mod=1e9+7;
int a[N],b[N],cnt=-1,dp[N][N],fac[N],inv[N],maxx1,maxx2;
struct tree{
	int tot,n,first[N],nnext[N<<1],to[N<<1],siz[N];
	vector<int>v[N];
	ull mask;
	void add(int x,int y){
		nnext[++tot]=first[x];
		first[x]=tot;
		to[tot]=y;
	}
	int dfs(int u,int fa){
		int las;
		for(int e=first[u];e;e=nnext[e]){
			if(to[e]!=fa){
				las=dfs(to[e],u);
				if(!nnext[first[u]]){
					siz[u]=siz[to[e]]+1;
					return las;
				}
				else{
					siz[las]=siz[to[e]];
					v[u].push_back(las);
				}
			}
		}
		siz[u]=1;
		return u;
	}
	ull shift(ull x){
		x^=mask;
		x^=(x<<11);
		x^=(x>>45);
		x^=(x<<14);
		return x;
	}
	ull calc(int u){
		ull sum=1;
		for(auto i:v[u]){
			sum+=shift(calc(i));
		}
		return sum;
	}
}t1,t2;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*a*ans%mod;
		}
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void get(int u1,int u2){
	a[++cnt]=t1.siz[u1];
	b[cnt]=t2.siz[u2];
	maxx1=max(maxx1,a[cnt]);
	maxx2=max(maxx2,b[cnt]);
	assert(t1.v[u1].size()==t2.v[u2].size());
	for(int i=0;i<t1.v[u1].size();i++){
		get(t1.v[u1][i],t2.v[u2][i]);
	}
}
int cc(int n,int m){
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int q,a,ans,op,n,c,d;
	scanf("%d%d",&t1.n,&t2.n);
	n=max(t1.n,t2.n);
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	}
	for(int i=2;i<=t1.n;i++){
		scanf("%d",&a);
		t1.add(a,i);
	}
	for(int i=2;i<=t2.n;i++){
		scanf("%d",&a);
		t2.add(a,i);
	}
	scanf("%d",&q);
	t1.add(0,-1);
	t2.add(0,-1);
	c=t1.dfs(1,0);
	d=t2.dfs(1,0);
	t1.siz[c]=t1.siz[1];
	t2.siz[d]=t2.siz[1];
	t1.v[0].push_back(c);
	t2.v[0].push_back(d);
	if(t1.calc(0)!=t2.calc(0)){
		while(q--){
			printf("0\n");
		}
		return 0;
	}
	get(0,0);
	dp[0][0]=1;
	while(q--){
		ans=1;
		scanf("%d%d",&op,&a);
		if(op==1){
			for(int i=maxx1-1;i>=0;i--){
				for(int j=maxx2-1;j>=0;j--){
					if(!dp[i][j])continue;
					for(int k=1;k<=min(maxx1-i,(maxx2-j)/a);k++){
						dp[i+k][j+k*a]=1ll*(dp[i+k][j+k*a]+1ll*dp[i][j]*cc(i+k,k)%mod)%mod;
					}
				}
			}
		}
		else{
			for(int i=0;i<=maxx1-1;i++){
				for(int j=maxx2-1;j>=0;j--){
					if(!dp[i][j])continue;
					for(int k=1;k<=min(maxx1-i,(maxx2-j)/a);k++){
						dp[i+k][j+k*a]=1ll*(dp[i+k][j+k*a]-1ll*dp[i][j]*cc(i+k,k)%mod+mod)%mod;
					}
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			ans=1ll*ans*dp[::a[i]][b[i]]%mod;
			if(!ans){
				break;
			}
		}
		printf("%d\n",ans);
	}
}
