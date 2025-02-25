#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 5e5 + 5;

int n, m; 

namespace SCC {
    int low[N], dfn[N], vis[N];
    vector<int> stk;
    vector<int> G[N];
    vector<VI> bel; 

    int dfs(int x) {
        dfn[x] = low[x] = ++dfn[N - 1]; 
        stk.emplace_back(x);
        for(auto to : G[x]) {
            if(!dfn[to]) low[x] = min(low[x], dfs(to));
            else if(!vis[to]) low[x] = min(low[x], dfn[to]);
        }
        if(dfn[x] == low[x]) {
            vector<int> tmp;
            for(int i = -1; i != x; stk.pop_back())
                tmp.emplace_back(i = stk.back()), vis[i] = 1;
            bel.emplace_back(tmp);
        }
        return low[x];
    }
}
using namespace SCC;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, u++, v++, G[u].emplace_back(v);
    
    rep(i, 1, n) if(!dfn[i]) dfs(i);

    cout << bel.size() << '\n';
    reverse(bel.begin(), bel.end());
    for(auto a : bel) {
        cout << a.size() << " ";
        for(auto b : a) cout << b - 1 << ' ';
        cout << '\n';
    }

    return 0;
}