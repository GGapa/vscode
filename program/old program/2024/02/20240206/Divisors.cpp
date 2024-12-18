#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;

ll n, l, r;
bool isprime[110000];

signed main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    memset(isprime, 1, sizeof(isprime));
    for (ll i = 2; i < 110001; ++i) 
        if (isprime[i])
            for (ll j = 2 * i; j < 110001; j += i)
                isprime[j] = 0;
    while (n--)
    {
        cin >> l >> r;
        ll ans = 0, nn;
        for (ll i = l; i <= r; ++i)
        {
            ll shu = 1, now = i;
            for (ll j = 2; j <= (ll)(sqrt(i)); ++j)
                if (isprime[j])
                {
                    ll num = 1;
                    while (now % j == 0) now /= j, ++num;
                    shu *= num;
                }
            if (now > 1) shu *= 2;
            if (shu > ans) ans = shu, nn = i;
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, r, nn, ans);
    }
    return 0;
}