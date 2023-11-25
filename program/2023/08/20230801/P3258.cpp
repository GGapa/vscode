//P3258 [JLOI2014] 松鼠的新家
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 3e5 + 5;
int n;
int a[maxn], fa[maxn], son[maxn], dep[maxn], siz[maxn], top[maxn];
vector <int> vec[maxn];
inline int read()
{
    char c;
    int x=0,f=1;
    c = getchar();
    while(!isdigit(c))
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}
void dfs1(int x,int f)
{
    fa[x] = f;
    dep[x] = dep[f] + 1;
    siz[x] = 1;
    for(auto to : vec[x])
    {
        if(to == f)continue;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]])son[x] = to;
    }
}
void dfs2(int x,int tp)
{
    top[x] = tp;
    if(!son[x]) return;
    dfs2(son[x], tp);
    for(auto to : vec[x])
    {
        if(to == fa[x] || to == son[x])continue;
        dfs2(to, to);
    }
}

int LCA(int x, int y)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y])return x;
    return y;
}

int val[maxn];
void dfs3(int x)
{
    for(auto to : vec[x])
    {
        if(to == fa[x])continue;
        dfs3(to);
        val[x] += val[to];
    }
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for(int i = 1, x, y; i < n; i++)
    {
        x = read();
        y = read();
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    for(int i = 1;i < n; i++)
    {
        int lca = LCA(a[i], a[i + 1]);
        val[a[i]]++;
        val[a[i + 1]]++;
        val[lca]--;
        val[fa[lca]]--;
    }
    dfs3(1);
    for (int i = 2; i <= n; i++)
    {
        val[a[i]]--;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << val[i] << "\n";
    }
    return 0;
}
