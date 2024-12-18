#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("G.in", "w", stdout);
    int n = 2e5, m = 2e5;
    cout << n << " " << m << "\n";
    rep(i, 1, m) cout << i << " " << 2 << '\n';
    int q = 2e5;
    cout << q << '\n';
    rep(i, 1, q) if(i != 2) cout << i << " " << 2 << '\n';
    cout << 2 << " " << 3 << '\n';
    return 0;
}