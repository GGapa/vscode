#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int l1, l2, r1, r2; cin >> l1 >> r1 >> l2 >> r2;
    int ans = 0;
    if(l1 <= l2 && l2 <= r1) ans = l2;
    else if(l2 <= l1 && l1 <= r2) ans = l1;
    else ans = l1 + l2;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}