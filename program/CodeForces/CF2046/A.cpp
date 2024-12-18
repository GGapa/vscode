#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> A(n + 1);
    rep(i, 1, n) cin >> A[i][0];
    rep(i, 1, n) cin >> A[i][1];
    int ans = LLONG_MIN;
    int sa = 0, sb = 0;
    for(int i = 1, x, y; i <= n; i++) {
        x = A[i][0], y = A[i][1];
        if(x >= y) sa += x;
        else sb += y;
    }
    rep(i, 1, n) {
        int x, y;
        x = A[i][0], y = A[i][1];
        if(x >= y) sa -= x;
        else sb -= y;
        ans = max(ans, sa + sb + x + y);
        if(x >= y) sa += x;
        else sb += y;
    } 
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}