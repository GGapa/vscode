#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    int ans = 0;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    for(int i = 1; i <= n; i += 2)  ans = max(ans, A[i]);
    for(int i = n; i  >0; i -= 2) ans = max(ans, A[i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}