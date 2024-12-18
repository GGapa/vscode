#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3, MAXM = 1e5;
const int MOD = 998244353;

int n, m, t, a[MAXN + 5];

int inv(int x)
{
    int res = 1, b = MOD - 2;
    while (b)
    {
        if (b & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        b >>= 1;
    }
    return res;
}

void solve3()
{
    static int x[MAXM + 5], y[MAXM + 5], z[MAXM + 5];
    int w = inv(m); w = 1ll * w * w % MOD;
    for (int i = 1; i < m; i++)
        x[i] = 2ll * i * (m - i) % MOD * w % MOD, y[i] = 1ll * i * i % MOD * w % MOD, z[i] = 1ll * (m - i) * (m - i) % MOD * w % MOD;

    static int k[MAXM + 5], b[MAXM + 5];
    for (int i = 1; i < m; i++)
    {
        int d = inv((1 + MOD - x[i] + MOD - 1ll * y[i] * k[i - 1] % MOD) % MOD);
        k[i] = 1ll * z[i] * d % MOD;
        b[i] = (1ll * y[i] * b[i - 1] + 1) % MOD * d % MOD;
    }

    static int f[MAXM + 5];
    f[0] = 0;
    for (int i = m - 1; i >= 0; i--) f[i] = (1ll * k[i] * f[i + 1] + b[i]) % MOD;
    assert(f[0] == 0);

    while (t--)
    {
        static int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", f[a]);
    }
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &t);

    if (n == 2) solve3();

    return 0;
}