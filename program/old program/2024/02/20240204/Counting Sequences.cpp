//Counting Sequences
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int n, k;
ll fac[N], inv[N];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void init(int top) {
    fac[0] = 1;
    rep(i, 1, top) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
}

ll C(int a, int b) {
    return fac[b] * inv[a] % mod * inv[b - a] % mod;
}
   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    init(max(n, k) + 5);
    // cout << qpow(k, n) << '\n';
    ll t1 = qpow(k, n); ll t2 = 0;
    for(int i = 1, p = 1; i < k; p *= -1, i++) 
        (t2 += 1ll * p * qpow(k - i, n) % mod * C(i, k) % mod) %= mod;
    cout << (t1 - t2 + mod) % mod << '\n';
    return 0;
}
