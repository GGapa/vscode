#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1) ;
    LL ans = 0;
    rep(i, 1, n) cin >> A[i]; 
    rep(i, 1, n) cin >> B[i];
    ans = accumulate(A.begin() + 1, A.end(), 0ll) + accumulate(B.begin(), B.end(), 0ll) - *max_element(B.begin() + 1, B.end());
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