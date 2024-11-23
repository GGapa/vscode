#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    int ans = 0, mn = n + 1;
    for(int i = 1; i <= n; i++) {
        int t = upper_bound(A.begin() + 1, A.end(), i) - A.begin() - 1;
        mn = min(mn, t - i + 1);
        if(mn <= i - 1) break;
        ans = max(i, ans);
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