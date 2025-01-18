#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

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
}dsu;

constexpr int N = 2e6 + 5;

int n, q; 
int dfn[N], fa[N], fst[N], lst[N], nxt[N], tag[N], ans[N];
AI que[N];

vector<int> G[N], ps[N], T[N];

void dfs(int x) {
    for(auto to : G[x]) if(to != fa[x]) 
        fa[to] = x, dfs(to);
}

void dfs1(int x) {
    int &tim = dfn[N - 1];
    dfn[++tim] = x, ps[x].emplace_back(tim); fst[x] = tim;
    for(auto to : T[x]) {
        dfs1(to);
        dfn[++tim] = x, ps[x].emplace_back(tim);
    }
}

void del(int x) {
    // nxt[x] = dsu.find(x % dfn[N - 1] + 1);
    dsu.merge(x, x % dfn[N - 1] + 1);
    tag[x] = 0;
}

int calc(int x, int y) {
    x += y; x %= dfn[N - 1];
    if(x == 0) x = dfn[N - 1];
    return dfn[x];
}

int dis(int x, int y) {
    return (x < y ? y - x : dfn[N - 1] + y - x);
}

void work(int p, int tim, int qt) {
    int x = dfn[p];
    if(tag[p]) {
        for(auto it : ps[x]) del(it);
        while(qt <= q && que[qt][0] == tim) ans[que[qt][1]] = x, qt++;
        work(G[x][G[x].size() > 1], tim + 1, qt);
    }
    else {
        int np = dsu.find(p);
        if(!tag[np]) {
            while(qt <= q) ans[que[qt][1]] = calc(p, que[qt][0] - tim), qt++;
            return ;
        }
        int nt = tim + dis(p, np);
        while(qt <= q && que[qt][0] < nt) ans[que[qt][1]] = calc(p, que[qt][0] - tim), qt++;
        work(np, nt, qt);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;

    vector<int> deg(n + 1);
    rep(i, 1, n) {
        cin >> deg[i];
        for(int j = 1, x; j <= deg[i]; j++) 
            cin >> x, G[i].emplace_back(x);
    }

    dfs(1);

    rep(i ,1, n) {
        int pos = 0;
        if(i != 1) while(G[i][pos] != fa[i]) pos++;
        (pos += 1) %= deg[i];
        for(int j = 1; j <= deg[i] && G[i][pos] != fa[i]; (pos += 1) %= deg[i], j++) 
            T[i].emplace_back(G[i][pos]);
    }

    dfs1(1); dfn[N - 1]--;
    dsu.init(dfn[N - 1] + 10);

    per(i, dfn[N - 1], 1) {
        int x = dfn[i]; lst[x] = i;
        if(fst[x] == i) {
            for(auto &to : G[x]) {
                if(!lst[to]) to = fst[to];
                else to = lst[to];
            }
        } 
    }

    rep(i, 1, q) cin >> que[i][0], que[i][1] = i;
    sort(que +1, que + 1 + q);
    fill_n(tag, N, 1);
    fill_n(ans, N, -1);
    work(1, 0, 1);

    rep(i ,1, q) cout << ans[i] << '\n';

    // rep(i, 1, dfn[N - 1]) cerr << fst[i] << " \n"[i == dfn[N - 1]];
    // rep(i, 1, dfn[N - 1]) cerr << lst[i] << " \n"[i == dfn[N - 1]];

    return 0;
}
