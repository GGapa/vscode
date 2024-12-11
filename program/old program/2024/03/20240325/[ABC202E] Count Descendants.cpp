// [ABC202E] Count Descendants
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    using VI = vector<int>;
    vector<VI> G(n + 1), dep = G
    ;
    for(int i = 2, x; i <= n; i++) 
        cin >> x, G[x].push_back(i), G[i].push_back(x);
    vector<int> in(n + 1), out = in;
    int idx = 0;
    auto dfs = [&](auto self, int x, int fa, int d) -> void {
        in[x] = ++idx;
        dep[d].push_back(idx);
        for(auto to : G[x]) if(to != fa) 
            self(self, to, x, d + 1);
        out[x] = ++idx;
    };
    dfs(dfs, 1, 0, 0);
    int q; cin >> q;
    for(int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        cout << lower_bound(dep[y].begin(), dep[y].end(), out[x]) - lower_bound(dep[y].begin(), dep[y].end(), in[x]) << '\n';
    }
    return 0;
}