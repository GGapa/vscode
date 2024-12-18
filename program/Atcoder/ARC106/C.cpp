#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    if(n == 1 && m == 0) return cout << "1 2\n", 0;
    if(m < 0 || m >= n - 1) return cout << -1 << '\n', 0;
    int a = (n - 1 - m);
    rep(i, 1, a - 1) cout << i * 2 - 1 << " " << i * 2 << "\n";
    cout << a * 2 - 1 << " " << (int)1e7 << '\n';
    rep(i, a + 1, n) cout << i * 2 << " " << i * 2 + 1 << '\n';
    return 0;
}