struct EBCC {
    int n, idx;
    vector<VI> G;
    VI dfn, low;
    set<int> ans;
    EBCC(int _n) : n(_n), dfn(_n + 1), low(_n + 1), G(_n + 1) {
        idx = 0;
    }
    void add(int u, int v) {
        G[u].push_back(v), G[v].push_back(u);
    }
    int dfs(int x, int p) {
        int ch = 0;
        low[x] = dfn[x] = ++idx;
        for(auto to : G[x])  {
            if(!dfn[to]) {
                ch++;
                int t = dfs(to, x);
                low[x] = min(low[x], t);
                if(t >= dfn[x] && p != -1) 
                    ans.insert(x);
            }
            else 
                low[x] = min(low[x], dfn[to]);
        }
        if(ch >= 2 && p == -1) ans.insert(x);
        return low[x];
    }
};