//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int mod = 998244353;
const int N = 2e5 + 5;

ll qpow(ll x, ll y) {
    ll ret = 1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x)  %= mod;
    } 
    return ret;
}

ll mul[N], inv[N];

void init() {
    mul[0] = inv[0] = 1;
    rep(i ,1, N - 5) (mul[i] = mul[i - 1] * i) %= mod;
    inv[N - 5] = qpow(mul[N - 5], mod - 2);
    per(i, N - 5 - 1, 1) (inv[i] = inv[i + 1] * (i + 1)) %= mod;
}

ll C(int n, int m) {
    if(m == 0 || n == m) return 1;
    return mul[n]  * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    sort(A.begin() + 1, A.end(), greater<>());
    if(A[1] == A[2]) return cout << mul[n] << '\n', void();
    if(A[1] - 1 != A[2]) return cout << 0 << '\n', void();
    int ct=  0;
    rep(i, 3, n) if(A[i] != A[2]) ct++;
    ll ans = 0;
    per(i, n, n - ct) {
        (ans += mul[i - 1] * C(ct, n - i) % mod * mul[n - i] % mod) %= mod;
    }
    cout << (mul[n] - ans + mod) % mod << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T;cin >> T;
    while(T--) solve() ;
    return 0;
}
/*
120
48
12
*/