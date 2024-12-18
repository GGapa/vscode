#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    vector<LL> S(n + 1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    LL mx = 0, ans = 0, sum = 0;
    rep(i, 1, n) {
        mx = max(mx, S[i]);
        if(mx + S[n] - S[i] > sum) sum = mx + S[n] - S[i], ans = mx;
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