//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, x, y; cin >> n >> y >> x;
    vector<int> ans(n + 1);
    for(int i = x - 1, xx = -1; i >= 1; i--, xx *= -1) ans[i] = xx;
    rep(i, x, y) ans[i] = 1;
    for(int i = y + 1, xx = -1; i <= n; i++, xx *= -1) ans[i] = xx;
    rep(i ,1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve(); 
    return 0;
}