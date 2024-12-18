#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    int ans = 0, cnt = 0, rem = 0;
    rep(i, 1, n) {
        cin >> a[i];
        ans += a[i] / 2 * 2; rem += a[i] / 2;   // 答案
        a[i] %= 2; cnt += a[i];
    }
    int ad = 0;
    for(; ad + (m - ad) * 2 >= cnt + ans; ad++) ;
    cout << min(ans + ad - 1, ans + cnt) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}