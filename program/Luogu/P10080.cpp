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

constexpr int N = 1e3 + 5;

int n, m; 
int vis[N], mch[N], ans[N * N], F[N], bel[N];
vector<AI<3>> G[N], H[N];
vector<AI<2>> stk;
bool tag = false;

bool dfs(int x, int tag) {
    if(vis[x] == tag) return false;
    vis[x] = tag;
    for(auto [to, w, id] : G[x]) if(mch[to] == 0 || dfs(mch[to], tag)) {
        mch[to] = x;
        return true;
    }
    return false;
}

void dfs(int x) {
    vis[x] = 1;
    for(auto [to, w, i] : H[x]) if(!tag) {
        if(!vis[to]) stk.push_back({to, i}), F[to] = F[x] + w, dfs(to);
        else if(bel[to] && (F[x] - F[to] + w) & 1) {
            tag = 1; ans[i] ^= 1;
             while(!stk.empty() && stk.back()[0] != to) ans[stk.back()[1]] ^= 1, stk.pop_back();
        }
    }
    bel[x] = 0; 
    if(!stk.empty()) stk.pop_back();
}

void solve() {
    cin >> n >> m;
    rep(i, 1, 2 * n) vis[i] = mch[i] = F[i] = bel[i], G[i].clear(), H[i].clear();
    stk.clear(); tag = false;
    rep(i, 1, m) ans[i] = 0;

    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w, i}), G[v].push_back({u, w, i})    ;
    }
    rep(i, 1, n) tag |= !dfs(i, i);
    if(tag) goto ed;

    int cnt; cnt = 0;
    rep(u, n + 1, n << 1) for(auto [v, w, i] : G[u]) {
        if(mch[u] == v) cnt += w, ans[i] = 1, H[v].push_back({u, w, i});
        else H[u].push_back({v, w, i});
    }
    if(!(cnt & 1)) goto out;

    // rep(i, 1, m) cerr << ans[i] << " \n"[i == m];

    rep(i, 1, n << 1) {
        fill_n(vis, N, 0); fill_n(bel, N, 0);
        F[i] = 0; bel[i] = 1; stk.clear();
        dfs(i);
    }

    if(!tag) goto ed;    

    out:
    rep(i, 1, m) if(ans[i]) cout << i << " "; 
    return cout << '\n', void();
    
    ed: return cout << -1 << '\n', void();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
找到一个完美匹配后如果是偶数直接输出，否则可以探究如何调整使得新图合法，(没有来讨论这个直接就遭殃了)
调整出来的和旧图连上一定是一个环，且黑色边的数量为奇数。
*/