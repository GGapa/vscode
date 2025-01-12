#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2000 + 5, B = 45, mod = 998244353;

int n = 2000;
int G[2][N][N], F[N][N];

void solve() {
    int m; cin >> n >> m;
    cout << F[n][m] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int o;
    G[0][0][0] = o = 1;
    for (int j = 1; j <= B; j++, o ^= 1) {
        memset(G[o], 0, sizeof(G[o]));
        rep(i, 1, n) rep(k, 1, n) {
            if (i > 1) (G[o][i][k] += G[o][i - 1][k]) %= mod;
            if (k >= B) (G[o][i][k] += G[o ^ 1][i - 1][k - B]) %= mod;
            if (k >= j) (G[o][i][k] += G[o][i][k - j]) %= mod;
            (F[i][k] += G[o][i][k]) %= mod;
        }
    }
    F[0][0] = 1;
    per(k, B - 1, 1) rep(i, 1, n) rep(j, 1, n) {
        if (j >= k) (F[i][j] += F[i - 1][j - k]) %= mod;
        if (i > 1) (F[i][j] += F[i - 1][j]) %= mod;
    }

    int T; cin >> T;
    while(T--) solve();
    return 0;
}