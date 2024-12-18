int n;
 
namespace LCA {
    constexpr int N = 3e5 + 5, B = __lg(N) + 1;
 
    vector<int> G[N];
    int dfn[N], mn[B][N];
 
    void dfs(int x, int pa) {
        dfn[x] = ++dfn[N - 1]; mn[0][dfn[x]] = pa;
        for(auto to : G[x]) if(to != pa) dfs(to, x);
    }
 
    int get(int x, int y) {return (dfn[x] < dfn[y] ? x : y); }
 
    void init(int rt) {   
        dfs(rt, 0);
        rep(i, 1, B - 1) for(int j = 1; j + (1 << i) - 1 <= n; j++) 
            mn[i][j] = get(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
    }
 
    int lca(int x, int y) {
        if(x == y) return x;
        if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
        int d = __lg(y - x++);
        return get(mn[d][x], mn[d][y - (1 << d) + 1]);
    }
}
using LCA::lca;