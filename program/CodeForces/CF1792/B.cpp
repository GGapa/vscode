#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a == 0)return cout << 1 << '\n', void();
    int ans = a;
    int t = min(b, c); ans += t * 2;
    b -= t, c -= t;
    t = min(a + 1, max(b, c));
    ans += t; a -= t;
    ans += min(d, a + 1) ;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}