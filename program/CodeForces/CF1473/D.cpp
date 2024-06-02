// D
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s; s = " " + s;
    unordered_map<int, bool> vis;
    vector<int> S(n + 2), px = S, pn = S, sx = S, sn = S, F = S; 
    S[0] = 1; vis[0] = true;
    for(int i = 1, t = 0; i <= n; i++) {
        t += (s[i] == '+' ? 1 : -1);
        F[i] = t;
        S[i] = S[i - 1] + (!vis[t]);
        vis[t] = 1;
    }
    // rep(i, 1, n) cout << F[i] << ' ';
    rep(i, 1, n) px[i] = max(px[i - 1], F[i]), pn[i] = min(pn[i - 1], F[i]);
    sx[n] = sn[n] = F[n];
    per(i, n - 1, 1) sx[i] = max(sx[i + 1], F[i]), sn[i] = min(sn[i + 1], F[i]);
    for(int o = 1, l, r; o <= m; o++) {
        cin >> l >> r;
        int dl = F[r] - F[l - 1];
        int smx = (r == n ? INT_MIN : sx[r + 1] - dl), smn = (r == n ? INT_MAX : sn[r + 1] - dl);
        cout << max(smx, px[l - 1]) - min(smn, pn[l - 1]) + 1 << '\n';
        // cout << smx << " " << px[l - 1] << " " << smn << " " << pn[l - 1] << '\n';
    }
    // cout << S[n] << '\n';
}
// 考虑记录前后缀最大最小值。

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
4 1
+-++
1 3
*/