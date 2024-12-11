#include<bits/stdc++.h>
#define LL long long
#define sl(s) strlen(s)
#define endline puts("")
#define pii pair<int , int>
#define pr_q priority_queue
#define debug puts("DEBUG.")
using namespace std;
const int N = 8e2 + 10;
const int inf = ~0u >> 2;
const int p = 1e9 + 7;
inline int getmod(int x)
    {return x >= p ? x - p : x;}
int n1,n2,m;
int fa1[N],fa2[N];
int tot1,tot2,deg1[N],deg2[N];
vector<int> F1[N],F2[N];
vector<int> G1[N],G2[N];
int siz1[N],siz2[N],dep[N],bel1[N],bel2[N];
void dfs1(int u , int t)
{
    dep[u] = dep[ fa1[u] ] + 1;
    if(deg1[u] != 1)
    {
        bel1[u] = ++tot1;
        if(t != 1)
            G1[ bel1[ fa1[t] ] ].push_back(tot1);
        siz1[tot1] = dep[u] - dep[t] + 1;
        // printf("tot1=%d, siz1=%d\n" , tot1 , siz1[tot1] );
    }
    for( int v : F1[u] )
        dfs1(v , deg1[u] == 1 ? t : v);
}
void dfs2(int u , int t)
{
    dep[u] = dep[ fa2[u] ] + 1;
    if(deg2[u] != 1)
    {
        bel2[u] = ++tot2;
        if(t != 1)
            G2[ bel2[ fa2[t] ] ].push_back(tot2);
        siz2[tot2] = dep[u] - dep[t] + 1;
        // printf("tot2=%d, siz2=%d\n" , tot2 , siz2[tot2] );
    }
    for( int v : F2[u] )
        dfs2(v , deg2[u] == 1 ? t : v);
}
bool fl = 1;
void dfs3(int u1 , int u2)
{
    // printf("u1=%d, u2=%d, siz1=%d, siz2=%d\n" , u1 , u2 , G1[u1].size() , G2[u2].size() );
    if(!fl)
        return ;
    if(G1[u1].size() != G2[u2].size() )
        return fl = 0,void();
    for(int i = 0;i < G1[u1].size();i++)
    {
        int v1 = G1[u1][i],v2 = G2[u2][i];
        dfs3(v1 , v2);
        if(!fl)
            return ;
    }
}
bool vis[N];
LL dp[N][N];
int V[N],top;
int main()
{
    // system("fc ex_b3.ans b.out");
    return 0;
    double bg = clock();
    // freopen("ex_b3.in" , "r" , stdin);
    freopen("b.in" , "r" , stdin);
    freopen("b.out" , "w" , stdout);
    cin >> n1 >> n2;
    // n1 = 400,n2 = 800;
    int n = max(n1 , n2);
    for(int i = 2;i <= n1;i++)
        // fa1[i] = i - 1,F1[ fa1[i] ].push_back(i),++deg1[ fa1[i] ];
        scanf("%d" , fa1 + i),F1[ fa1[i] ].push_back(i),++deg1[ fa1[i] ];
    for(int i = 2;i <= n2;i++)
        // fa2[i] = i - 1,F2[ fa2[i] ].push_back(i),++deg2[ fa2[i] ];
        scanf("%d" , fa2 + i),F2[ fa2[i] ].push_back(i),++deg2[ fa2[i] ];
    dfs1(1 , 1);
    dfs2(1 , 1);
    dfs3(1 , 1);
    // cout << "fl="<<fl << endl;
    int tot = tot1;
    if(fl)
    {
        for(int i = 1;i <= tot;i++)
            fl &= siz1[i] <= siz2[i];
    }
    // cout << "fl="<<fl << endl;
    // cerr << clock() - bg << endl;
    cin >> m;
    // m = 100;
    // dp[0][0] = 1;
    // while(m--)
    // for(int num = 1;num <= m;num++)
    while(m--)
    {
        int op,x;
        scanf("%d%d" , &op , &x);
        // op = 1,x = num;
        if(!fl)
        {
            puts("0");
            continue;
        }
        vis[x] ^= 1;
        top = 0;
        for(int i = 1;i <= n;i++)
            if( vis[i] )
                V[++top] = i;
        memset(dp , 0 , sizeof dp);
        dp[0][0] = 1;
        // if(op == 1)
        // {
        //     for(int i = 1;i <= n;i++)
        //     {
        //         for(int j = x;j <= n;j++)
        //             dp[i][j] = getmod( dp[i - 1][j - x] + dp[i][j] );
        //     }
        // }
        // else
        // {
        //     for(int i = 1;i <= n;i++)
        //     {
        //         for(int j = x;j <= n;j++)
        //             dp[i][j] = getmod( p - dp[i - 1][j - x] + dp[i][j] );
        //     }
        // }
        for(int i = 1;i <= n;i++)
        {
            for(int k = 1;k <= top;k++)
                for(int j = V[k];j <= n;j++)
                    dp[i][j] += dp[i - 1][ j - V[k] ];
            for(int j = 0;j <= n;j++)
                dp[i][j] %= p;
        }
        int ans = 1;
        for(int i = 1;i <= tot;i++)
            ans = 1ll * ans * dp[siz1[i] ][siz2[i] ] % p;
        printf("%d\n" , ans);
    }
    // cerr << clock() - bg << endl;
    return 0;
}
/*
6 9
1 1 3 3 2
1 1 2 3 3 5 6 4
5
1 1
1 2
1 3
2 1
2 2
*/