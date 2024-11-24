#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    s = " " + s, t = " " + t;
    vector<int> c1(4), c2(4);
    rep(i, 1, n) {
        c1[s[i] - 'a']++, c2[t[i] -'a']++;
        if(c2[0] > c1[0]) return cout << "NO\n", void();
    }
    if(c1 != c2) return cout << "NO\n", void();
    fill(c1.begin(), c1.end(), 0); fill(c2.begin(), c2.end(), 0);
    per(i, n, 1) {
        c1[s[i] - 'a']++, c2[t[i] -'a']++;
        if(c2[2] > c1[2]) return cout << "NO\n", void();
    }
    string as, at;
    rep(i, 1, n) {
        if(s[i] != 'b') as += s[i];
        if(t[i] != 'b') at += t[i];
    }
    if(as != at) return cout << "NO\n", void();
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
