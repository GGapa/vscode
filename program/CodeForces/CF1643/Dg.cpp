#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n * 2 + 1), B(n  +1);
    rep(i, 1, n) cin >> B[i], A[B[i]] = 1;
    int mx = 0, mn = INT_MAX, cnt = 0;
    rep(i, 1, 2 * n) {
        cnt += (A[i] == 1) - (A[i] == 0);
        mx = max(mx, cnt);
        mn = min(mn, cnt);
    }
    cout << n - (mx - mn) + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   
    int T; cin >> T;
    while(T--) solve();
    return 0;
}