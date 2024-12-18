struct DSU {
    vector<int> sz, fa;
    vector<array<int, 2>> his;

    void init(int n) {
        sz.assign(n + 1, 1);
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }

    DSU() {}
    DSU(int n) {init(n); }

    int find(int x) {
        while(x != fa[x]) x = fa[x];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        his.push_back({x, y});
        sz[x] += sz[y];
        fa[y] = fa[x];
        return true;
    }

    int time() {return his.size(); }
    int size(int x) {return sz[x]; }
    bool same(int x, int y) {return find(x) == find(y); }

    void revert(int tim) {
        while(his.size() > tim) {
            int x = his.back()[0], y = his.back()[1];
            his.pop_back();
            fa[y] = y;
            sz[x] -= sz[y];
        }
    }
}dsu;