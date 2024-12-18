#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    map<string, int> mp;
    rep(i, 1, n - 1) {
        string t = ""; t += s[i]; t += s[i + 1];
        if(mp[t] != 0 && i - mp[t] > 1) 
            return cout << "YES\n", void();
        mp[t] = min(mp[t] == 0 ? INT_MAX : mp[t], i);
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}