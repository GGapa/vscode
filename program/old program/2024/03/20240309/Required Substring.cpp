// Required Substring 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int m = s.length();
    if(m > n) return cout << -1, 0;
    using VL = vector<ll>;
    vector<VL> len(n + 1, VL(27)), F(n + 1, VL(m + 1));
    rep(i, 0, m - 1) rep(j, 0, 25) {
        string ns = s.substr(0, i) + char('A' + j);
        int nl = ns.length();
        rep(k, 0, nl - 1) if(ns.substr(k) == s.substr(0, nl - k)) {
            len[i][j] = nl - k;
            break;
        }
    }
    F[0][0] = 1;
    rep(i, 0, n - 1) rep(j, 0, m - 1) rep(k, 0, 25) 
        (F[i + 1][len[j][k]] += F[i][j]) %= mod;
    ll ans = 1;
    rep(i, 1, n) (ans *= 26) %= mod;
    rep(i, 0, m - 1) (ans += -F[n][i] + mod) %= mod;
    cout << ans << '\n';
    return 0;
}