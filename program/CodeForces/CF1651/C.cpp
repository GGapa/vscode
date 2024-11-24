#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<LL> A(n + 1), B(n + 1);
    rep(i ,1 ,n) cin >> A[i];
    rep(i ,1, n) cin >> B[i];
    LL a1, a2, a3, a4; a1 = a2 = a3 = a4 = INT_MAX;
    rep(i ,1, n) {
        a1 = min(a1, abs(A[1] - B[i])); a2 = min(a2, abs(A[n] - B[i]));
        a3 = min(a3, abs(A[i] - B[1])); a4 = min(a4, abs(A[i] - B[n]));
    }
    LL ans = a1 + a2 + a3 + a4;
    ans = min(ans, abs(A[1] - B[1]) + abs(A[n] - B[n]));
    ans = min(ans, abs(A[1] - B[1]) + a2 + a4);
    ans = min(ans, abs(A[n] - B[n]) + a1 + a3);
    ans = min(ans, abs(A[1] - B[n]) + a2 + a3);
    ans = min(ans, abs(A[n] - B[1]) + a1 + a4);
    ans = min(ans, abs(A[1] - B[n]) + abs(A[n] - B[1])) ;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}