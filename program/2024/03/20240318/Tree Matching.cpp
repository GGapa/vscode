// Tree Matching
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int> ;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<VI> G(n + 1);
    for(int i = 2, x, y; i <= n; i++) {
        cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    vector<array<int, 2>> F(n + 1, {-1, -1});
    auto dfs = [&](auto self, int x, int t, int fa) -> int {
        auto &f = F[x][t];
        if(f != -1) return f;
        f = 0;
        for(auto to : G[x]) if(to != fa)
            f += self(self, to, 0, x);
        if(!t) {
            int nf = f;
            for(auto to : G[x]) if(to != fa) 
                nf = max(nf, f - self(self, to, 0, x) + 1 + self(self, to, 1, x));
            f = nf;
        }
        return f;
    };
    cout << max(dfs(dfs, 1, 0, -1), dfs(dfs, 1, 1, -1)) << '\n';
    return 0;
}