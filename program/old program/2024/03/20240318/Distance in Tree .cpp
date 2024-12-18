// Distance in Tree 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    using VI = vector<int>;
    vector<VI> G(n+ 1), F(n + 1, VI(k + 1));
    ll ans = 0;
    for(int i = 2, x, y; i <= n; i++) 
        cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
    auto dfs = [&](auto self, int x, int fa) -> void{
        auto &f = F[x];
        f[0] = 1;
        for(auto to : G[x]) if(to != fa) {
            self(self, to, x);
            rep(i, 0, k - 1) ans += f[i] * F[to][k - i - 1];
            rep(i, 0, k - 1) f[i + 1] += F[to][i];
        }
    };
    dfs(dfs, 1, -1);
    cout << ans << '\n';
    return 0;
}
// 以“右端点”进行查找，这样才可以不重不漏。
// 树上动态规划往往需要以树的节点/子树作为转移对象