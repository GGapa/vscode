#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

template<int siz = 4>
using AI = array<int, siz>;

constexpr int N = 2e5 + 5;

int n, m;
int deg[N];
vector<AI<4>> G[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<AI<5>> ed;
    for(int i = 1, a, b, r, p; i <= m; i++) {
        cin >> a >> b >> r >> p;
        G[b].push_back({a, r, p, i}); ed.push_back({a, b, r, p, i});
        ++deg[a];
    }

    sort(ed.begin(), ed.end(), [](const auto &x, const auto &y) {
        return x[2] > y[2];
    });

    queue<int> q;
    rep(i, 1, n) if(!deg[i]) q.emplace(i);

    vector<int> F(n + 1, INT_MAX), vis(m + 1);
    rep(now, 1, m) {
        while(q.size()) {
            int x = q.front(); q.pop();
            for(auto to : G[x]) {
                if(vis[to[3]]) continue;
                vis[to[3]] = 1;
                if(--deg[to[0]] == 0) q.emplace(to[0]);
                if(F[x] != INT_MAX) 
                    F[to[0]] = min(F[to[0]], max(to[1], F[x] - to[2]));
            }
        }
        auto e = ed[now - 1];
        if(vis[e[4]]) continue;
        vis[e[4]] = 1; --deg[e[0]];
        if(deg[e[0]] == 0) q.emplace(e[0]);
        F[e[0]] = min(F[e[0]], e[2]);
    }
    rep(i, 1, n) cout << (F[i] >= INT_MAX ? -1 : F[i]) << " \n"[i == n];
    return 0;
}