#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int unsigned long long
using VI = vector<int>;
const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    ll ans = 0;
    rep(i, 2, n) (ans += A[i] * (i - 1) % mod) %= mod;
    vector<int> cnt(20);
    per(i, n, 1) {
        for(ll j = 1, t = 10; j <= 11; j++, t *= 10) if(cnt[j] != 0){
            (ans += (1ll * A[i] * t % mod * cnt[j] % mod)) %= mod;
        }
        cnt[to_string(A[i]).size()]++;
    }
    cout << ans % mod << '\n';
    return 0;
}
