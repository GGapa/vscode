#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    int mx = *max_element(A.begin() + 1, A.end()), mn = *min_element(A.begin() + 1, A.end()) ;
    LL ans = 0;
    rep(i, 2, n) ans += abs(A[i] - A[i - 1]) ;
    if(mx < x) {
        int t = min(abs(x - A[1]), abs(x - A[n]));
        rep(i, 1, n) t = min(t, abs(x - A[i]) + abs(x - A[i - 1]) - abs(A[i] - A[i - 1]));
        ans += t;
    } 
    if(mn > 1) {
        int t = min(abs(1 - A[1]), abs(1 - A[n]));
        rep(i, 2, n) t = min(t, abs(1 - A[i]) + abs(1 - A[i - 1]) - abs(A[i] - A[i - 1]));
        ans += t;
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