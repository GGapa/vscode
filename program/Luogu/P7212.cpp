#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

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
        fa[x] = y;
        return true;    
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    
    DSU dsu(n + 1);
    vector<int> siz(n + 1, 1);
    vector<set<int>> in(n + 1), out(n + 1); // Node point to clique and outedge
    LL ans = 0;
    rep(i, 1, n) in[i].insert(i);
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        int x = dsu.find(u), y = dsu.find(v);

        function<void(int, int)> merge = [&](int u, int v) {
            u = dsu.find(u), v = dsu.find(v);
            if(u == v) return ;
            if(in[u].size() + out[u].size() < in[v].size() + in[v].size()) swap(u, v);
            ans -= 1ll * siz[u] * in[u].size() + 1ll * siz[v] * in[v].size();

            vector <int> nxt;
            for(auto x : out[v]) if(out[x].count(u))
                nxt.push_back(x);
            for(int x : in[v]) {    // x can arrive clique v
                x = dsu.find(x);
                if(out[u].count(x)) nxt.push_back(x);   // u -> x -> v so {u, x, v} in the same clique
                out[x].erase(v), out[x].insert(u);      // u and v will merge so clique x must not have v but have u
            }
            dsu.fa[v] = u, siz[u] += siz[v];
            for (int x : in[v]) in[u].insert(x);
            for (int x : out[v]) out[u].insert(x);
            ans += 1ll * siz[u] * in[u].size();
            for (int x : nxt) merge(u, x);
        } ;

        if (x != y) {
            if (!out[y].count(x)) {     // clique y don't have edge with clique x (this means that x and y is not a clique)
                if (!in[y].count(u))    // node u is not belong to clique y
                    ans += siz[y], in[y].insert(u), out[x].insert(y);   // u can arrive clique and clique x's neighborhood have y
            }
            else merge(u, v);   // two clique can be reached with each other, need merge.
        }

        cout << ans << '\n';
    }
 

    return 0;
}