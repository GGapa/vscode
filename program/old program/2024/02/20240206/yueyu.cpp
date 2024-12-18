//越狱 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int mod = 100003;

ll m, n;


ll qpow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << qpow(2, 4) << '\n';
    cin >> m >> n;
    cout << ((qpow(m, n) - m * qpow(m - 1, n - 1) % mod) + mod) % mod;
    return 0;
}