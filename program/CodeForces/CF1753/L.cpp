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
    vector<int> F(n) ;
    rep(i, 1, n - 1) cin >> F[i];
    rep(i, 2, n) cout << 1 << " " << i << '\n';
    m -= (n - 1);
    if(m == 0) return 0;
    rep(i, 2, n) rep(j, i + 1, n) {
        cout << i << " " << j << '\n';
        m--;
        if(m == 0) return 0;
    }
    return 0;
}