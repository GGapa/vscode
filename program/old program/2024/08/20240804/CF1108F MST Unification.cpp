#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> e;
    vector<int> fa(n + 1); 
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    };
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, e.push_back({w, u,  v}) ;
    sort(e.begin(), e.end());
    int tp = (int) e.size();
    int ans = 0;
    for(int i = 0, j = 0; i < m; i = j) {
        while(j < m && e[i][0] == e[j][0]) j++;
        rep(k, i, j - 1) if(find(e[k][1]) != find(e[k][2])) ans++;
        rep(k, i, j - 1) {
            int x = find(e[k][1]), y = find(e[k][2]);
            if(x == y) continue;
            ans--;
            fa[x] = y;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
} 