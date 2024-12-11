#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5;

int n, q, si;
vector<array<int, 2>> G[N];
vector<int> dfn(1);
int in[N], out[N], c[N], cnt[N], et[N], num[N];


int siz[N], top[N], hson[N], fa[N], dep[N];


void dfs1(int x, int f) {
    dfn.emplace_back(x);
    in[x] = dfn.size() - 1;
    siz[x] = 1; dep[x] = dep[f] + 1; fa[x] = f;
    for(auto i : G[x]) {
        int to = i[0];
        if(to == f) continue;
        c[to] = i[1];
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[hson[x]]) hson[x] = to;
    }
    dfn.emplace_back(x);
    out[x] = dfn.size() - 1;
}

void dfs2(int x, int tp) {
    top[x] = tp;
    if(!hson[x]) return ;
    dfs2(hson[x], tp);
    for(auto i : G[x]) {
        int to = i[0];
        if(to == fa[x] || to == hson[x]) continue;
         dfs2(to, to);       
    }
}

int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);   
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}


struct Que {
    int l, r, id;
};
bool debug = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // debug = 1;/
    cin >> n >> q;
    for(int i = 1, u, v, w; i < n; i++) 
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w});
    c[1] = -1;
    dfs1(1, 0);
    dfs2(1, 0);
    vector<Que> Q(1);
    for(int i = 1, l, r; i <= q; i++) {
        cin >> l >> r; int la = lca(l, r);
        if(la == l || r == la) {
            if(in[l] > in[r]) swap(l, r);
            l = in[l] + 1, r = in[r];
        }
        else {
            if(out[l] > in[r]) swap(l, r);
            l = out[l], r = in[r];
        }
        Q.push_back({l, r, i});
    }
    if(debug) rep(i, 1, 2 * n) cout << dfn[i] << " \n"[i == 2 * n];
    si = 500;
    vector<int> ans(q + 1);
    sort(Q.begin() + 1, Q.end(), [&](const Que &x, const Que &y) {
        int a = x.l / si, b = y.l / si;
        if(a != b) return a < b;
        return (a % 2 ? x.r > y.r : x.r < y.r);
    });
    auto update = [&](int x, int y) {
        if(x > n || x < 0) return ;
        if(et[x] == 0 && et[x] + y > 0) cnt[x / si]++;
        else if(et[x] + y == 0) cnt[x / si]--;
        et[x] += y;
    } ;
    auto add = [&](int x, int y) {
        num[x] += y;
        if(num[x] == 1) update(c[x], 1); 
        else if((num[x] == 0 && y == -1) || (num[x] == 2 && y == 1)) update(c[x], -1);
        if(debug) cout << x << " " << y << '\n';
    };
    auto ask = [&]() {
        rep(i, 0, n / si) if(cnt[i] < si){
            rep(j, i * si, (i + 1) * si - 1) if(et[j] < 1) return j;
        }
        return -1;
    };
    for(int l = 1, r = 0, i = 1; i <= q; i++) {
        int nl = Q[i].l, nr = Q[i].r;
        if(debug) cout << nl << " " << nr << " " << Q[i].id << '\n';
        while(l < nl) add(dfn[l++], -1);
        while(l > nl) add(dfn[--l], 1);
        while(r < nr) add(dfn[++r], 1);
        while(r > nr) add(dfn[r--], -1);
        ans[Q[i].id] = ask();
        if(debug) rep(i ,0, n) cout << et[i] << " \n"[i == n];
        // cout << "-------\n";
    }
    rep(i ,1, q) cout << ans[i] << "\n";
    return 0;
}