#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> B(n + 2);
    rep(i ,1, n - 1) cin >> B[i];
    vector<int> ans(1);
    ans.push_back(B[1]);
    B[n + 1] = (1 << 30) - 1;
    rep(i, 1, n - 1) {
        int t = B[i] | B[i + 1];
        ans.push_back(t);
        // else ans.push_back(B[i]);
    }
    // rep(i ,1, n) cout << ans[i] << " \n"[i == n];
    rep(i ,1, n - 1) if((ans[i] & ans[i + 1]) != B[i]) return cout << "-1\n", void();
    rep(i ,1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}