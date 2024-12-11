#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 4000005, mod = 998244353;
int n, m, len, s;
int a[maxn], b[maxn], c[maxn];
int g[maxn][2];
int rev[maxn];
int diao(int x) {
    int res = 1;
    while (res <= x) res <<= 1, s++;
    return res;
}
int power(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p; b >>= 1;
    }
    return res;
}
void init() {
    len = diao(n + m + 1);
    int G = power(3, (mod - 1) / len, mod);
    int iG = power(G, mod - 2, mod);
    g[0][0] = g[0][1] = 1;
    for (int i = 1; i < len; i++) {
        g[i][0] = g[i - 1][0] * G % mod;
        g[i][1] = g[i - 1][1] * iG % mod;
        for (int j = 0; j < s; j++)
            if ((i >> j) & 1) rev[i] |= (1 << s - j - 1);
    }
}
void ntt(int *a, int p) {
    for (int i = 0; i < len; i++)
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int l = 2; l <= len; l <<= 1) {
        int m = l / 2;
        for (int i = 0; i < len; i += l)
            for (int j = 0; j < m; j++) {
                int w = a[i + j + m] * g[len / l * j][p] % mod;
                a[i + j + m] = (a[i + j] - w) % mod;
                a[i + j] = (a[i + j] + w) % mod;
            }
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= m; i++) cin >> b[i];
    init();
    ntt(a, 0); ntt(b, 0);
    for (int i = 0; i < len; i++) c[i] = a[i] * b[i] % mod;
    ntt(c, 1);
    int jaiba = power(len, mod - 2, mod);
    for (int i = 0; i <= len; i++) c[i] = c[i] * jaiba % mod;
    for (int i = 0; i <= n + m; i++) cout << (c[i] + mod) % mod << ' ';
    cout << endl;
    return 0;
}
