//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1); 
    rep(i, 1, n) cin >> A[i];
    auto check = [&](int l, int r) {
        rep(i, l, r) rep(j, i + 1, r) rep(k, j + 1, r) {
            if((A[i] <= A[j] && A[j] <= A[k]) || (A[i] >= A[j] && A[j] >= A[k])) return 1;
        }
        return 0;
    };
    int ans = 0;
    for(int l = 1, r = 1; r <= n; r++) {
        while(l <= r && check(l, r)) l++;
        ans += r - l + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}