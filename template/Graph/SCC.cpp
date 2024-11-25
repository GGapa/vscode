struct SCC {
    int n, idx, cnt;
    vector<VI> G;
    VI stk, dfn, low, belong;
    SCC(int _n) : n(_n), G(n + 1), low(n + 1), belong(n + 1), dfn(n + 1) {
        idx = cnt = 0;
    }   
    void add(int u, int v) {G[u].push_back(v); };
    int dfs(int x) {
        low[x] = dfn[x] = ++idx;
        stk.push_back(x);
        for(auto to : G[x]) {
            if(!dfn[to]) 
                low[x] = min(low[x], dfs(to));
            else if(!belong[to])
                low[x] = min(low[x], low[to]);
        }
        if(low[x] == dfn[x]) {
            cnt++;
            for(int i = -1; i != x; stk.pop_back()) 
                i = stk.back(), belong[i] = cnt;
        }
        return low[x];
 
    }
};