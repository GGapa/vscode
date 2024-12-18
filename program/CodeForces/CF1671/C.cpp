#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n + 1);
    vector<LL> S(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end()) ;
    rep(i, 1, n) S[i] = S[i - 1] + A[i];
    LL ans = 0, day = 0;
    per(i, n, 1) {
        if(S[i] + day * i > x) continue;
        LL t = (x - S[i] - day * i) / i + 1;
        day += t;
        ans += t * i;
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