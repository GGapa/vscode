#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B = A;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    LL ans = 0;
    rep(i ,1, n - 1) 
        ans += min(abs(A[i] - A[i + 1]) + abs(B[i] - B[i + 1]), abs(A[i] - B[i + 1]) + abs(B[i] - A[i + 1])) ;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}