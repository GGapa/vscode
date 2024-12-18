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
	LL A[10010][5],f[10010],g[10010];
	void gaosi(){
		for(int i=0;i<=m;i++){
			A[i-1][1]=(A[i-1][1]-inv(A[i][1])*A[i-1][2]%mod*A[i][0])%mod;
			A[i-1][3]=(A[i-1][3]-inv(A[i][1])*A[i-1][2]%mod*A[i][3])%mod;
			A[i-1][2]=0;
			A[i+1][1]=(A[i+1][1]-inv(A[i][1])*A[i+1][0]%mod*A[i][2])%mod;
			A[i+1][3]=(A[i+1][3]-inv(A[i][1])*A[i+1][0]%mod*A[i][3])%mod;
			A[i+1][0]=0;
		}
	}
	void init(){
		for(int i=0;i<=m;i++) for(int j=0;j<=3;j++) A[i][j]=0;
		for(int j=1;j<m;j++){
			LL p1=j*inv(m)%mod,p2=(m-j)*inv(1LL*n*m%mod-m)%mod;
			if(j!=0)A[j][0]=p1*(1-p2)%mod;
			if(j!=m)A[j][2]=(1-p1)*p2%mod;
			A[j][1]=(p1*p2%mod+(1-p1)*(1-p2)%mod-1)%mod;
			A[j][3]=mod-1;
		}
		A[m][1]=1;  A[0][1]=1;
		A[m][3]=0;	A[0][3]=0;
		gaosi();
		for(int i=0;i<=m;i++) f[i]=A[i][3]*inv(A[i][1])%mod;
	}
	void work(){
		LL ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<(f[a[1]]+mod)%mod<<'\n';
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
	if(n==2)sub1::main();
	return 0; 
}
