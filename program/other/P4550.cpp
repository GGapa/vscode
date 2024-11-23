#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<double> F(n + 1), G(n + 1) ;
    F[n] = 0;
    per(i, n - 1, 0) F[i] = 1.0 * n / (n - i) + F[i + 1];
    G[n] = 0;
    per(i, n - 1, 0) G[i] = 1.0 * i / (n - i) * (F[i] + 1) + G[i + 1] + F[i + 1] + 1;
    cout << fixed << setprecision(2) << G[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
/*
定义 F[i] 代表从 i 达到 n 的最小步数。
*/