#include<bits/stdc++.h>
#define db double
#define int ll
#define ll long long
#define ull unsigned long long
#define pb emplace_back
#define MP make_pair
#define pii pair<int, int>
#define vec vector<int>
#define fi first
#define se second
#define ls k<<1
#define rs k<<1|1
#define CLK (double)clock()/(double)CLOCKS_PER_SEC
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(register int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int N=805,M=105,mod=1e9+7;
int n1,n2,B,m,h,sum,f[N][N],g[N][N],C[N][N],flg=1;vector<pii> Q;
vec T1[N],T2[N];vec S,T;
inline void add(int &x,int y){(x+=y)%=mod;}
inline void dfs(int x,int y){
    int s1=1,s2=1;
    while(T1[x].size()==1)s1++,x=T1[x][0];
    while(T2[y].size()==1)s2++,y=T2[y][0];
    Q.pb(MP(s1,s2)),h=max(h,max(s1,s2));
    if(T1[x].size()!=T2[y].size())return flg=0,void();
    for(int i=0;i<T1[x].size();i++)
        dfs(T1[x][i],T2[y][i]);
}
inline void build(){
    memset(f,0,sizeof f),memset(g,0,sizeof g);
    f[0][0]=g[0][0]=1;
    for(int i=1;i<=h;i++)for(int j=0;j<=n2;j++)if(f[i-1][j]){
        for(auto x:S)if(j+x<=n2)add(f[i][j+x],f[i-1][j]);
    }
    for(int i=1;i<=n2/B;i++)for(int j=0;j<=n2;j++)if(g[i-1][j]){
        for(auto x:T)if(j+x<=n2)add(g[i][j+x],g[i-1][j]);
    } 
}
map<pii,int> mp;
inline int count(int x,int y){
    if(mp.count(MP(x,y)))return mp[MP(x,y)];
    int res=0;
    for(int i=0;i<=min(x,n2/B);i++)for(int j=0;j<=y;j++)
        add(res,g[i][j]*f[x-i][y-j]%mod*C[x][i]%mod);
    return res;
}
void MAIN(){
    n1=read(),n2=read();B=20;
    for(int i=0;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    for(int i=2;i<=n1;i++)T1[read()].pb(i);
    for(int i=2;i<=n2;i++)T2[read()].pb(i);
    m=read();flg=1;dfs(1,1);
    if(!flg){for(int i=1;i<=m;i++)puts("0");return ;}
    while(m--){
        int op=read(),x=read();
        if(op==1){
            if(x<=B)S.pb(x);
            else T.pb(x);
        }
        else {
            if(x<=B)S.erase(find(S.begin(),S.end(),x));
            else T.erase(find(T.begin(),T.end(),x));
        }
        build();
        int ans=1;mp.clear();
        for(auto t:Q){
            int x=t.fi,y=t.se;
            ans=ans*count(x,y)%mod;
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    int T=1;while(T--)MAIN();
    // cerr<<"\nTIME: "<<(double)clock()/CLOCKS_PER_SEC<<"\n";
    return 0;
}
