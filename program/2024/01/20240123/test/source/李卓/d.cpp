#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
using namespace std;
const int mod=998244353,mx=4005;
int n,m,p,k,t,a[mx],tot,ans,nxt[mx],ver[mx],head[mx],fac[mx],inv[mx];
bool vis[mx];
struct edge{
	int x,y,z;
} e[mx];
int read(){
	int num=0,w=1;char c;
	while(1){
		c=getchar();
		if((c=='-')||(c>='0'&&c<='9')) break;
	}
	if(c=='-') w=-1;
	else num=c-'0';
	while(1){
		c=getchar();
		if(!(c>='0'&&c<='9')) break;
		num=num*10+c-'0';
	}
	return num*w;
}
int qpow(int x,int y){
	int s=x;x=1;
	while(y){
		if(y&1) x=x*s%mod;
		s=s*s%mod;y>>=1;
	}
	return x;
}
void dfs(int x,int cnt){
//	cout<<x<<" "<<cnt<<endl;
	if(x==n+m+1){
		if(cnt<p)
			return ;
//		cout<<x<<" "<<cnt<<endl;
		for(int i=0;i<(1<<n);++i){
			bool ok=1;int now=0;
			for(int j=1;j<=n;++j)
				vis[j]=0;
			for(int j=1;j<=n;++j)
				if((i>>(j-1))&1)
					vis[j]=1,now=(now+a[j])%mod;
			for(int j=1;j<=m;++j){
				if(e[j].x&&e[j].y)
					ok=0;
				else if(!e[j].x&&!e[j].y)
					now=(now+e[j].z)%mod;
			}
			if(!ok)
				continue;
			now=qpow(now,k);
			ans=(ans+now)%mod; 
		}
		return ;
	}
	if(cnt==p)
		dfs(x+1,cnt);
	else{
		x<=n?a[x]+=t:e[x-n].z+=t;
		dfs(x+1,cnt+1);
		x<=n?a[x]-=t:e[x-n].z-=t;
		dfs(x+1,cnt);
	}
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n+m;++i)
		fac[i]=fac[i-1]*i%mod;
	inv[n+m]=qpow(fac[n+m],mod-2);
	for(int i=n+m-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read();m=read();k=read();p=read();t=read();
	init();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=m;++i)
		e[i].x=read(),e[i].y=read(),e[i].z=read();
	dfs(1,0);
	ans=ans*qpow(C(n+m,p),mod-2)%mod;
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
