//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

map<ll, int> mp;
vector<int> A;
void solve() {
    mp.clear();
    int n; cin >> n;
    A.assign(n + 1, 0);
    ll s = 0;
    rep(i, 1, n) cin >> A[i], s += A[i];
    if((2.0 * s / n) != (int)2 * s / n) return cout << 0 << '\n', void();
    int t = 2 * s / n;
    ll ans = 0;
    rep(i, 1, n) {
        int x = A[i];
        ans += mp[t - x];
        mp[x]++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}