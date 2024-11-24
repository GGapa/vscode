#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    LL n, k; cin >> n >> k;
    if(n % 2 == 0) return cout << "YES\n", void();
    else if((n - k) % 2 == 0 && n - k >= 0) return cout << "YES\n", void();
    else if((n - 2 * k) % 2 == 0 && n - 2 * k >= 0) return cout << "YES\n", void();
    else return cout << "NO\n", void();
 }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}