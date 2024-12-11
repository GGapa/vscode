// Tree Distances II
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    using VI = vector<int>;
    vector<VI> G(n + 1);
    for(int i = 2, x, y; i <= n; i++) 
        cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
    vector<int> S(n + 1), F(n + 1);
    auto dfs1 = [&](auto self, int x, int fa, int d) -> int {
        auto  &s = S[x];
        F[1] += d; s = 1;
        for(auto to : G[x]) if(to != fa) {
            s += self(self, to, x, d + 1);
        } 
        return s;
    };
    auto dfs2 = [&](auto self, int x, int fa) -> void {
        for(auto to : G[x]) if(to != fa) {
            F[to] = F[x] + n - 2 * S[to];
            self(self, to, x);
        }
    };
    dfs1(dfs1, 1, 0, 0); dfs2(dfs2, 1, 0);
    rep(i, 1, n) cout << F[i] << " \n"[i == n]; 
    return 0;
}