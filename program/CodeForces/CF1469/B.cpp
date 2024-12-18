#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    cin >> m;
    vector<int> B(m + 1);
    rep(i, 1, m) cin >> B[i];
    int a1 = 0, a2 = 0;
    for(int i = 1, x = 0; i <= n; i++) {
        x += A[i];
        a1 = max(x, a1);
    }
    for(int i = 1, x = 0; i <= m; i++) {
        x += B[i];
        a2 = max(a2, x);
    }
    cout << a1 + a2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}