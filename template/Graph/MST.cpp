array<int, 3> E[M];
int vis[M];
ll mns = 0;
namespace kruskal {
    vector<int> fa;
    int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;
    }
    void work() {
        sort(E + 1, E + 1 + m);
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(0), 0);
        int cnt = 1;
        rep(i, 1, m) {
            int x = E[i][1], y = E[i][2];
            if(merge(x, y)) mns += E[i][0], cnt++, G[x].push_back({y, E[i][0]}), G[y].push_back({x, E[i][0]});
            if(cnt == 0) break;
        }
    }
}