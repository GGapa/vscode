#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> A(n + 2);
    rep(i, 1, n) cin >> A[i];
    LL ans = 0;
    rep(i, 1, n) if(A[i] >= A[i + 1]) 
        ans += A[i] - A[i + 1];
    cout << ans << '\n';
    for(int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        if (A[l - 1] >= A[l]) ans -= (A[l - 1] - A[l]);
        if (A[l] >= A[l + 1]) ans -= (A[l] - A[l + 1]);
        if (A[r - 1] >= A[r] && r - 1 != l) ans -= (A[r - 1] - A[r]);
        if (A[r] >= A[r + 1]) ans -= (A[r] - A[r + 1]);
        swap(A[l], A[r]); 
        if (A[l - 1] >= A[l]) ans += (A[l - 1] - A[l]);
        if (A[l] >= A[l + 1]) ans += (A[l] - A[l + 1]);
        if (A[r - 1] >= A[r] && r - 1 != l) ans += (A[r - 1] - A[r]);
        if (A[r] >= A[r + 1]) ans += (A[r] - A[r + 1]);
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}