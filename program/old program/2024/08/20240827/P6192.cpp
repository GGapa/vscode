#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 100 + 5, INF = 1e9;

vector<pair<int, int>> G[N];
int n, m, k;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, u--, v--, G[u].emplace_back(v, w), G[v].emplace_back(u, w) ;
    vector<int> sp(k + 1); 
    rep(i, 0, k - 1) cin >> sp[i], sp[i]--;
    int tp = (1 << k) - 1;
    vector<VI> F(tp + 1, VI(n + 1, INF));
    rep(i, 0, k - 1) F[1 << i][sp[i]] = 0;
    auto work = [&](int s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        rep(i, 0, n - 1) q.push({F[s][i], i}) ;
        while(!q.empty()) {
            int x = q.top().second, nw = q.top().first; q.pop();
            if(nw > F[s][x]) continue;
            for(auto i : G[x]) {
                int to = i.first, w = i.second ;
                if(F[s][to] > F[s][x] + w) {
                    F[s][to] = F[s][x] + w;
                    q.push({F[s][to], to}) ;
                }
            }
        }
    };
    fill(F[0].begin(), F[0].end(), 0);
    rep(i, 1, tp) {
        for(int j = i & i; j; j = (j - 1) & i) {
            rep(k, 0, n - 1) 
                F[i][k] = min(F[i][k], F[j][k] + F[i ^ j][k]);
        }
        work(i);    
    }
    int ans = INF;
    rep(i, 0, n - 1) ans = min(ans, F[tp][i]);
    cout << ans << '\n';
    return 0;
}
/*
F[S][i] 为当前特殊点的点集为 S，顶点为 i 的最小代价。
*/