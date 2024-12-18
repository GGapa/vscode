// Tandem Repeats?
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    int n = s.size();
    auto check = [&](int i, int len) {
        int j = i + len;
        if(j + len - 1>= n) return false;
        rep(l, 0, len - 1) if(s[i + l] != s[j + l] && (s[i + l] != '?' && s[j + l] != '?')) 
            return false;
        return true;
    };
    int ans = 0;
    rep(i, 0, n - 1) for(int j = (n - i) / 2; j >= 1; j--) {
        if(j <= ans) break;
        if(check(i, j)) 
            ans = max(j, ans);
    }
    cout << ans * 2 << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}