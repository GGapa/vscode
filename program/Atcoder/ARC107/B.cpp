#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;

    auto calc = [&](int x) {
        if(x < 2 || x > n + n) return 0ll;
        
        LL t = min(n, x - 1) - max(x - n, 1) + 1;
        return t;
    };
    LL ans = 0;
    rep(i, 1, 2 * n) ans += calc(i) * calc(i + k);
    cout << ans << '\n';
    return 0;
}