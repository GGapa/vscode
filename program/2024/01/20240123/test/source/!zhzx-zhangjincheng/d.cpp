#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int M=2e3+5,mod=998244353;
vector<int>vec;ll ans;
int n,m,k,p,t,all,a[M],x[M],y[M],z[M];
int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
bool check(int s){
	for (int i=0;i<m;i++)
		if ((s>>x[i]&1)&&(s>>y[i]&1))
			return 0;
	return 1; 
}
int qpow(int x,int n){
	int s=1;while (n){
		if (n&1) s=(ll)s*x%mod;
		x=(ll)x*x%mod;n>>=1;
	} return s;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read();m=read();k=read();p=read();t=read();
	for (int i=0;i<n;i++) a[i]=read();
	for (int i=0;i<m;i++) x[i]=read()-1,y[i]=read()-1,z[i]=read();
	for (int sta=0;sta<1<<n;sta++)
		if (check(sta)) vec.push_back(sta);
	for (int sta=0;sta<(1<<n+m);sta++){
		if (__builtin_popcount(sta)!=p) continue; all++;
		for (int i=0;i<n;i++) if (sta>>i&1) a[i]+=t;
		for (int i=0;i<m;i++) if (sta>>(i+n)&1) z[i]+=t; 
		for (auto t:vec){ ll sum=0;
			for (int i=0;i<n;i++) if (t>>i&1) sum+=a[i];
			for (int i=0;i<m;i++)
				if (!(t>>x[i]&1)&&!(t>>y[i]&1))
					sum+=z[i];
			sum%=mod; ans+=qpow(sum,k);
		}
		for (int i=0;i<n;i++) if (sta>>i&1) a[i]-=t;
		for (int i=0;i<m;i++) if (sta>>(i+n)&1) z[i]-=t;
	}
	printf("%d\n",ans%mod*qpow(all,mod-2)%mod);
	return 0;
}
