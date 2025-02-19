#include<bits/stdc++.h>
#define mid (l+r>>1)
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;
typedef long long ll;
const int N=1e6+5;
const ll mod=998244353;
struct node{
    ll kk,kb,bb,k,b,sum;
}s[N];
ll p,R;
int n,m;
ll qpow(ll x,ll y){
    ll ss=1;
    while(y){
        if(y&1)ss=ss*x%mod;
        x=x*x%mod;y>>=1;
    }return ss;
}
void due(int k,int l,int r,node z){
    s[k].kk=(s[k].kk*p+s[k].kk*z.kk%mod*R)%mod;
    s[k].kb=(s[k].kb*p+(s[k].k*z.kb+s[k].kb*z.kk)%mod*R)%mod;
    s[k].bb=(s[k].bb*p+(s[k].bb*z.kk+2*z.kb*s[k].b+z.bb)%mod*R)%mod; 
    s[k].k=(s[k].k*p+s[k].k*z.k%mod*R)%mod;
    s[k].b=(s[k].b*p+(s[k].b*z.k+z.b)%mod*R)%mod;
    s[k].sum=(s[k].sum*p+((r-l+1)*z.b+s[k].sum*z.k)%mod*R)%mod; 
}
void pushdown(int k,int l,int r){
    due(ls,l,mid,s[k]);due(rs,mid+1,r,s[k]);
    s[k]={1,0,0,1,0,s[k].sum};
}
void change(int k,int l,int r,int x,int y,node z){
    if(l>y||r<x)return;
    if(l>=x&&r<=y){
        due(k,l,r,z);
        return;
    }
    pushdown(k,l,r);
    change(ls,l,mid,x,y,z);
    change(rs,mid+1,r,x,y,z);
    s[k].sum=(s[ls].sum+s[rs].sum)%mod;
}
ll query(int k,int l,int r,int x,int y,int op){
    if(l>y||r<x)return 0;
    if(l>=x&&r<=y){
        if(op)return s[k].bb;
        else return s[k].sum;
    }
    pushdown(k,l,r);
    return (query(ls,l,mid,x,y,op)+query(rs,mid+1,r,x,y,op))%mod;
}
int main(){
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
    cin>>n>>m;
    p = 0;
    R=(mod+1-p)%mod;
    while(m--){
        int op,x,y,z;
        scanf("%d%d",&op,&x);
        if(op==1)scanf("%d%d",&y,&z),change(1,1,n,x,y,node{1,z,1ll*z*z%mod,1,z,0});
        else if(op==2)scanf("%d%d",&y,&z),change(1,1,n,x,y,node{0,0,1ll*z*z%mod,0,z,0});
        else if(op==3)scanf("%d%d",&y,&z),change(1,1,n,x,y,node{1ll*z*z%mod,0,0,z,0,0});
        else if(op==4)scanf("%d",&y),printf("%lld\n",query(1,1,n,x,y,0));
        else printf("%lld\n",query(1,1,n,x,x,1));
    }
    return 0;
}