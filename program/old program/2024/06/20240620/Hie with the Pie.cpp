#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int n;

void solve() {
    vector<VI> A(n + 1, VI(n + 1));
    rep(i, 0, n) rep(j, 0, n) cin >> A[i][j];
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) 
        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
    int m = n + 1;
    int tp = (1 << m) - 1;
    vector<VI> F(tp + 1, VI(n + 1, 1e9));
    F[1][0] = 0;
    rep(s, 1, tp) rep(i, 0, n) if((s >> i) & 1) 
        rep(j, 0, n) if(!((s >> j) & 1)) 
            F[s ^ (1 << j)][j] = min(F[s ^ (1 << j)][j], F[s][i] + A[i][j]);
    int ans = INT_MAX;
    rep(i, 1, n) ans = min(ans, F[tp][i] + A[i][0]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(; cin >> n && n ; ) solve();
    return 0;
}