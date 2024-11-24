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
    rep(i, 1, n) cin >> A[i], A[i] = min(A[i], i);
    vector<VI> F(n + 1, VI(2, -1e9));
    F[0][0] = 0;
    int mx = 0;
    rep(i, 1, n) {
        F[i][0] = F[i - 1][0] - (F[i - 1][0] > A[i]) + (F[i - 1][0] < A[i]);
        F[i][1] = F[i - 1][1] - (F[i - 1][1] > A[i]) + (F[i - 1][1] < A[i]);
        if(i > 1) F[i][1] = max(F[i][1], F[mx][0] - (F[mx][0] > A[i]) + (F[mx][0] < A[i]));
        if(F[mx][0] < F[i - 1][0]) mx = i - 1;
    }
    // cerr << F[n][1] << '\n';
    cout << max(F[mx][0], F[n][1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}