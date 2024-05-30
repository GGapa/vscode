// divide
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map<ll, ll> A;
    ll n, k, p, x; 
    cin >> n >> k >> p;
    vector<ll> F(n + 1), S(k * 2 + 2);
    F[0] = S[0] = 1;
    rep(i, 1, n) F[i] = 1ll * F[i - 1] * 2 % p;
    ll ans = 0;
    rep(i, 1, n) {
        cin >> x;
        ll a = x / k, b = x % k;
        (ans += 1ll * a * F[n - 1] % p) %= p;
        per(j, k - 1, 0) (S[j + b] += S[j]) %= p;
        rep(j, k, 2 * k - 1) {
            (ans += 1ll * S[j] * F[n - i] % p) %= p;
            (S[j - k] += S[j]) %= p;
            S[j] = 0;
        }
    }   
    cout << ans << '\n';

    return 0;
}
