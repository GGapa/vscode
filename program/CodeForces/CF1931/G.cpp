#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int CC = 4e6 + 5;

ll qpow(ll x, ll y) {
    ll sum = 1;
    while(y) {
        if(y & 1) (sum = sum * x) %= mod;
        (x = x * x) %= mod;
        y >>= 1;
    }
    return sum % mod;
}

vector<ll> mul, inv;

void init() {
    mul.push_back(1); 
    inv.push_back(1); 
    rep(i, 1, CC + 2) {
        mul.push_back((mul[i - 1] * i) % mod);
        inv.push_back(qpow(mul[i], mod - 2) % mod);
    }

}

ll C(int n, int m) {
	return mul[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
    int c1, c2, c3, c4; 
    cin >> c1 >> c2 >> c3 >> c4;
    if(abs(c1 - c2) > 1) cout << "0\n";
    else if(c1 == c2) {
        if(!c1) cout << (c3 && c4  ? 0 : 1) << '\n';
        else cout << (C(c3 + c1, c1) * C(c4 + c1 - 1, c1 - 1) % mod + C(c3 + c1 - 1, c1 - 1) * C(c4 + c1, c1) % mod) % mod << '\n';
    }
    else if(c1 == c2 + 1) cout << C(c1 + c3 - 1, c1 - 1) * C(c1 + c4 - 1, c1 - 1) % mod << '\n';
    else  cout << C(c1 + c3 , c1 ) * C(c1 + c4 , c1 ) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init(); 
    int T; cin >> T;
    while(T--) solve();
    return 0;
}