#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
typedef long double ld;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, a, X, Y;
    cin >> n >> a >> X >> Y;
    unordered_map<int, ld> v;
    function<ld(ll)> dfs = [&](ll x) {
        if(x == 0) return (ld)0;
        if(v[x]) return v[x];
        // cout << x << endl;
        ld ans = dfs(x / a) + X, tmp = 0;
        rep(i, 2, 6)
            tmp += dfs(x / i);
        tmp = tmp / 5 + 6.0 / 5 * Y;
        return v[x] = min(ans, tmp);
    };
    cout << fixed << setprecision(10) << dfs(n);
    return 0;
}