#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> x(n + 1), y(n + 1);
    rep(i, 1, n) cin >> x[i] >> y[i];
    int sx, sy, ex, ey ; cin >> sx >> sy >> ex >> ey;
    LL ds = (sx - ex) * (sx - ex) + (sy - ey) * (sy - ey);
    rep(i, 1, n) {
        int cnt = (x[i] - ex) * (x[i] - ex) + (y[i] - ey) * (y[i] - ey); 
        if(cnt <= ds) return cout << "NO\n", void();
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}