#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> s(n + 1), t(n + 1);
    LL ans = 0;
    rep(i, 1, n) cin >> s[i] >> t[i], ans += abs(s[i] - t[i]);
    t[0] = 0, s[0] = m;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    rep(i, 0, n) ans += abs(s[i] - t[i]);
    cout << ans << '\n';
    return 0;
}
