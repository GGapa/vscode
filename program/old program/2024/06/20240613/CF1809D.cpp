// D. Binary String Sorting
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const ll ad = 1e12;

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<ll> pre(n + 2), suf(n + 2);
    ll cnt = 0;
    rep(i, 1, n) pre[i] = pre[i - 1] + (s[i] == '1') * (ad + 1);
    per(i, n, 1) suf[i] = suf[i + 1] + (s[i] == '0') * (ad + 1);
    ll ans = LLONG_MAX;
    rep(i, 1, n + 1) {
        ans = min(ans, pre[i - 1] + suf[i]);
        if(i < n && s[i] == '1' && s[i + 1] == '0') ans = min(ans, pre[i - 1] + suf[i + 2] + ad);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}