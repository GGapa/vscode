// Distributing Apples 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> inv(n + m + 1), F(n + m + 1), invf(n + m + 1);
    inv[1] = F[1] = invf[1] = 1;
    inv[1] = invf[1] = F[1] = 1;
    inv[0] = invf[0] = F[0] = 1;
    rep(i, 2, n + m) {
        (inv[i] = (mod - mod / i) * inv[mod % i]) %= mod;
        F[i] = F[i - 1] * i % mod; invf[i] = invf[i - 1] * inv[i] % mod;
    }
    cout << F[n + m - 1] * invf[n - 1] % mod * invf[m] % mod<< '\n';
    return 0;
}