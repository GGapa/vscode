#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    LL n, b, c; cin >> n >> b >> c;
    if(b == 0) {
        if(c + 1 < n - 1) return cout << -1 << '\n', void();
        else return cout << n - (!(c >= n)) << '\n', void();
    }
    int ans = max(0ll, (n - c + b - 1) / b );
    // rep(i, 1, n) {
    //     __int128_t t1 = b, t2 = c;
    //     if(t1 * (i - 1) + t2 < n) ans++;
    //     if(t1 * (i - 1) + t2 >= n) break;
    // } 
    cout << n - ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}