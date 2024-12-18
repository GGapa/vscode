#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n = 1e5;
    cout << n << '\n';
    rep(i, 1, n - 1) cout << i << " " << i + 1 << '\n';
}

signed main() {
    freopen("test.in", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 5;
    cout << T << '\n';
    while(T--) solve();
    return 0;
}