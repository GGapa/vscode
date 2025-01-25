#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; LL k; cin >> n >> k;
    vector<LL> inv(n + 2); inv[1] = 1; 
    LL x = (k + 1) % mod, ans = 0;
    rep(i, 2, n + 1) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    rep(i, 0, n) {
        ans = (ans + x) % mod;
        x = x * inv[i + 1] % mod * (n - i) % mod * inv[i + 2] % mod * ((k - i) % mod) * 2 % mod;
    }
    cout << ans << '\n';

    return 0;
}