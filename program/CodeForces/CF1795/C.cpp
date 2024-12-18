#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n +1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    vector<LL> S(n + 1), ans(n + 3), cnt(n + 3);
    rep(i, 1, n) S[i] = S[i - 1] + B[i];
    rep(l, 1, n) {
        int r = upper_bound(S.begin() + 1, S.end(), S[l - 1] + A[l]) - S.begin();
        cnt[l]++, cnt[r]--; ans[r] += A[l] - S[r - 1] + S[l - 1];
        cnt[l] += cnt[l - 1];
    }
    rep(i, 1, n) {
        cout << ans[i] + cnt[i] * B[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}