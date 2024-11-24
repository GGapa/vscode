#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(27); 
    int sum = 0;
    rep(i, 1, 26) cin >> A[i], sum += A[i];
    n = min(n, sum); 
    vector<VI> C(1001, VI(1001));
    C[0][0] = 1;
    rep(i, 1, n ) {
        C[i][0] = 1;
        rep(j, 1, i) (C[i][j] = C[i - 1][j] + C[i - 1][j - 1]) %= mod;
    }
    vector<VI> F(28, VI(n + 1));
    F[0][0] = 1;
    rep(i, 1, 26) rep(j, 0, n) rep(k, 0, min(j, A[i])) 
        (F[i][j] += F[i - 1][j - k] * C[j][k]) %= mod;
    int ans = 0;
    rep(i, 1, n) (ans += F[26][i]) %= mod;
    cout << ans << '\n';
    return 0;
}
/*
计数 dp 常见套路 F[i][j] 前 i 个字符，组成长度为 j 的串的数量
*/