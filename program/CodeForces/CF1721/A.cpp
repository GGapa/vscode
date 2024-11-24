#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    vector<int> cnt(27);
    rep(i, 1, 4) {
        char c; cin >> c;
        cnt[c - 'a'] ++;
    }
    int ans = 0;
    rep(i, 0, 26) ans += (cnt[i] > 0);
    cout <<ans- 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}