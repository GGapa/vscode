//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    if(k % 2) return cout << "No\n", void();
    vector<int> ans(n + 1);
    rep(i, 1, (n + 1) /2) {
        if(k == 0) break;
        int c = i + k / 2;
        // if(c > n) return cout << "No\n", void();
        c = min(c, n - i + 1);
        ans[i] = c, ans[c] = i;
        k -= 2 * abs(c - i);
    }
    rep(i, 1, n) if(!ans[i]) ans[i] = i;
    if(k > 0) return cout << "No\n", void();
    cout << "Yes\n";
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}