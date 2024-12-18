#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<LL>;
const LL INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<VI> F(n + 1, VI(m + 1, INF));
    vector<int> A(n + 1), B(m + 1);
    vector<int> S(n + 1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    rep(i, 1, m) cin >> B[i];
    F[0][1] = 0;
    rep(i, 0, n) rep(j, 1, m) {
        if(j < m) F[i][j + 1] = min(F[i][j + 1], F[i][j]);
        int t = upper_bound(S.begin(), S.end(), S[i] + B[j]) - S.begin() - 1;
        if(t == i) continue;
        F[t][j] = min(F[t][j], F[i][j] + m - j);
    }
    LL mn = INF;
    rep(i, 1, m) mn = min(mn, F[n][i]);
    if(mn >= INF) mn = -1;
    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}