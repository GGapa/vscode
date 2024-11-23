#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), pre(n + 1), itt(n + 1);
    rep(i, 1, n) cin >> A[i], pre[i] = itt[A[i]], itt[A[i]] = i;
    vector<int> S(n + 1), F(n + 1);
    int ans = 0;
    rep(i, 1, n) {
        F[i] = (!pre[i] || S[pre[i] - 1] < S[i - 1]) ;
        S[i] = S[i - 1] + F[pre[i]];
        if(F[pre[i]]) ans = i;
    }
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