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

constexpr int mod = 1e9 + 7, N = 400 + 5;

int n, m;
bool vis[N];
vector<AI<2>> G[N];
bitset<N> w, d[N], x[N];

void inesrt() {
    rep(i, 1, m) if(w[i]) {
        if(!x[i].any()) return x[i]=w,void();
        else w^=x[i];
    }
}

void dfs(int u) {
    vis[u] = true;
    for (auto e : G[u]) {
        if (!vis[e[0]]) {
            d[e[0]] = d[u]; d[e[0]].set(e[1]);
            dfs(e[0]);
        } 
        else {
            w = d[u]; w ^= d[e[0]];
            w.flip(e[1]);
            inesrt();
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].push_back({v, i});

    rep(i, 1, n) {
        rep(u, 1, n) d[u].reset(), vis[u] = false;
        dfs(i);
    }   

    int ans = 1;
    rep(i, 1, m) if (!x[i].any()) ans = (1ll * ans * 2) % mod;

    cout << ans << '\n';

    return 0;
}