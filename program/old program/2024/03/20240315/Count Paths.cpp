// Count Paths
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve( ) { 
    int n; cin >> n;
    vector<int> co(n + 1);
    unordered_map<int, int> cnt;
    vector<VI> G(n + 1);
    rep(i, 1, n) cin >> co[i];
    for(int i = 2, a, b; i <= n; i++) {
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    int ans = 0;
    auto dfs = [&](auto self, int x, int fa) -> void {
        int &c = cnt[co[x]], tmp = c; ans += tmp;
        for(auto to : G[x]) if(to != fa) {
            c = 1;
            self(self, to, x);
        }
        c = tmp + 1;
    };
    dfs(dfs, 1, 1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}