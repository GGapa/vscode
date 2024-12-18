// Placing Lampposts
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
const int N = 1000 + 5;
const int INF = 2000;
int n, m;
vector<int> G[N];
int F[N][2];    // i 选不选的最大结果

int dfs(int i, int j, int fa) {
    auto &f = F[i][j];
    if(f != -1) return f;
    f = INF;
    for(auto to : G[i]) if(to != fa) {
        f += dfs(to, 1, i);
    }
    if(!j && fa >= 0) f++; 
    if(j || fa < 0) {
        int nf = 0;
        for(auto to : G[i]) if(to != fa) {
            nf += dfs(to, 0, i);
        }
         if(fa >= 0) nf++;
        f = min(f, nf);
    }
    return f;
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) G[i].clear(); 
    memset(F, -1, sizeof(F)); 
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
    int ans = 0;
    rep(i, 1, n) if(F[i][0] == -1) ans += dfs(i, 0, -1);
    cout << ans / INF << " " << m - ans % INF << " " << ans % INF << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve ();
    return 0;
}