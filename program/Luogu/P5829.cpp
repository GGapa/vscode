#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 5, B = __lg(N) + 1;
vector<int> G[N];
int n;

namespace LCA {
    int dfn[N], mn[B][N];
 
    void dfs(int x, int pa) {
        dfn[x] = ++dfn[N - 1]; mn[0][dfn[x]] = pa;
        for(auto to : G[x]) if(to != pa) dfs(to, x);
    }
 
    int get(int x, int y) {return (dfn[x] < dfn[y] ? x : y); }
 
    void init(int rt) {   
        dfs(rt, 0);
        n += 5;
        rep(i, 1, B - 1) for(int j = 1; j + (1 << i) - 1 <= n; j++) 
            mn[i][j] = get(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
        n -= 5;
    }
 
    int lca(int x, int y) {
        if(x == y) return x;
        if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
        int d = __lg(y - x++);
        // cerr << d << '\n';
        // cerr << x << " " << y << '\n';
        // cerr << mn[d][x] << " " << mn[d][y - (1 << d) + 1] << '\n';
        return get(mn[d][x], mn[d][y - (1 << d) + 1]);
    }
}
using LCA::lca;

signed main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s; 
    n = s.size(); s = " " + s;
    vector<int> nxt(n + 1);
    
    G[1].emplace_back(0); G[0].emplace_back(1);
    for(int i = 2, j = 0; i <= n; i++) {
        for(; j && s[i] != s[j + 1]; j = nxt[j]) ;
        j += (s[i] == s[j + 1]);
        nxt[i] = j; G[i].emplace_back(j), G[j].emplace_back(i);
    }

    LCA::init(0);
    int q; cin >> q;
    for(int x, y; q--; ) {
        // cerr << q << '\n';
        cin >> x >> y;
        int t = lca(x, y);
        // cerr << lca(y - 2, y) << '\n';
        if(x == t || y == t) cout << nxt[lca(x, y)] << '\n';
        else cout << t << '\n';
    }
    return 0;
}
/*
g++ P5829.cpp -o P5829 && ./P5829
*/