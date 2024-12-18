//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int N = 50 + 5;

int st[N][N][N * N];
int fx[] = {0, 1, -1, 0, 0}, fy[] = {0, 0, 0, -1, 1};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m,  K; cin >> n >> m >> K;
    int sx, sy; cin >> sx >> sy;
    vector<VI> A(n + 2, VI(m + 2, -1e17));
    rep(i, 1, n) rep(j, 1,  m) cin >> A[i][j];
    int mx = n * m;
    fill(st[0][0], st[0][0] + N * N * N * N, -1e17);
    st[sx][sy][0] = 0;
    rep(k, 0, mx) rep(i, 1, n) rep(j, 1, m) {
        if(st[i][j][k] < 0) continue;
        rep(x, 0, 4) {
            int ni = i + fx[x], nj = j + fy[x];
            st[ni][nj][k + 1]  = max(st[ni][nj][k + 1], st[i][j][k] + A[ni][nj]);
        }
    }
    int ans = 0;
    rep(k, 0, min(K, n * m)) rep(i, 1, n) rep(j, 1, m) {
        ans = max(ans, st[i][j][k] + max(K - k, 0ll) * A[i][j]);
    }
    cout << ans << '\n';
    return 0;
}