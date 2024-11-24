#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

vector<array<int, 2>> G[N];
int n;

int F[N * 2], si[N * 2];
vector<int> stk[N * 2];

void dfs1(int x, int fa) {
    si[x] = 1;
    for(auto i : G[x]) {
        int to = i[0], w = i[1];
        if(to == fa) continue;
        stk[w].push_back(to);
        dfs1(to, x) ;
        si[x] += si[to];
        stk[w].pop_back();
        F[stk[w].back()] -= si[to];
    }
    F[x] += si[x];
}

LL ans = 0;

void dfs2(int x, int fa) {
    for(auto i : G[x]) {
        int to = i[0], w = i[1];
        if(to == fa) continue;
        stk[w].push_back(to);
        dfs2(to, x);
        stk[w].pop_back();
        ans += 1ll * F[to] * F[stk[w].back()];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v, w; i < n; i++)     
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w}) ;
    rep(i, 1, n) stk[i].push_back(i + n), F[n + i] = n;
    dfs1(1, 0); dfs2(1, 0);
    cout << ans << '\n';
    return 0;
}