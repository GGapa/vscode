#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    int c0 = count(s.begin(), s.end(), '0'), c1 = count(s.begin(), s.end(), '1');
    if(c0 == c1) return cout << c0 - 1 << '\n', void();
    cout << min(c0, c1) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}