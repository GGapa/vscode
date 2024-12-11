// P9869 [NOIP2023] 三值逻辑
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5, U = 0, T = 1e5 + 1, F = -T; 

int Fa[N * 3], vis[N * 3];
int n, m;

int find(int x) {
    int res ;
    if(x == T || x == F || x == U) return x;
    else if(vis[n - x]) return U;
    else if(vis[n + x]) return T;
    else if(x < 0) {
        if(x == -Fa[-x]) return x;
        vis[x + n] = 1;
        Fa[-x] = res = find(-Fa[-x]);
        vis[x + n] = 0;
    }
    else {
        if(x == Fa[x]) return x;
        vis[x + n] = 1;
        Fa[x] = res = find(Fa[x]);
        vis[x + n] = 0;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    char c;
    iota(Fa + 0, Fa + N, 0);
    memset(vis, 0, sizeof(vis));
    for(int i = 1, x, y; i <= m; i++) {
        cin >> c >> x;
        if(c == 'T') Fa[x] = T;
        else if(c == 'F') Fa[x] = F;
        else if(c == 'U') Fa[x] = U;
        else if(c == '+') cin >> y, Fa[x] = Fa[y];
        else cin >> y, Fa[x] = -Fa[y];
    }
    int ans = 0;
    rep(i, 1, n) ans += (find(i) == U) ;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, t; cin >> c >> t;
    while(t--) solve();
    return 0;
}