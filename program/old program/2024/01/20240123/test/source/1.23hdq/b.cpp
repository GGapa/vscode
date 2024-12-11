#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7,N=805;
#define pii pair<int,int>
#define fi first 
#define se second
struct node{
    int n,fa[N],ind[N],tot=0,d[N];
    vector<int>nbr[N];
    vector<pii >nbr2[N];
    void add(int cur,int fa){
        ind[++tot]=cur;
        nbr2[fa].push_back({tot,d[cur]-d[ind[fa]]});
    }
    void dfs(int cur,int fa){
        if(nbr[cur].size()!=1){
            add(cur,fa);
            fa=tot;
        }
        for(auto to:nbr[cur]){
            d[to]=d[cur]+1;
            dfs(to,fa);
        }
    }
}t1,t2;
void NO(){
    int q;
    cin>>q;
    while(q--)cout<<0<<'\n';
    exit(0);
}
int dp[N][N],f[N][N];
bool vis[N];
int doit(int n,int m){
    for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)dp[i][j]=f[i][j]=0;
    for(int i=1;i<=m;++i)if(vis[i])dp[1][i]=1;
    f[0][0]=1;
    int cnt1=1,cnt2=0;
    int o=n;
    while(o){
        if(o&1){
            cnt2++;
            for(int i=0;i<=m;++i){
                for(int j=0;i+j<=m;++j){
                    f[cnt2][i+j]=(f[cnt2][i+j]+f[cnt2-1][i]*dp[cnt1][j])%mod;
                }
            }
        }
        cnt1++;
        for(int i=1;i<=m;++i){
            for(int j=1;i+j<=m;++j){
                dp[cnt1][i+j]=(dp[cnt1][i+j]+dp[cnt1-1][i]*dp[cnt1-1][j])%mod;
            }
        }
        o>>=1;
    }
    return f[cnt2][m];
}
pii p[N];
int num;
signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t1.n>>t2.n;
    for(int i=2;i<=t1.n;++i){
        cin>>t1.fa[i];
        t1.nbr[t1.fa[i]].push_back(i);
    }
    for(int i=2;i<=t2.n;++i){
        cin>>t2.fa[i];
        t2.nbr[t2.fa[i]].push_back(i);
    }
    t1.d[1]=t2.d[1]=1;
    t1.dfs(1,0);
    t2.dfs(1,0);
    if(t1.tot!=t2.tot)NO();
    int tot=t1.tot;
    for(int i=0;i<=tot;++i){
        if(t1.nbr[t1.ind[i]].size()!=t2.nbr[t2.ind[i]].size()||t1.nbr2[i].size()!=t2.nbr2[i].size()){
            NO();
        }
        for(int j=0;j<t1.nbr2[i].size();++j){
                auto x=t1.nbr2[i][j],y=t2.nbr2[i][j];
                if(x.fi!=y.fi){
                    NO();
                }
            }
    }
    int q;
    cin>>q;
    int n=max(t1.n,t2.n);
    for(int i=0;i<=tot;++i){
        for(int j=0;j<t1.nbr2[i].size();++j){
            auto x=t1.nbr2[i][j],y=t2.nbr2[i][j];
            p[++num]={x.se,y.se};
        }
    }
    while(q--){
        int opt,x;
        cin>>opt>>x;
        if(opt==1)vis[x]=1;
        else vis[x]=0;
        int ans=1;
        for(int i=1;i<=num;++i)ans=ans*doit(p[i].fi,p[i].se)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}   