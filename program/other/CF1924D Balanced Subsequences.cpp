#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 1e9 + 7, N = 2000 + 5;

int n, m;

int F[N][N], sum[N];

int calc(int k) {
    if(n < k || m < k) return 0;
    rep(i, 0, n) rep(j, 0, m) F[i][j] = 0;
    rep(j, 0, m) sum[j] = 0;
    F[0][0] = 1;
    rep(j, 0, m) sum[j] = 1;
    rep(i, 1, n) {
        rep(j, 0, m) {
            if(j - (m - k) <= i - 1) F[i][j] = sum[j];
        }
        rep(j, 0, m) sum[j] = 0;
        sum[0] = F[i][0];
        rep(j, 1, m) sum[j] = (sum[j - 1] + F[i][j]) % mod;
    }
    return sum[m];
}

void solve() {
    int k;
    cin >> n >> m >> k;
    cout << (calc(k) - calc(k + 1) + mod) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}