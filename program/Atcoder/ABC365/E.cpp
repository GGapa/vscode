#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LL ans = 0;
    vector<int> A(n + 1), S(n + 1);
    vector<VI> F(41, VI(2));
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] ^ A[i];
    rep(i, 0, n) per(j, 30, 0) 
        F[j][(S[i] >> j) & 1]++;
    rep(i, 0, 30) ans += F[i][0] * F[i][1] * (1 << i);
    cout << ans << '\n';
    return 0;
}