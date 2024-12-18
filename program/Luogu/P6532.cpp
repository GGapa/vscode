#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, p; cin >> n >> k >> p;
    LL ans = 0;
    gp_hash_table<int, int> sx, sy, cx, cy;
    map<pair<int, int>, int> A;
    cx[0] = n; cy[0] = n;

    auto calc = [&](int x, int y) {
        return (n - cy[sx[x]]) + (n - cx[sy[y]]);
    };

    auto modify = [&](int x, int y, int w) {
        ans -= calc(x, y);
        cx[sx[x]]--; cy[sy[y]]--;
        sx[x] ^= w, sy[y] ^= w;
        cx[sx[x]]++; cy[sy[y]]++;
        ans += calc(x, y);
        A[{x, y}] ^= w;
    } ;

    for(int i = 1, x, y, w; i <= k; i++) {
        cin >> x >> y >> w;
        modify(x, y, w);
    }

    for(int a, b, c, d; p--; ) {
        cin >> a >> b >> c >> d;
        int t = A[{a, b}];
        modify(a, b, t);
        modify(c, d, t);
        cout << ans << '\n';
    } 

    return 0;
}
/*
1. 行列分开考虑。 (√)
2. 考虑清楚满足条件的行和列满足什么条件，即为 行^列 不为 0 也就是说行和列不相同。   (×)
3. 考虑答案的增量是多少。   (√)
*/