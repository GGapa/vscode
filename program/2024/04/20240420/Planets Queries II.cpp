// Planets Queries II
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 2e5 + 5, L = 20;

int F[N][L + 1], D[N], vis[N];

void dfs(int x) {
    if(vis[x]) return ;
    vis[x] = 1;
    dfs(F[x][0]), D[x] = D[F[x][0]] + 1;
}

int lift(int x, int d) {
    if(d <= 0) return x;
    for(int i = 0; d > 0; d >>= 1, i++) 
        if(d & 1) x = F[x][i];
    return x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    rep(i, 1, n) cin >> F[i][0];
    rep(j, 1, L) rep(i ,1, n) F[i][j] = F[F[i][j - 1]][j - 1];
    rep(i, 1, n) if(!vis[i]) dfs(i);
    for(int x, y; q--; ) {
        cin >> x >> y;
        int &dx = D[x], &dy = D[y], ans = - 1, c = lift(x, dx); 
        // cout << D[c] << '\n';
        if(dx >= dy && lift(x, dx - dy) == y) ans = dx - dy;
        else if(lift(c, D[c] - dy) == y) ans = dx + D[c] - dy;
        cout << ans << '\n';
    }
    return 0;
}