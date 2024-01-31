#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005,Mod=998244353;
LL N,t,A[maxn];
LL M;
LL F[maxn];
struct YYZ{
	LL k,b;
	YYZ operator *(const LL B)const{return (YYZ){k*B%Mod,b*B%Mod};}
}G[maxn];
LL QSM(LL x,LL y){
	LL ret=1;x%=Mod;
	while(y){
		if(y&1) ret=ret*x%Mod;
		x=x*x%Mod;y>>=1;
	}
	return ret;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>N>>M>>t;
	for(long long i=1;i<M;i++){
		YYZ Now=G[i-1]*(i*i%Mod*QSM(M*M,Mod-2)%Mod);
		Now.b++;
		LL cur=((1-Now.k-1ll*2*i*(M-i)%Mod*QSM(M*M,Mod-2)%Mod)%Mod+Mod)%Mod;cur=QSM(cur,Mod-2);
		G[i]=(YYZ){1ll*(M-i)*(M-i)%Mod*QSM(M*M,Mod-2)%Mod*cur%Mod,Now.b*cur%Mod};
	}
	for(int i=M-1;i>=1;i--){
		F[i]=(G[i].k*F[i+1]+G[i].b)%Mod;
	}
	while(t--){
		for(int i=1;i<=N;i++) cin>>A[i];
		printf("%lld\n",F[A[1]]);
	}
	return 0;
}
