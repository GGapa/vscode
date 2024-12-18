// [ABC199D] RGB Coloring 2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 25;

ll F[N], vv[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> G(n + 1);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    vector<int> vis(n + 1);
    ll ans = 1;

    function<long long(int, int)> dp = [&](int x, int fa) -> ll{
        vis[x] = 1;
        if(F[x]) {
            vv[x][fa] = 1;
            return F[x] != F[fa];
        }
        ll f = 0;
        rep(nc, 1, 3) if(nc != F[fa]){
            F[x] = nc;
            ll cnt = 1;
            memset(vv[x], 0, sizeof(vv[x]));
            for(auto to : G[x]) if(to != fa && !vv[x][to]) {
                cnt *= dp(to, x);
            }
            f += cnt;
            F[x] = 0;
        }
        return f;
    };
    rep(i, 1, n) if(!vis[i]) {
        ans *= dp(i, 0);
    }
    cout << ans << '\n';
    return 0;
}