#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e6 + 5;

LL cnt[N];

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    vector<LL> F(n + 1);
    LL mx = 0;
    fill(cnt, cnt + N, -1e18);
    rep(i, 1, n - 1) {
        F[i] = max(F[i], mx - (A[i] == A[i + 1]) * A[i]);
        F[i] = max(F[i], cnt[A[i + 1]] + A[i + 1] - (A[i] == A[i + 1]) * A[i]);
        cnt[A[i]] = max(cnt[A[i]], F[i]); mx = max(mx, F[i]);
    }
    LL ans = 0;
    rep(i, 1, n) if(A[i] == A[i - 1]) ans += A[i];
    cout << *max_element(F.begin(), F.end()) + ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}