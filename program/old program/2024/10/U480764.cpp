#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int INF = 2e9;

signed main() {
// #ifndef ONLINE_JUDGE
//     freopen("test.in", "r", stdin);
//     freopen("test.out", "w", stdout);
// #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    rep(i, 1, n) cin >> a[i] >> b[i] >> c[i], a[i] = INF - a[i], b[i] = INF - b[i], c[i] = INF - c[i];
    auto A = a, B = b, C = c;
    sort(A.begin(), A.end()); sort(B.begin(), B.end()); sort(C.begin(), C.end());
    rep(i, 1, n) {
        cout << min({lower_bound(A.begin() + 1, A.end(), a[i]) - A.begin(), lower_bound(B.begin() + 1, B.end(), b[i]) - B.begin(), lower_bound(C.begin() + 1, C.end(), c[i]) - C.begin()}) << '\n';
    }
    return 0;
}