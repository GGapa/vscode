#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    auto check = [=](string s, string t) {
        rep(i, 0, (int)s.size() - 1) if(s[i] == s[i + 1]) return false;
        rep(i, 0, (int)t.size() - 1) if(t[i] == t[i + 1]) return false;
        return true;
    };
    string s, t; cin >> s >> t; 
    reverse(t.begin(), t.end());
    rep(i, 0, n - 1) {
        string tmp = s.substr(i + 1, n - i); 
        if(check(s.substr(0, i + 1), tmp + t)) return cout << "YES\n", void();
    }
    reverse(t.begin(), t.end());
    swap(s, t); swap(n, m);
    reverse(t.begin(), t.end());
    rep(i, 0, n - 1) {
        string tmp = s.substr(i + 1, n - i); 
        if(check(s.substr(0, i + 1), tmp + t)) return cout << "YES\n", void();
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
