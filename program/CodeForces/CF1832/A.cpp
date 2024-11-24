#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    for(int i = 1, j = n - 1; i + 1 < j; i++, j--) if(s[i] != s[i + 1])
        return cout << "YES\n", void();
    cout << "NO\n", void();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
