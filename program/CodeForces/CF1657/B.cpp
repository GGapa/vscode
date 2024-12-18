#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, b, x, y; cin >> n  >> b >> x >> y;
    LL sum = 0;
    LL a = 0;
    rep(i, 1, n) {
        if(a + x <= b) a += x;
        else a -= y;
        sum += a;
    }
    cout << sum << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}