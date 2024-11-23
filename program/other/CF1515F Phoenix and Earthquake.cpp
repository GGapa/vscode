#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 100 + 5;

int n, m, X;
int A[N];
set<array<LL, 3>> G[N];
set<pair<LL, int>> s;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> X; 
    rep(i, 1, n) cin >> A[i];
    LL sum  = accumulate(A, A + 1 + n, 0ll);

    if(sum - (n - 1) * 1ll * X < 0) return cout << "NO\n", 0;
    else cout << "YES\n";
    
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].insert({A[v], v, i}), G[v].insert({A[u], u, i});
    
    rep(i, 1, n) s.insert({A[i], i});

    vector<int> ans;

    while(s.size() > 1) {
        int x = s.rbegin()->second; LL val = s.rbegin()->first;

        auto ttmp = *G[x].rbegin();
        int y = ttmp[1]; LL yval = ttmp[0];
        // cerr << x << " " << y << '\n';
        
        s.erase({val, x}); s.erase({yval, y});
        if(G[x].size() > G[y].size()) swap(x, y), swap(val, yval);

        for(auto i : G[x]) {
            int to = i[1];
            G[to].erase(G[to].lower_bound({val, x, -10}));
            if(to != y) G[y].insert({i[0], i[1], A[x] + A[y] - X});
        }
        for(auto i : G[y]) {
            int to = i[1];
            G[to].erase(G[to].lower_bound({yval, y, -10}));
            G[to].insert({A[x] + A[y] - X, y, i[2]});
        }
        G[x].erase(G[x].lower_bound({yval, y, -10}));
        s.insert({A[y] + A[x] - X, y}); A[y] = A[y] + A[x] - X;

        ans.emplace_back(ttmp[2]);
    }
    // cout << ans.size() << '\n';
    for(auto a : ans) cout << a << '\n';
    return 0;
}
/*

首先判断无解的情况，是否拥有结论可以得到一定有解？
考虑维护每一个连通块，维护连通块的点权，现在需要合并两个连通块，且满足两个连通块之间拥有边，
考虑点权从大到小填写，
*/