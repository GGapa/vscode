#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

constexpr int N = 1e5 + 5;

gp_hash_table<int, int> mp[N];
LL ans = 0;

struct DSU {
    vector<int> fa;
    DSU() {}
    DSU(int n) {init(n); }
    void init(int n) {
        fa.resize(n + 1); 
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(mp[x].size() < mp[y].size()) swap(mp[x], mp[y]);
        for(auto p : mp[x]) {
            ans += 1ll * p.second * mp[y][p.first];
            mp[y][p.first] += p.second;
        }
        fa[x] = y;
        return true;    
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int n;
vector<AI> G[N];
int val[N];

void dfs(int x, int fa) {
    for(auto i : G[x]) {
        int to = i[0], w = i[1];
        if(to == fa) continue;
        val[to] = val[x] ^ w;
        dfs(to, x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<tuple<int, int>> edge(1);
    for(int i = 1, u, v, w; i < n; i++) 
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w}), edge.emplace_back(u, v);
    dfs(1, 0);
    vector<int> id(n);
    rep(i, 1, n - 1) cin >> id[i];
    reverse(id.begin() + 1, id.end());

    DSU dsu(n + 1);
    rep(i, 1, n) mp[i][val[i]] = 1;
    vector<LL> aa(1, 0);
    rep(i, 1, n - 1) {
        int u, v; tie(u, v) = edge[id[i]];
        dsu.merge(u, v);
        aa.emplace_back(ans);
    }
    reverse(aa.begin(), aa.end());
    for(auto a : aa) cout << a << '\n';
    return 0;
}