#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 1e5 + 5;

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

int n, m; 
vector<AI<2>> G[N];
int ans[N], cnt;

void dfs(int x, int fa) {
    for(auto i : G[x]) {
        int to = i[0], c = i[1];
        if(to == fa) continue;
        if(ans[x] == c) ans[to] = ans[x] == 1 ? 2 : 1;
        else ans[to] = c;
        dfs(to, x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    DSU dsu(n + 1);
    for(int i = 1, u, v, c; i <= m; i++) {
        cin >> u >> v >> c;
        if(!dsu.same(u, v)) dsu.merge(u, v), G[u].push_back({v, c}), G[v].push_back({u, c}), cnt++;
    }
    if(cnt != n - 1) return cout << "No\n", 0;
    ans[1] = 1;
    dfs(1, 0);
    rep(i, 1, n) cout << ans[i] << '\n';
    return 0;
}