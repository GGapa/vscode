#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

LL calc(int x, int y) {
    return 1ll * (x + y) * (y - x + 1) / 2;
}

void solve() {
    int n; cin >> n;
    vector<int> k(n + 1), h(n + 1);
    rep(i, 1, n) cin >> k[i] ;
    rep(i ,1, n) cin >> h[i];
    LL ans = 0;
    vector<int> F(n + 1);
    per(i, n - 1, 1) 
        h[i] = max(h[i], h[i + 1] - (k[i + 1] - k[i]));
    // rep(i, 1, n) cout << h[i] << " \n"[i == n];
    
    rep(i, 1, n) {
        if(k[i] - k[i - 1] >= h[i]) ans += calc(1, h[i]), F[i] = h[i];
        else ans += calc(F[i - 1] + 1, F[i - 1] + k[i] - k[i - 1]), F[i] = F[i - 1] + k[i] - k[i - 1];
        // cout << ans << '\n';
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}