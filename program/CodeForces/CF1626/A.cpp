#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    vector<int> cnt(27);
    for(auto c : s) cnt[c - 'a']++;
    rep(i, 0, 26) if(cnt[i] == 1) cout << (char)('a' + i);
    rep(i, 0, 26) if(cnt[i] == 2) cout << (char)('a' + i) << (char)('a' + i);
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}