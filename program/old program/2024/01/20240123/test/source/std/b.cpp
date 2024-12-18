#include<bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
template<typename T>void readmain(T &x){
    bool neg=false;unsigned int c=getchar();
    for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
    for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
    if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1005,mod=1e9+7;
int n,Q,ppp;
vector<int> S;
map<vector<int> ,int> mp;
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
struct TREE{
    int n,m,fa[N],Fa[N],num[N],has[N],id[N];
    vector<int> G[N],ha[N];
    void dfs(int u,int ffa){
        ++m;Fa[m]=ffa;num[m]=1;
        for(;(int)G[u].size()==1;u=G[u][0],num[m]++);
        id[u]=m;
        for(int v:G[u])dfs(v,id[u]);
    }
    void solve(){
        for(int i=2;i<=n;i++){
            read(fa[i]);
            G[fa[i]].pb(i);
        }
        dfs(1,0);
        if(!ppp)ppp=m;
        for(int i=m;i>=1;i--){
            ha[i].pb(i);
            if(!mp[ha[i]])mp[ha[i]]=++ppp;
            has[i]=mp[ha[i]];
            if(Fa[i])ha[Fa[i]].pb(has[i]);
        }
    }
}t1,t2;
struct node{
    int a[N];
    node(){memset(a,0,sizeof(a));}
}bas;
node MMUL(node x,node y,int z){
    node res;
    for(int i=0;i<z;i++)
        for(int j=0;j+i<z;j++)res.a[i+j]=(res.a[i+j]+(ll)x.a[i]*y.a[j])%mod;
    return res;
}
int power(node a,int b,int p){
    node res;res.a[0]=1;
    while(b){
        if(b&1)res=MMUL(res,a,p+1);
        a=MMUL(a,a,p+1);
        b>>=1;
    }
    return res.a[p];
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    read(t1.n,t2.n);
    t1.solve();t2.solve();
    bool same=(t1.m==t2.m);
    for(int i=t1.m;i>=1&&same;i--)same&=(t1.has[i]==t2.has[i]&&t1.num[i]<=t2.num[i]);
    read(Q);n=max(t1.n,t2.n);
    while(Q--){
        int op,x;read(op,x);
        if(!same){
            puts("0");
            continue;
        }
        if(op==1)bas.a[x]=1;
        else bas.a[x]=0;
        int res=1;
        for(int i=1;i<=t1.m;i++)res=(ll)res*power(bas,t1.num[i],t2.num[i])%mod;
        printf("%d\n",res);
    }
    fprintf(stderr,"\n %ld ms.\n",clock()*1000/CLOCKS_PER_SEC);
    return 0;
}
