#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    LL n; cin >> n;
    LL l = 1, r = n * 2, ans = 0;
    while(l <= r) {
        LL mid = l + r >> 1;
        if(mid - (LL)sqrt(mid) < n) l = mid + 1;
        else r = mid - 1, ans = mid;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}