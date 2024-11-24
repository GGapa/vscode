#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    // while(s.size() < 3) s = " " + s;
    string ans;  int cnt = 4;
    rep(i, 7, 1000) if(i % 7 == 0) {
        string tmp = to_string(i);
        // while(tmp.size() < 3) tmp = " " + tmp;
        if(tmp.size() != s.size()) continue;
        int t = 0;
        rep(j, 0, 2) if(tmp[j] != s[j]) t++;
        if(t < cnt) cnt = t, ans = tmp; 
    }
    cout << stoi(ans) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}