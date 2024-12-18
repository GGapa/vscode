//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve()  {
    int n; cin >> n;
    vector<int> X(n + 1), Y(n + 1);
    vector<int> x(n + 1), y(n + 1);
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        X[x[i]]++; Y[y[i]]++;
    }
    rep(i, 1, n) ans -= 1ll * (X[x[i]] - 1) * (Y[y[i]] - 1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}