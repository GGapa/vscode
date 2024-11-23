#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
int n,x,id,T;
bool tf=true;
vector<int> E[100100];
int maxx[100100],a[100100],dp[100100],minn[100100],fath[100100];
bool check(int u,int value,int minsum) 
{
    int temp=a[u]-value;
    int sum=0;
    if(temp>minsum) return false;
    for(int to: E[u]) 
        if(to!=fath[u]) sum+=max(0ll,a[to]-value);
    return sum<=temp;
}
void dfs_min(int u,int fa) 
{
    int ll=-INF,rr=a[u],ans=0;
    int min_sum=(E[u].size()==1&&u!=1) ? INF: 0;
    for(int to: E[u]) 
    {
        if(to!=fa) 
        {
            dfs_min(to,u);
            ll=max(ll,minn[to]);
            min_sum+=a[to]-minn[to];
        }
    }
    while(ll<=rr) 
    {
        int mid=(ll+rr)/2;
        if(check(u,mid,min_sum)) ans=mid,rr=mid-1;
        else ll=mid+1;
    }
    minn[u]=ans;
}
void dfs_max(int u,int fa) 
{
    maxx[u]=a[u];
    int maxs=-INF;  
    for(int to: E[u]) 
    {
        if(to!=fa) 
        {
            dfs_max(to,u);
            dp[u]+=dp[to];
            maxs=max(maxs,maxx[to]);
        }
    }
    if((maxs>a[u]&&a[u]<=0)||(a[u]<dp[u]&&a[u]>=0)) tf=false;
    dp[u]=max(dp[u],a[u]);
    maxx[u]=max(maxx[u],a[u]);
}
void solve() 
{
    cin>>n;
    tf=true;
    for(int i=0;i<=n;i++) E[i].clear();
    for(int i=2;i<=n;i++) cin>>x,E[i].emplace_back(x),E[x].emplace_back(i),fath[i]=x;
    for(int i=1;i<=n;i++) cin>>a[i],minn[i]=maxx[i]=-INF,dp[i]=0;
    dfs_max(1,0),dfs_min(1,0);
    if(tf&&minn[1]<=0) cout<<"Huoyu\n";
    else cout<<"Shuiniao\n";
}
signed main() 
{
//    freopen("water7.in","r",stdin);
//    freopen("water.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>id>>T;
    while(T--) solve();
    return 0;
}