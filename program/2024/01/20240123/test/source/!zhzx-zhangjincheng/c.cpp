#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int M=5005,mod=998244353;
int n,m,t,inv,idx,a[M],b[M],f[M][M];
map<ull,int>mp;
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
int qpow(int x,int n){
	int s=1; while (n){
		if (n&1) s=(ll)s*x%mod;
		x=(ll)x*x%mod;n>>=1; 
	}  return s;
}
void dfs(int x,int sum,int mx){
	if (x>n){ if (sum) return ;ull Hash=0;
		for (int i=1;i<=n;i++) Hash=Hash*233+a[i];
		mp[Hash]=++idx;return ; 
	}
	for (int i=0;i<=mx&&i<=sum;i++)
		a[x]=i,dfs(x+1,sum-i,i);
}
void trans(int x,int sum,int mx){
	if (x>n){
		if (sum) return ;
		ull Hash=0;bool flag=0;
		for (int i=1;i<=n;i++) Hash=Hash*233+a[i];
		for (int i=1;i<=n;i++) flag|=a[i]==m;
		f[mp[Hash]][mp[Hash]]=1;
		if (flag) return ; f[mp[Hash]][idx+1]=1;
		for (int i=1;i<=n;i++) if (a[i]){
			for (int j=1;j<=n;j++){
				for (int k=1;k<=n;k++) b[k]=a[k];
				b[i]--;b[j]++;ull H=0;
				sort(b+1,b+n+1,greater<int>());
				for (int k=1;k<=n;k++) H=H*233+b[k];
				f[mp[Hash]][mp[H]]=(f[mp[Hash]][mp[H]]+mod-(ll)a[i]*(m-a[j])%mod*inv)%mod;
			}
		}	
		return ;
	}
	for (int i=0;i<=mx&&i<=sum;i++)
		a[x]=i,trans(x+1,sum-i,i);
}
void gauss(int n){
	for (int i=1;i<=n;i++){ int p;
		for (int j=i;j<=n;j++) if (f[j][i]) {p=j;break;}
		for (int j=1;j<=n;j++) swap(f[i][j],f[p][j]);
		int inv=qpow(f[i][i],mod-2);
		for (int j=1;j<=n+1;j++) f[i][j]=(ll)f[i][j]*inv%mod;
		for (int j=1;j<=n;j++)
			if (i!=j&&f[j][i]){
				int coef=f[j][i];
				for (int k=1;k<=n+1;k++)
					f[j][k]=(f[j][k]-(ll)coef*f[i][k]%mod+mod)%mod;
			}
	}
}
unordered_map<int,int>F[100005];
void Gauss(int n){
	for (int i=0;i<=n;i++){ int p;
		for (int j=i;j<=n;j++) if (F[j].count(i)) {p=j;break;}
		swap(F[i],F[p]); int inv=qpow(F[i][i],mod-2);
		for (auto &x:F[i]) x.second=(ll)x.second*inv%mod;
		for (int j=i+1;j<=min(i+5,n);j++)
			if (i!=j&&F[j].count(i)&&F[j][i]){
				int coef=F[j][i];
				for (auto &x:F[j]) x.second=(x.second-(ll)coef*F[i][x.first]%mod+mod)%mod;
			}
	}
	for (int i=n;~i;i--)
		for (auto &x:F[i])
			if (x.first!=i&&x.first!=n+1)
				F[i][n+1]=(F[i][n+1]-(ll)x.second*F[x.first][n+1]%mod+mod)%mod,x.second=0;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout); 
	n=read();m=read();t=read();
	inv=qpow((ll)m*(n-1)*m%mod,mod-2);
	if (n==2&&m>17){
		F[0][0]=F[m][m]=1;F[0][m+1]=F[m][m+1]=0;
		for (int i=1;i<m;i++)
			F[i][i-1]=mod-(ll)i*i%mod*inv%mod,
			F[i][i]=((ll)m*m-(ll)2*i*(m-i)%mod+mod)%mod*inv%mod,
			F[i][i+1]=mod-(ll)(m-i)*(m-i)%mod*inv%mod,
			F[i][m+1]=1;
		Gauss(m);
		while (t--){
			int x=read();read();
			printf("%d\n",F[min(x,m-x)][m+1]);
		}
		return 0;
	}
	dfs(1,m,m); trans(1,m,m); gauss(idx);
	while (t--){ 
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1,greater<int>());ull Hash=0;
		for (int i=1;i<=n;i++) Hash=Hash*233+a[i];
		printf("%d\n",f[mp[Hash]][idx+1]);
	}
	return 0;
}
