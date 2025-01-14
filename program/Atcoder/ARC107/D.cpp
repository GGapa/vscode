#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 6000 + 5, mod = 998244353;

int F[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    F[0][0] = 1;
    rep(i, 1, n) per(j, i, 1) {
        (F[i][j] = F[i - 1][j - 1] + F[i][j * 2]) %= mod;
    }
    cout << F[n][k] << '\n';
    return 0;
}