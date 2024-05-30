// Creating Strings II
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e6 + 5, mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    vector<ll> F(N), inv(N), invf(N);
    inv[1] = invf[1] = F[1] = 1;
    rep(i, 2, n) {
        (inv[i] = (mod - mod / i) * inv[mod % i]) %= mod;
        F[i] = F[i - 1] * i %  mod; invf[i] = invf[i - 1] * inv[i] % mod;
    }
    unordered_map<char, int> mp;
    for(auto c : s) mp[c]++;
    ll ans = F[s.size()];
    for(auto i : mp) (ans *= invf[i.second]) %= mod;
    cout << ans << '\n';
    return 0;
}