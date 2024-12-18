#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1001;
const ll P=1e9+7;
int n,n1,n2,m,q,t1,t2;
ll f[N][N],g[N][N];
bool h[N];
vector<int> a1[N],a2[N];
pair<int,int> b[N];
bool u;
void dfs(int x1,int x2,int w1,int w2)
{
    if(a1[x1].size()==1) dfs(a1[x1][0],x2,w1+1,w2);
    else if(a2[x2].size()==1) dfs(x1,a2[x2][0],w1,w2+1);
    else
    {
        if(a1[x1].size()!=a2[x2].size()||w1>w2)
        {
            u=true;
            return;
        }
        b[++q]=make_pair(w1,w2);
        for(int i=0;i<a1[x1].size();++i)
        {
            dfs(a1[x1][i],a2[x2][i],1,1);
        }
    }
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d%d",&n1,&n2);
    n=max(n1,n2);
    for(int i=2;i<=n1;++i)
    {
        int x;
        scanf("%d",&x);
        a1[x].push_back(i);
    }
    for(int i=2;i<=n2;++i)
    {
        int x;
        scanf("%d",&x);
        a2[x].push_back(i);
    }
    scanf("%d",&m);
    dfs(1,1,1,1);
    if(u)
    {
        for(int i=1;i<=m;++i)
        {
            printf("0\n");
        }
        return 0;
    }
    for(int i=1;i<=q;++i) t1=max(t1,b[i].first);
    for(int i=1;i<=q;++i) t2=max(t2,b[i].second);
    for(int i=1;i<=m;++i)
    {
        int x;
        scanf("%*d%d",&x);
        h[x]^=1;
        g[0][0]=1;
        for(int j=1;j<=t1;++j)
        {
            for(int k=0;k<=t2;++k) g[j][k]=0;
            for(int k=1;k<=t2;++k)
            {
                if(!h[k]) continue;
                for(int l=k;l<=t2;++l)
                {
                    g[j][l]+=g[j-1][l-k];
                    if(g[j][l]>=P) g[j][l]-=P;
                }
            }
        }
        ll s=1;
        for(int j=1;j<=q;++j)
        {
            s=s*g[b[j].first][b[j].second]%P;
        }
        printf("%lld\n",(s%P+P)%P);
    }
    return 0;
}