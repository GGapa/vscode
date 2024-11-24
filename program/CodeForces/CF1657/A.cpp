#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int x, y; cin >> x >> y;
    if(x == y && y == 0) return cout << 0 << '\n', void();
    else if(x * x + y * y == (int)sqrt(x * x + y * y) * (int)sqrt(x * x + y * y)) return cout << 1 << '\n', void();
    else cout << 2 << '\n', void();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}