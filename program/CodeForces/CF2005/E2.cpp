#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int l, n, m; cin >> l >> n >> m;
    vector<int> idx(n * m + 1), A(l + 1);
    rep(i, 1, l) cin >> A[i];
    rep(i, 1, l) {
        if(idx[A[i]]) {
            l = i - 1;
            break;
        }
        idx[A[i]] = i;
    }

    const int INF = 1e9 ;
    vector<VI> B(n + 2, VI(m + 2, INF)), F = B, G = B;  // F 是偶数， G 是奇数
    rep(i, 1, n) rep(j, 1,  m) cin >> B[i][j];
    per(i, n, 1) per(j, m, 1) {
        F[i][j] = min(F[i + 1][j], F[i][j + 1]);
        G[i][j] = min(G[i + 1][j], G[i][j + 1]);
        if(!idx[B[i][j]]) continue;
        if((idx[B[i][j]] & 1) == 0 && idx[B[i][j]] + 3 <= G[i + 1][j + 1]) F[i][j] = min(F[i][j], idx[B[i][j]]);
        if((idx[B[i][j]] & 1) == 1 && idx[B[i][j]] + 3 <= F[i + 1][j + 1]) G[i][j] = min(G[i][j], idx[B[i][j]]);
    }
    cout << (G[1][1] == 1 ? "T" : "N") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}