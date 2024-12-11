#include<bits/stdc++.h>
using namespace std;
const int maxn=805,mod=1e9+7;
int G[105][maxn],bk[maxn][maxn],f[105][maxn],n1,n2,q,pd=0,vis[maxn],in[maxn],t[maxn],ans[maxn][maxn],tt[maxn];
vector<int> e[maxn];
vector<int> g[maxn];
void dfs(int x1,int x2)
{
    int now=x1,len=1,now2=x2,len2=1;
    while(e[now].size()==1)
    {
        now=e[now][0];
        ++len;
    }
    // cout<<g[x2].size()<<'\n';
    while(g[now2].size()==1)
    {
        now2=g[now2][0];
        ++len2;
    } 
    // cout<<x1<<' '<<x2<<' '<<len<<' '<<len2<<' '<<g[x2].size()<<'\n';
    x1=now,x2=now2;
    in[len]=1;
    ++bk[len][len2];
    if(e[x1].size()!=g[x2].size())
    {
        pd=1;
        // cout<<x1<<' '<<x2<<'\n';
        return;
    }
    for(int i=0;i<e[x1].size();i++)
        dfs(e[x1][i],g[x2][i]);
} 
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n1>>n2;
    for(int i=2;i<=n1;i++)
    {
        int fa;
        cin>>fa;
        e[fa].push_back(i);
    }
    for(int i=2;i<=n2;i++)
    {
        int fa;
        cin>>fa; 
        g[fa].push_back(i);
    }
    dfs(1,1);
    f[0][0]=1;
    cin>>q; 
    for(int i=1;i<=q;i++)
    {
        int op,x;
        cin>>op>>x;
        if(pd)
        {
            cout<<0<<'\n';
            continue;
        }
        if(op==1)
            t[++t[0]]=x;
        else
        {
            for(int i=1;i<=t[0];i++)
                if(t[i]==x)
                {
                    swap(t[i],t[t[0]]);
                    --t[0];
                    break;
                }
        } 
        memset(f,0,sizeof(f));
        memset(G,0,sizeof(G));
        memset(ans,0,sizeof(ans));
        int K=55;
        f[0][0]=1;
        sort(t+1,t+t[0]+1);
        for(int i=1;i<=K;i++)
            for(int j=i;j<=n2;j++)
                for(int k=1;k<=t[0];k++)
                    if(t[k]<=j)
                        f[i][j]=(f[i][j]+f[i-1][j-t[k]])%mod;
                    else
                        break;
        for(int j=1;j<=n2;j++) 
            G[1][j]=f[K][j];  
        // cerr<<"###"<<clock()<<'\n';
        for(int i=2;i<=n1/K;i++)
            for(int j=i*K;j<=n2;j++)
                for(int k=K;k<=j-(i-1)*K;k++)
                    G[i][j]=(G[i][j]+1ll*G[i-1][j-k]*G[1][k]%mod)%mod;
        // cerr<<clock()<<'\n';
        for(int i=1;i<=n1;i++)
        {
            tt[i]=0;
            if(i%K==0)
            {
                tt[i]=1;
                for(int k=1;k<=n2;k++)
                {
                    ans[i][k]=G[i/K][k];
                }
            }
        }
        tt[1]=1;
        for(int k=1;k<=t[0];k++)
            ans[1][t[k]]=1;
        int s=1;
        for(int i=1;i<=n1;i++)
        {
            if(in[i])
            {
                for(int j=i;j>=1;j--)
                {
                    if(tt[j]==1)
                    {
                        for(int k=j+1;k<=i;tt[k]=1,k++)
                            for(int l=k;l<=n2;l++)
                                for(int p=1;p<=t[0];p++)
                                    if(t[p]<=l) 
                                        ans[k][l]=(ans[k][l]+ans[k-1][l-t[p]])%mod; 
                                    else
                                        break;
                        break;
                    }
                }
                for(int j=1;j<=n2;j++) 
                    for(int k=1;k<=bk[i][j];k++) 
                        s=1ll*s*ans[i][j]%mod;  
            }
        }
        cout<<s<<'\n';
    } 
    return 0;
}