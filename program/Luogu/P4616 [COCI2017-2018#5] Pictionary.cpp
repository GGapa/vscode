#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct DSU {
    vector<int> fa, sz, num;
    DSU() {}
    DSU(int n) {init(n); }
    void init(int n) {
        fa.resize(n + 1);  sz.assign(n + 1, 1); num.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y, int id = 0) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] > sz[y]) swap(x, y);
        fa[x] = y;
        sz[y] += sz[x];
        num[x] = id;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int get(int x, int y) {
        set<int> s;
        int t = x;
        while(x != fa[x]) {
            s.emplace(x);
            if(fa[x] == y) return num[x];
            x = fa[x];
        }
        s.emplace(x); 
        x = y;
        while(s.count(fa[x]) == 0) x = fa[x];
        swap(x, t);
        if(fa[t] == x) return num[t];
        while(fa[x] != fa[t] && fa[x] != t) x = fa[x];
        return max(num[x], num[t]);
    }
};

signed main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    DSU dsu(n);
    rep(i, 1, m) {
        int t = m - i + 1;
        for(int j = t; j + t <= n; j += t) dsu.merge(t, j + t, i);
    }

    for(int x, y; q--; ) {
        cin >> x >> y;
        // cerr << x << " " << y << '\n';
        cout << dsu.get(x, y) << '\n';
    }
    return 0;
}