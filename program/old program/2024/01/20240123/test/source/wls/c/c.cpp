#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10, S = 2e3 + 10, mod = 998244353;
int n, m, t, cnt;
unordered_map<int, int> mp;
int st[S];
int qpow(int a, int b) {
    int res = 1;
    for (; b; a = a * a % mod, b >>= 1)
        if (b & 1) res = res * a % mod;
    return res;
}
void init(int dep, int sum, int sta) {
    if (dep > n) {
        if (sum == m) mp[sta] = ++cnt, st[cnt] = sta;
        return;
    }
    for (int i = 0; sum + i <= m; i++) init(dep + 1, sum + i, sta * (m + 1) + i);
}
int a[N], pw[N];
int A[S][S], B[S];
bool gauss() {
    for (int i = 1; i <= cnt; i++) {
        int p = -1;
        for (int j = i; j <= cnt; j++) {
            if (A[j][i] != 0) {
                p = j;
                break;
            }
        }
        if (p == -1) return 0;
        swap(A[p], A[i]), swap(B[p], B[i]);
        for (int j = 1; j <= cnt; j++) {
            if (j == i) continue;
            int d = A[j][i] * qpow(A[i][i], mod - 2) % mod;
            for (int k = 1; k <= cnt; k++) (A[j][k] += mod - d * A[i][k] % mod) %= mod;
            (B[j] += mod - d * B[i] % mod) %= mod;
        }
    }
    for (int i = 1; i <= cnt; i++) (B[i] *= qpow(A[i][i], mod - 2)) %= mod;
    return 1;
}
int tmp[N], tmp2[N * N];
signed main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> t;
    for (int i = pw[0] = 1; i <= n; i++) pw[i] = pw[i - 1] * (m + 1);
    init(1, 0, 0);
    for (int k = 1; k <= cnt; k++) {
        int s = st[k], c1 = 0;
        for (int i = n; i >= 1; i--) a[i] = s % (m + 1), s /= (m + 1), c1 += (a[i] > 0);
        int e = 0, e2 = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= a[i]; j++) tmp[++e] = i;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m - a[i]; j++) tmp2[++e2] = i;
        A[k][k] = B[k] = 1;
        if (c1 == 1) {
            B[k] = 0;
            continue;
        }
        for (int ii = 1; ii <= e; ii++) {
            for (int jj = 1; jj <= e2; jj++) {
                int i = tmp[ii], j = tmp2[jj];
                int nk = mp[st[k] - pw[n - i] + pw[n - j]];
                A[k][nk] += mod - qpow(m * m % mod * (n - 1) % mod, mod - 2);
                (A[k][nk] >= mod) && (A[k][nk] -= mod);
            }
        }
    }
    gauss();
    while (t--) {
        int sta = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sta = sta * (m + 1) + a[i];
        cout << B[mp[sta]] << '\n';
    }
    return 0;
}