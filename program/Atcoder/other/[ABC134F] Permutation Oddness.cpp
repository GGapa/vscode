#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7, N = 50 + 5, B = N * N;

int F[N][N][2 * N * N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    F[0][0][N * N] = 1;
    rep(i, 1, n) rep(j, 0, n) rep(k, -n * n, n * n) {
        F[i][j][k + B] = F[i - 1][j][k + B];
        (F[i][j][k + B] += F[i - 1][j][k + B] * 2 % mod * 1ll * j % mod) %= mod;
        if(k + i * 2 <= n * n && j)(F[i][j][k + B] += F[i - 1][j - 1][k + i * 2 + B]) %= mod;
        if(k - i * 2 >= -n * n && j < n) (F[i][j][k + B] += F[i - 1][j + 1][k - i * 2 + B] * 1ll * (j + 1) % mod * (j + 1) % mod) %= mod;
    }
    cout << F[n][0][m + B] << '\n';
    return 0;
}