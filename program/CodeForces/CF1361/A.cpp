#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

vector<int> G[N];

void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, n) vector<int>(0).swap(G[i]);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);

    vector<int> A(n + 1), id(n), vis(n + 1);
    rep(i, 1, n) cin >> A[i];
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        return A[x] < A[y];
    });

    for(auto x : id) {
        set<int> s;
        for(auto to : G[x]) if(vis[to]) s.insert(A[to]);
        if(s.size() && *s.rbegin() >= A[x]) return cout << -1 << '\n', void();
        if(s.size() != A[x] - 1) return cout << -1 << '\n', void();
        vis[x] = 1;
    }
    for(auto i : id) cout << i << " ";
    cout << '\n'; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}