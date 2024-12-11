#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> F(2), A(n + 1);     // 0 是 + 1 是 -
    rep(i, 1, n) {
        int x; cin >> x;
        F[1] = max(F[1], F[0] - x);
        F[0] = max(F[0], F[1] + x);
    }
    cout << max(F[1], F[0]) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}