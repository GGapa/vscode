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

void init() {
    rep(i ,1, n) G[i].clear(); 
    dfn.assign(1, 0);
    memset(cnt, 0, sizeof(cnt));
    memset(et, 0, sizeof(et));
    memset(num, 0, sizeof(num));
    rep(i ,0, n + 1) siz[i] = top[i] = hson[i] = fa[i] = dep[i] = in[i] = out[i] = c[i] = 0; 
}

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

void solve() {
    cin >> n;
    // debug = 1;
    init();
    for(int i = 1, u, v, w; i < n; i++) 
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w});
    c[1] = -1;
    dfs1(1, 0);
    dfs2(1, 0);
    vector<Que> Q(1);
    cin >> q;
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
    si = 300; 
    vector<double> ans(q + 1);
    sort(Q.begin() + 1, Q.end(), [&](const Que &x, const Que &y) {
        int a = x.l / si, b = y.l / si;
        if(a != b) return a < b;
        return (a % 2 ? x.r > y.r : x.r < y.r);
    });
    int sum = 0;
    auto update = [&](int x, int y) {
        if(x > 100000 || x < 0) return ;
        cnt[x / si] += y;
        et[x] += y; sum += y;
    } ;
    auto add = [&](int x, int y) {
        num[x] += y;
        if(num[x] == 1) update(c[x], 1); 
        else if((num[x] == 0 && y == -1) || (num[x] == 2 && y == 1)) update(c[x], -1);
    };
    const int MX = 1e6;
    auto ask = [&]() {
        int res = 0;
        int t1 = -1;
        if(sum & 1) {
            rep(i, 0, MX / si) if((res += cnt[i]) >= sum / 2) {
                res -= cnt[i];
                rep(j, i * si, MX) {
                    res += et[j];
                    if(res>= (sum + 1) / 2) return j * 1.0;
                }
            }
        }
        else {
            rep(i, 0, MX / si) if((res += cnt[i]) >= sum / 2){
                res -= cnt[i];
                rep(j, i * si, MX) {
                    if(debug) cout << j << " " << et[j] << '\n';
                    if(res + et[j] >= sum / 2 && t1 == -1) t1 = j;
                    if(res + et[j] > sum / 2 && t1 != -1) return 1.0 * (t1 + j) / 2;
                    res += et[j];
                }
            }
        }
        return -1.0;
    };
    for(int l = 1, r = 0, i = 1; i <= q; i++) {
        int nl = Q[i].l, nr = Q[i].r;
        if(debug) cout << nl << " " << nr << " " << Q[i].id << '\n';
        while(l < nl) add(dfn[l++], -1);
        while(l > nl) add(dfn[--l], 1);
        while(r < nr) add(dfn[++r], 1);
        while(r > nr) add(dfn[r--], -1);
        ans[Q[i].id] = ask();
        if(debug) rep(i ,0, 10) cout << et[i] << " \n"[i == 10];
    }
    rep(i ,1, q) cout << fixed << setprecision(1) << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}