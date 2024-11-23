#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> xx(n + 1), yy(n + 1) ;
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, xx[x] = 1, yy[y] = 1;
    int ans = (accumulate(xx.begin() + 1, xx.end(), 0) <= n - 1) && (accumulate(yy.begin(), yy.end(), 0) <= n - 1);
    cout << (ans ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}