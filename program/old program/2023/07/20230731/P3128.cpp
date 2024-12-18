//P3128 [USACO15DEC] Max Flow P

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 5e4+5;

int n,T,k;
vector <int> vec[maxn];
int val[maxn];
int fa[maxn],siz[maxn],son[maxn];
int dep[maxn],top[maxn];

void dfs1(int x, int f)
{
    fa[x] = f;
    siz[x] = 1;
    dep[x] = dep[f] + 1;
    for(auto to : vec[x])
    {
        if(to == f)continue;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]]) son[x] = to;

    }
}
void dfs2(int x,int tp)
{
    top[x] = tp;
    if(!son[x]) return ;
    dfs2(son[x], tp);
    for(auto to : vec[x])
    {
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}
int ans=-1;
void dfs3(int x)
{
    for(auto to : vec[x])
    {
        if(to == fa[x])continue;
        dfs3(to);
        val[x] += val[to];
    }
    ans = max(ans, val[x]);
}

int LCA(int x, int y)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y])return x;
    return y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> T;
    for(int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    while(T --)   
    {
        int x;
        int y;
        cin >> x >> y;
        int lca = LCA(x, y);
        val[x]++;
        val[y]++;
        val[lca]--;
        val[fa[lca]]--;
    }
    dfs3(1);
    cout << ans << endl;
    return 0;
}