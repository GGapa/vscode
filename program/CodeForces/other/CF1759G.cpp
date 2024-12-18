// G. Restore the Permutation
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    int m = n / 2;
    set<int> s;
    vector<int> B(m + 1), ans(m + 1);
    rep(i, 1, n) s.insert(i);
    rep(i, 1, m) cin >> B[i];
    rep(i ,1, m) {
        if(s.count(B[i]) == 0) return cout << -1 << '\n', void();
        s.erase(B[i]);
    }
    per(i, m, 1) {
        auto it = s.upper_bound(B[i]) ;
        if(it == s.begin()) return cout << -1 << '\n', void();
        ans[i] = (*--it);
        s.erase(it);
    }
    rep(i, 1, m) cout << ans[i] << " " << B[i] << " \n"[i == m];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}