// ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 250010
using namespace std;
ll fact[N], inv[N], inv_fac[N];
ll C(ll x, ll y) { return (x < y || x < 0 || y < 0) ? 0 : (fact[x] * ((inv_fac[y] * inv_fac[x - y]) % mod)) % mod; }
ll n, k, cnt[3], a[3][3];
string s;
int main()
{
    ll i, j, l, p;
    fact[0] = inv_fac[0] = inv[1] = inv_fac[1] = fact[1] = 1;
    for (i = 2; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = (inv[mod % i] * (mod - mod / i)) % mod;
        inv_fac[i] = (inv_fac[i - 1] * inv[i]) % mod;
    }
    cin >> n >> k >> s;
    for (i = 0; i < n; i++)
    {
        cnt[s[i] - 'A']++;
    }
    ll ans = 0;
    i = j = l = 0;
    for (i = 0; i <= k; i++)
    {
        for (j = 0; j + i <= k; j++)
        {
            for (l = 0; l + j + i <= k; l++)
            {
                a[0][1] = a[1][0] = i;
                a[0][2] = a[2][0] = j;
                a[1][2] = a[2][1] = l;
                for (p = 0; p * 2 + l + j + i <= k; p++)
                {
                    ll coefa = (C(cnt[0], a[0][2]) * C(cnt[0] - a[0][2], a[0][1] + p)) % mod;
                    ll coefb = (C(cnt[1], a[1][0]) * C(cnt[1] - a[1][0], a[1][2] + p)) % mod;
                    ll coefc = (C(cnt[2], a[2][1]) * C(cnt[2] - a[2][1], a[2][0] + p)) % mod;
                    ans = (ans + ((coefa * coefb) % mod) * coefc) % mod;
                }
                for (p = 1; p * 2 + l + j + i <= k; p++)
                {
                    ll coefa = (C(cnt[0], a[0][2] + p) * C(cnt[0] - a[0][2] - p, a[0][1])) % mod;
                    ll coefb = (C(cnt[1], a[1][0] + p) * C(cnt[1] - a[1][0] - p, a[1][2])) % mod;
                    ll coefc = (C(cnt[2], a[2][1] + p) * C(cnt[2] - a[2][1] - p, a[2][0])) % mod;
                    ans = (ans + ((coefa * coefb) % mod) * coefc) % mod;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}