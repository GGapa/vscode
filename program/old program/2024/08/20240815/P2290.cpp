#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;
const int N = 160 * 2;

int C[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> d(n + 1) ;
    int sum = 0;
    rep(i, 1, n) cin >> d[i], sum += d[i] - 1;
    if(n == 1) return cout << !d[1] << '\n', 0;
    if(sum != n - 2) return cout << 0 << '\n', 0;
    rep(i, 1, n) if(d[i] == 0) return cout << 0 << '\n', 0;
    rep(i, 0, 300) {
        C[i][0] = C[i][i] = 1;
        rep(j, 1, 300) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    int ans = 1;
    rep(i, 1, n) {
        int t = d[i] - 1;
        ans *= C[sum][t], sum -= t;
    }
    cout << ans << '\n';
    // cout << 4709614623714;
    return 0;
}