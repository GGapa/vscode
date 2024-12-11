#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 900 + 10, mod = 998244353;
int n, m, k, p, t, a[N], C[N][N];
int qpow(int a, int b) {
    int res = 1;
    for (; b; a = a * a % mod, b >>= 1)
        if (b & 1) res = res * a % mod;
    return res;
}
namespace Sub1 {
    const int N = 100;
    struct edge {
        int u, v, w;
    } E[N];
    int ans = 0, cc = 0;
    int calc() {
        int sum = 0;
        for (int k = 0; k < (1 << n); k++) {
            bool ok = 1;
            int s = 0;
            for (int i = 1; i <= m; i++) {
                if ((k >> (E[i].u - 1) & 1) && (k >> (E[i].v - 1) & 1)) ok = 0;
                else if ((k >> (E[i].u - 1) & 1 ^ 1) && (k >> (E[i].v - 1) & 1 ^ 1)) s += E[i].w;
            }
            if (!ok) continue;
            for (int i = 1; i <= n; i++)
                if (k >> (i - 1) & 1) s += a[i];
            sum += qpow(s, ::k);
            sum %= mod;
        }
        return sum;
    }
    void dfs(int cnt, int lst) {
        if (cnt >= p) {
            (ans += calc()) %= mod, cc += 1;
            return;
        }
        for (int i = lst + 1; i <= n + m; i++) {
            if (i <= n) a[i] += t;
            else E[i - n].w += t;
            dfs(cnt + 1, i);
            if (i <= n) a[i] -= t;
            else E[i - n].w -= t;
        }
    }
    int main() {
        // int d = (C[n + m][p] - C[n + m - 1][p] + mod) % mod * qpow(C[n + m][p], mod - 2) % mod * t % mod;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> E[i].u >> E[i].v >> E[i].w;
        // t = 0;
        dfs(0, 0);
        cout << ans * qpow(cc, mod - 2) % mod << '\n';
        return 0;
    }
}  // namespace Sub1
// namespace Sub2 {
//     int b[N], dp[N];
//     int main() {
//         for (int i = 1; i <= n; i++) cin >> a[i];
//         bool f = 1;
//         for (int i = 1, u, v, w; i <= m; i++) cin >> u >> v >> w, f &= (abs(v - u) == 1), b[min(u, v)] = w;
//         for (int i = 1; i <= n; i++) b[i] += b[i - 1];
//         if (!f) return;
//         for (int i = 1; i <= n; i++) dp[i] = a[i] + (i <= 2 ? 0 : b[i - 2]);
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j + 1 < i; j++) {}
//         }
//     }
// }
signed main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k >> p >> t;
    // for (int i = 0; i <= 900; i++) {
    //     C[i][0] = 1;
    //     for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    // }
    // if (n <= 6 && m <= 12 && k <= 6 && p <= 6)
    Sub1::main();
    return 0;
}