#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), pre(n + 1);
    rep(i ,1, n) cin >> A[i], pre[i] = pre[i - 1] ^ A[i];

    // rep(i, 1, n) cerr << pre[i] << " \n"[i == n];
    map<int, int> mp;
    LL cnt = 1;
    rep(i, 1, n) {
        (mp[pre[i - 1]] += cnt * 3 % mod) %= mod;
        cnt = 0;
        LL t = mp[pre[i]]; mp[pre[i]] = 0;
        (mp[pre[i - 1]] += t * 2 % mod) %= mod;
        (cnt += t) %= mod;
    }

    LL ans = 0;
    for(auto p : mp) (ans += p.second) %= mod;
    (ans += cnt % mod) %= mod;
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}