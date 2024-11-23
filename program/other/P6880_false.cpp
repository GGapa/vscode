#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 200 + 5;
constexpr LL INF = 1e18;

struct Graph {
    struct Node {int v, w, tp; };
    vector<vector<Node>> G;
    vector<vector<LL>> dis, dis2;
    vector<int> pre;
    int n;
    Graph(int nn) : n(nn), G(nn + 1), dis(nn + 1, vector<LL>(2)), pre(nn + 1) {}
    void add(int u, int v, int w, int tp) {
        G[u].push_back({v, w, tp});
    }
    void Dijkstra(int st) {
        rep(i, 1, n) dis[i][0] = dis[i][1] = INF;
        dis2 = dis;
        fill(pre.begin(), pre.end(), 0);

        priority_queue<array<LL, 3>> q;
        q.push({-0, st, 0});
        dis[st][0] = 0;

        while(!q.empty()) {
            int x = q.top()[1], j = q.top()[2]; LL val = -q.top()[0];
            q.pop();
            if(val > dis[x][j]) continue;
            for(auto i : G[x]) {
                if(j == 1 && i.tp == 1) continue;
                int to = i.v;
                if(dis[to][i.tp + j] > dis[x][j] + i.w) {
                    // if(dis2[to][i.tp + j] > dis[to][i.tp + j]) 
                    dis2[to][i.tp + j] = dis[to][i.tp + j];
                    dis[to][i.tp + j] = dis[x][j] + i.w; 
                    pre[to] = x;
                    q.push({-dis[to][i.tp + j], to, i.tp + j});
                }
                else if(dis[to][i.tp + j] == dis[to][i.tp] + j && pre[to] != x) {
                    dis2[to][i.tp + j] = dis[to][i.tp] + j;
                } 
            }
        }
    }
};

int n, m;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    Graph g1(n), g2(n), g3(n), g4(n), g5(n * 2);   // 正图，反图，solve
    vector<array<int, 4>> edge;
    for(int i = 1, u, v, c, d; i <= m; i++) {
        cin >> u >> v >> c >> d;
        edge.push_back({u, v, c, d});
        g1.add(u, v, c, 0); g2.add(u, v, c, 0);
        g3.add(v, u, c, 0); g4.add(v, u, c, 0);
        g5.add(u, v, c, 0); g5.add(v, u, c + d, 1);
        g5.add(u + n, v + n, c, 0); g5.add(v + n, u + n, c + d, 1);
    }
    g5.add(n, 2 * n, 0, 0);

    LL ans = LLONG_MAX;
    g5.Dijkstra(n + n);
    ans = min(g5.dis[1 + n][0], g5.dis[1 + n][1]);
    // cerr << g5.dis[n + 1][0] << '\n';

    g1.Dijkstra(1), g2.Dijkstra(n), g3.Dijkstra(1), g4.Dijkstra(n);

    for(auto e : edge) {
        int u = e[0], v = e[1]; LL w = e[2] + e[3];
        LL v1 = (g1.pre[v] == u ? g1.dis2[v][0] : g1.dis[v][0]) + (g4.pre[u] == v ? g4.dis2[u][0] : g4.dis[u][0]);
        LL v2 = (g2.pre[v] == u ? g2.dis2[v][0] : g2.dis[v][0]) + (g3.pre[u] == v ? g3.dis2[u][0] : g3.dis[u][0]);
        ans = min(ans, v1 + v2 + e[2] + e[2] + e[3]);
        cerr << u << " " << v << " " << v1 + v2 << '\n';
    }

    cout << ans << '\n';
    return 0;
}