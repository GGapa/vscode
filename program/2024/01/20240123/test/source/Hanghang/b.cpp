#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=803,H=1e9+7;
struct Tree
{
    ll n,fa[N],sz[N];
    vector<ll>ve[N];
    void Work()
    {
        for(int i=2;i<=n;i++)cin>>fa[i],ve[fa[i]].push_back(i);
        for(int i=n;i>0;i--)
        {
            sz[i]=1;sort(ve[i].begin(),ve[i].end());
            for(int x:ve[i])sz[i]+=sz[x];
        }
    }
}A,B;
set<int>q;
map<pair<int,int>,ll>mp;
ll Dfs(ll x,ll y)
{
    if(A.sz[x]>B.sz[y])return 0;
    if(mp.count({x,y}))return mp[{x,y}];
    ll las=1,ans=0,z=y;
    for(auto it:q)
    {
        int fl=1;
        for(int i=las+1;i<=it;i++)
        {
            if(B.ve[z].size()!=1){fl=0;break;}
            z=B.ve[z][0];
        }
        if(!fl)break;
        ll s=1;las=it;
        if(A.ve[x].size()!=B.ve[z].size())continue;
        for(int i=0;i<(int)A.ve[x].size()&&s;i++)s=s*Dfs(A.ve[x][i],B.ve[z][i])%H;
        ans=(ans+s)%H;
    }
    return mp[{x,y}]=ans;
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin>>A.n>>B.n;A.Work();B.Work();
    int T;cin>>T;
    while(T--)
    {
        int op,x;cin>>op>>x;
        if(op==1)q.insert(x);
        else q.erase(x);
        mp.clear();cout<<Dfs(1,1)<<endl;
    }
}