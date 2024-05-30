// Another Crisis
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N =   1e5 +5;
int F[N], nd[N];
vector<int> G[N];

int dfs(int x) {
            vector<int> rk;
            int f = 0;
            for(auto to : G[x]) {
                rk.push_back(dfs( to));
            }
            sort(rk.begin(), rk.end());
            // if(x == 0) return rk[0];
            rep(i, 0, nd[x] - 1) f += rk[i];
            if(f == 0) f = 1;
            return f;
        };

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int n, t; cin >> n >> t && n ; ) {
        rep(i, 0   , n) G[i].clear();
        fill(F, F + 1 + n, 0); fill(nd, nd + 1 + n, 0);
        for(int i = 1, x; i <= n; i++) 
            cin >> x, G[x].push_back(i);
        rep(i, 0, n) 
            nd[i] = ceil(1.0 * G[i].size() * t / 100.0);
        // rep(i, 1, n) cout << G[i].size() << " " << nd[i] << '\n'
        cout << dfs(0) << '\n';
    }
    return 0;
}