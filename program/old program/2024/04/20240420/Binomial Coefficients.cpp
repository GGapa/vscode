// Binomial Coefficients
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e6;
const int mod = 1e9 + 7;

ll inv[N + 1], mul[N + 1];

ll qpow(ll x, ll y) {
    ll ans = 1;
    for(; y; y >>= 1) {
        if(y & 1) (ans = ans * x) %= mod;
        (x = x * x) %= mod;
    }
    return ans;
}

void init() {
    mul[0] = inv[0] = 1;
    rep(i, 1, N) {
        mul[i] = (mul[i - 1] * i) % mod;
        inv[i] = qpow(mul[i], mod - 2);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int n; cin >> n;
    for(int x, y, i = 1; i <= n; i++ ) {
        cin >> x >> y;
        cout << mul[x] * inv[y] % mod * inv[x - y] % mod<< '\n';
    }

    return 0;
}