#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    int L = 1, R = 50;
    for(int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        if(l <= k && k <= r) L = max(l, L), R = min(r, R);
    }
    cout << (L == R ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}