#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


void solve() {
    string s; cin >> s;
    // if(s.size() == 1) return cout << s << char((s[0] - 'a' + 1) % 26 + 'a') << '\n', void();
    int t = s.size() - 1;
    rep(i, 0, s.size() - 1) if(s[i] == s[i + 1]) {
        t = i; break;
    }
    rep(i, 0, t) cout << s[i];
    cout << char((s[t] - 'a' + 1) % 26 + 'a') ;
    rep(i, t + 1, s.size() - 1) cout << s[i];
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}