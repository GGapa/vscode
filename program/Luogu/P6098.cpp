/*
problem:P6098 [USACO19FEB] Cow Land G
URL:https://www.luogu.com.cn/problem/P6098
date:2023-10-03
树状数组+DFS序+lca
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using VI = vector<int>;
struct XorBIT
{
    VI C;
    int N;
    void init(int sz) { N = sz, C.resize(sz + 1); }
    inline int lowbit(int x) { return x & -x; }
    int xorSum(int x) //树状数组前缀异或
    { 
        int xo = 0;
        while (x > 0)
            xo ^= C[x], x -= lowbit(x);
        return xo;
    }
    void xorV(int x, int v)
    { 
        while (x <= N)
            C[x] ^= v, x += lowbit(x);
    }
};
int HH, timer = 1;
vector<VI> G, fa;
VI Tin, Tout;
XorBIT S;
void dfs(int u = 0, int p = 0)
{ // dfs，倍增预处理
    Tin[u] = timer++, fa[u][0] = p;
    for (int i = 1; i < HH; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : G[u])
        if (v != p)
            dfs(v, u);
    Tout[u] = timer++;
}
inline bool isAncestor(int u, int v)
{ // 祖孙关系询问
    return (Tin[u] <= Tin[v] && Tout[u] >= Tout[v]);
}
int lca(int u, int v)
{ // LCA计算
    if (isAncestor(u, v))
        return u;
    for (int i = HH - 1; i >= 0; i--)
        if (fa[u][i] >= 0 && !isAncestor(fa[u][i], v))
            u = fa[u][i];
    return fa[u][0];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, Q;
    cin >> N >> Q, HH = ceil(log2(N)) + 2, S.init(2 * N);
    G.resize(N + 1), Tin.resize(N), Tout.resize(N), fa.assign(N + 1, VI(HH));
    vector<int> E(N);
    for (int &e : E)
        cin >> e;
    for (int i = 1, u, v; i < N; i++)
        cin >> u >> v, --u, --v, G[u].push_back(v), G[v].push_back(u);
    dfs();
    for (int i = 0; i < N; i++)
        S.xorV(Tin[i], E[i]), S.xorV(Tout[i], E[i]);
    for (int q = 0, s, x, u, v, t; q < Q; q++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> s >> x; 
            int &e = E[--s];
            S.xorV(Tin[s], e), S.xorV(Tout[s], e), e = x; // 清除初始值
            S.xorV(Tin[s], e), S.xorV(Tout[s], e);        // 设置新的值
        }
        else
        {
            cin >> u >> v, --u, --v;
            printf("%d\n", (S.xorSum(Tin[u]) ^ S.xorSum(Tin[v])) ^ E[lca(u, v)]);
        }
    }
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
2.23KB
用时
1.61s
内存
23.80MB
*/