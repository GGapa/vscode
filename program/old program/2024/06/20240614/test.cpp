#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    EBCC tj(4);
    tj.add(1, 2); tj.add(2, 3); tj.add(3, 1);
    tj.dfs(1, 0);
    cout << tj.low[3];
    return 0;
}