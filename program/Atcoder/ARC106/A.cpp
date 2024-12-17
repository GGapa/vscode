#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL n; cin >> n;
    for(LL i = 1, a = 3; a <= n; a *= 3, i++) for(LL j = 1, b = 5; b + a <= n; b *= 5, j++) if(a + b == n) return cout << i << " " << j << '\n', 0;
    cout << -1 << '\n';
    return 0;
}