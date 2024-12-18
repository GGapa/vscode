#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    string t;
    int n = s.size(); s = " "  + s;
    s[0] = '0'; s += "0"; 
    vector<int> pre(n + 1), suf(n + 2, n + 1);
    rep(i, 1, n) pre[i] = (s[i] == '?' ? pre[i - 1] : i);
    per(i, n, 1) suf[i] = (s[i] == '?' ? suf[i + 1] : i);
    rep(i, 1, n) {
        if(s[i] == '?') {
            if(s[pre[i]] == '0' && s[suf[i]] == '0') t += '0';
            else t += '1';
        }
        else t += s[i];
    }
    cout << t << '\n';
    // cout << string(s.begin() + 1, s.end()) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}