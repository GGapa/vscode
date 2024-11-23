#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int mod1 = 1e9 + 7, mod2 = 1e8 + 7;

LL qpow(LL x, LL y, int mod){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) {
            (ret = ret * x) %= mod;
        }
        (x = x * x) %= mod;
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    int p; cin >> p;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    sort(A.begin(), A.end(), greater<>());

    int s1, s2; s1 = s2 = 0;
    for(auto a : A) {
        if(s1 == 0 && s2 == 0) {
            (s1 += qpow(p, a, mod1)) %= mod1, (s2 += qpow(p, a, mod2)) %= mod2;
        }
        else  s1 = (s1 - qpow(p, a, mod1) + mod1) % mod1, s2 = (s2 - qpow(p, a, mod2) + mod2) % mod2;
    }
    cout << s1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}