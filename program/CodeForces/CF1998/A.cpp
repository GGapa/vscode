#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    if(k & 1) cout << x << " " << y << '\n', k--;
    int it = 1;
    rep(i, 1, k) {
        if(i & 1)cout << x + it << " " << y << '\n';
        else cout << x - it << " " << y << '\n', it++;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}