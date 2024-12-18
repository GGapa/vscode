#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int cnt = 0;
    rep(i, 1, 4) {
        int x; cin >> x;
        cnt += x;
    }
    if(cnt == 0) return cout << 0 << '\n', void();
    else if(cnt == 4) return cout << 2 << '\n', void();
    cout << "1\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}