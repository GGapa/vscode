#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    string t; cin >> t; t = " " + t;
    priority_queue<int> q0, q1;
    int cnt = 1;
    for(int i = 2; i <= n; i++) {
        if(s[i] == s[i - 1]) {
            cnt++;
        }
        else {
            if(s[i] == '1') q0.emplace(cnt);
            else q1.emplace(cnt);
            cnt = 1;
        }
    }
    if(s[n] == '1') q1.emplace(cnt);
    else q0.emplace(cnt);
    rep(i, 1, n - 1) {
        if(q1.empty() || q0.empty()) return cout << "NO\n", void();
        if(t[i] == '0')  {
              
            int x = q1.top(); q1.pop();
            x--;
            if(x > 0) q1.emplace(x);
        }
        else {
            // if(q0.empty()) return cout << "NO\n", void();
            int x = q0.top(); q0.pop();
            x--;
            if(x > 0) q0.emplace(x);
        }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}