#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e3+10,M=1e5+10;
const int mod=998244353;
LL qpow(LL a,LL b){
	LL sum=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) sum=sum*a%mod;
	return sum;
}
LL inv(LL a){return qpow(a,mod-2);}
int n,m,a[N];
namespace sub1{
	LL A[1010][1010],f[10010],g[10010];
	void gaosi(){
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++){
				if(i==j) continue;
				LL _=A[j][i]*inv(A[i][i])%mod;
				for(int k=0;k<=m+1;k++){
					A[j][k]=(A[j][k]-_*A[i][k]%mod)%mod;
				}
			}
		}
	}
	void init(){
		for(int i=0;i<=m;i++) for(int j=0;j<=m+1;j++) A[i][j]=0;
		for(int j=0;j<m;j++){
			LL p1=j*inv(m)%mod,p2=(m-j)*inv(1LL*n*m%mod-m)%mod;
			if(j!=0)A[j][j-1]=p1*(1-p2)%mod;
			if(j!=m)A[j][j+1]=(1-p1)*p2%mod;
			A[j][j]=(p1*p2%mod+(1-p1)*(1-p2)%mod-1)%mod;
			A[j][m+1]=mod-1;
		}
		A[m][m]=1;
		A[m][m+1]=0;
		gaosi();
		for(int i=0;i<=m;i++) f[i]=A[i][m+1]*inv(A[i][i])%mod;
		
		for(int i=0;i<=m;i++) for(int j=0;j<=m+1;j++) A[i][j]=0;
		for(int j=1;j<m;j++){
			LL p1=j*inv(m)%mod,p2=(m-j)*inv(1LL*n*m%mod-m)%mod;
			if(j!=0)A[j][j-1]=p1*(1-p2)%mod;
			if(j!=m)A[j][j+1]=(1-p1)*p2%mod;
			A[j][j]=(p1*p2%mod+(1-p1)*(1-p2)%mod-1)%mod;
			A[j][m+1]=0;
		}
		A[m][m]=1;  A[0][0]=1;
		A[m][m+1]=1;A[0][m+1]=0;
//		for(int i=0;i<=m;i++){for(int j=0;j<=m+1;j++) cout<<(A[i][j]+mod)%mod<<' ';cout<<'\n';}
		gaosi();
		
		for(int i=0;i<=m;i++) g[i]=A[i][m+1]*inv(A[i][i])%mod;//,cout<<g[i]<<'\n';
	}
	void work(){
//		for(int i=0;i<=m;i++) cout<<g[i]<<' '<<f[i]<<'\n';
		LL ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=(ans+g[a[i]]*f[a[i]]%mod)%mod;
		}
		cout<<(ans+mod)%mod<<'\n';
	}
	void main(){
		init();
		int T;
		cin>>T;
		while(T--) work();
		
	}
}
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>m;
	sub1::main();
	return 0; 
}
