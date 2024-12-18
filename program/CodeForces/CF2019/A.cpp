#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

// 冲冲冲！！！
void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    int mx = 0, cnt = 0, ans = 0;
    for(int i = 1; i <= n; i += 2) cnt++, mx = max(mx, A[i]);
    ans = max(ans, cnt + mx);
    mx = 0, cnt = 0;
    for(int i = 2; i <= n; i += 2) cnt++, mx = max(mx, A[i]);
    ans = max(ans, cnt + mx);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}