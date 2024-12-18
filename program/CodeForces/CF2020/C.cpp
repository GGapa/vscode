#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    LL b, c, d; cin >> b >> c >> d;
    LL a = 0;
    rep(i, 0, 61) {
        int tb = b >> i & 1, tc = c >> i & 1, td = d >> i & 1;
        bool tag = false;
        rep(j, 0, 1) {
            if((j | tb) - (j & tc) == td) a |= (1ll << i) * j, tag = true;
        }
        if(tag == false) return cout << -1 << '\n', void();
    }
    if((a | b) - (a & c) != d) return cout << -1 << '\n', void();
    cout << a << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}