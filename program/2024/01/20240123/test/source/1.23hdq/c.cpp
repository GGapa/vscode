#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,t,tot;
map<vector<int>,int>mp;
vector<int>vec,tmp[4005];
void dfs(int cur,int sum){
    if(cur==n){
        vec.push_back(m-sum);
        tmp[mp[vec]=++tot]=vec;
        vec.pop_back();
        return;
    }
    for(int i=0;i+sum<=m;++i){
        vec.push_back(i);
        dfs(cur+1,sum+i);
        vec.pop_back();
    }
}
int f[4005][4005];
int qpow(int a,int b){
    int ans=1,base=a;
    while(b){
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}
void gauss(){
    for(int i=1;i<=tot;++i){
        int maxn=i;
        for(int j=i+1;j<=tot;++j)if(f[j][i]>f[maxn][i])maxn=j;
        for(int j=1;j<=tot+1;++j)swap(f[i][j],f[maxn][j]);
        for(int j=1;j<=tot;++j){
            if(i==j)continue;
            int d=f[j][i]*qpow(f[i][i],mod-2)%mod;
            for(int k=1;k<=tot+1;++k)f[j][k]=(f[j][k]-d*f[i][k]%mod+mod)%mod;
        }
    }
}
signed main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>t;
    dfs(1,0);
    for(int i=1;i<=tot;++i){
        for(int j=0;j<n;++j){
            if(tmp[i][j]==0)continue;
            for(int k=0;k<n;++k){
                vector<int>o=tmp[i];
                o[j]--;o[k]++;
                f[mp[o]][i]=(f[mp[o]][i]-tmp[i][j]*qpow(m,mod-2)%mod*(m-tmp[i][k])%mod*qpow((n-1)*m%mod,mod-2)%mod+mod)%mod;
                f[mp[o]][tot+1]=(f[mp[o]][tot+1]+tmp[i][j]*qpow(m,mod-2)%mod*(m-tmp[i][k])%mod*qpow((n-1)*m%mod,mod-2)%mod)%mod;
            }
        }
        f[i][i]=(f[i][i]+1)%mod;
        // f[i][tot+1]=1;
    }
    for(int i=1;i<=tot;++i){
        bool vis=0;
        for(int j=0;j<n;++j)if(tmp[i][j]==m)vis=1;
        if(vis==1){
            for(int j=1;j<=tot+1;++j)f[i][j]=0;
            f[i][i]=1;f[i][tot+1]=0;
            continue;
        }
    }
    // for(int i=1;i<=tot;++i){
    //     for(int j=1;j<=tot+1;++j){
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    gauss();
    // cout<<"CHCK\n";
    // for(int i=1;i<=tot;++i){
    //     for(int j=1;j<=tot+1;++j){
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(t--){
        vector<int>now;
        for(int i=1;i<=n;++i){
            int x;
            cin>>x;
            now.push_back(x);
        }
        cout<<f[mp[now]][tot+1]*qpow(f[mp[now]][mp[now]],mod-2)%mod<<'\n';
    }
    return 0;
}