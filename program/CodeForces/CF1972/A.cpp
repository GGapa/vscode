#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n ;cin >> n;
    vector<int> A(n + 1), B(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    int ans = 0;
    for(int l = 1, r = 1; r <= n && l <= n; l++) {
        while(A[l] > B[r] && r <= n) r++;
        ans = max(ans, r - l);
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