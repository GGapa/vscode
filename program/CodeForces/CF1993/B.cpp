#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n +1);
    rep(i, 1, n) cin >> A[i];
    bool tag = 1;
    rep(i, 2, n) if(A[i] % 2 != A[1] % 2) tag=  0;
    if(tag) return cout << 0 << '\n', void();
    sort(A.begin() + 1, A.end());
    const int INF = 1e18;
    int mx = -INF;
    int ans = 0, r = 0;
    per(i, n, 1) {
        if(A[i] % 2) r = max(r, i), mx = max(mx, A[i]);
        if(A[i] % 2 == 0 ) {
            ans++;
            if(mx > A[i]) mx = max(mx, mx + A[i]);
        } 
    }

    rep(i, r + 1, n) if(A[i] % 2 == 0 && mx > A[i]) {
        r = i;
        mx = max(mx, A[i] + mx);
    }
    if(r != n) ans++;
    cout << ans<< '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}