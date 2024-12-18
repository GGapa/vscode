#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 300 + 5;

int A[N], B[N][N];
int F[N][N][N];
int n, m, l;

int dfs(int x, int y, int k) {
    auto &f = F[x][y][k];
    if(x > n || y > m || k > l) return f = 0;
    if(f != -1) return f;
    f = 0;
    f |= dfs(x + 1, y, k);
    f |= dfs(x, y + 1, k);
    f |= dfs(x + 1, y + 1, k);
    if(B[x][y] == A[k]) f |= !dfs(x + 1, y + 1, k + 1);
    return f;
}

void solve() {
    cin >> l >> n >> m;
    rep(i, 1, n) rep(j, 1, m) rep(k, 1, l) F[i][j][k] = -1;
    rep(i, 1, l) cin >> A[i];
    rep(i, 1, n) rep(j, 1, m) cin >> B[i][j];
    cout << (dfs(1, 1, 1) ? "T" : "N") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
八步之内一定会结束游戏
*/