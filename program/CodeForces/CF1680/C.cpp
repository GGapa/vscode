#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 1e9;

void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<int> F(n + 1), G(n + 1);
    rep(i, 1, n) F[i] = F[i - 1] + (s[i] == '0'), G[i] = G[i - 1] + (s[i] == '1');
    int c0 = F[n], ans = INF;
    rep(i, 0, c0) {
        int t = n - (c0 - i) ;
        int mx = G[i] + G[n] -  G[t];
        ans = min(ans, mx);
    }
    if(ans >= INF) ans = 0;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}