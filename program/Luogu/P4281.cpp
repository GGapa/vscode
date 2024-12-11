// P4281 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

int si[N], top[N], hson[N], fa[N], dep[N];
vector<int> G[N];

void dfs1(int x, int f) {
    si[x] = 1, fa[x] = f; dep[x] = dep[f] + 1;
    for(auto to : G[x]) {
        if(to == f) continue;
        dfs1(to, x);
        si[x] += to;
        if(si[hson[x]] < si[to]) hson[x] = to;
    }
} 

void dfs2(int x, int tp) {
    top[x] = tp;
    if(!hson[x]) return ;
    dfs2(hson[x], tp);
    for(auto to : G[x]) {
        if(to == fa[x] || to == hson[x]) continue;
        dfs2(to, to);
    }
}

int LCA(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y); 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m ;
    for(int i = 2, x, y; i <= n; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    auto dis = [&](int x, int y, int &l1) {
        return dep[x] + dep[y] - 2 * dep[(l1 = LCA(x, y))];
    };
    for(int i = 1, x, y, z, l1, l2, l3; i <= m; i++) {
        cin >> x >> y >> z;
        int C = (dis(x, y, l1) + dis(x, z, l2) + dis(y, z, l3)) / 2, LL = (l1 ^ l2 ^ l3);
        // int D = abs(dep[LL] - dep[x]) + abs(dep[LL] - dep[y]) + abs(dep[LL] - dep[z]);
        cout << LL << " " << C << '\n';
    } 
    return 0;
}