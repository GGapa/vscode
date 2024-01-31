#include <bits/stdc++.h>
using namespace std;
#define ll long long

int read(){
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
  return x*f;
}

void prt(ll x){
  int p[25],tmp=0;
  if(x==0) putchar('0');
  if(x<0) putchar('-'),x=-x;
  while(x) p[++tmp]=x%10,x/=10;
  for(int i=tmp;i>=1;i--) putchar(p[i]+'0');
  putchar('\n');
}

const ll mod=998244353;
const int N=1e5+5;
int n,m,a[N],_,mx;
ll f[N],ans=0;

ll qpow(ll a,ll b){
  ll res=1ll;
  while(b){if(b&1) res=res*a%mod;a=a*a%mod;b>>=1;}
  return res;
}
ll inv(ll a){return qpow(a,mod-2);}

ll mul(ll a,ll b){return a*b%mod;}

void solve(){
  mx=0;
  for(int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]);
  prt(f[mx]);
}

int main(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  n=read();m=read();_=read();
  f[m]=0;
  for(int i=m-1;i>=0;i--) f[i]=1ll*inv(m-i)*inv(m-i)%mod*mul(n-1,m)%mod*m%mod+f[i+1];
  while(_--) solve();
}