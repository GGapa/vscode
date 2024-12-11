// Counting Paths
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int dep[N], hson[N], F[N], si[N], top[N], ans[N], cnt[N];
vector<int> G[N], pre(1);

void dfs1(int x, int fa) {
    pre.push_back(x);
    dep[x] = dep[fa] + 1, si[x] = 1, F[x] = fa;
    for(auto to : G[x]) if(to != fa) {
        dfs1(to, x);
        si[x] += si[to];
        if(si[to] > si[hson[x]]) hson[x] = to;
    }
} 

void dfs2(int x, int tp) {
    top[x] = tp;
    if(!hson[x]) return ;
    dfs2(hson[x], tp);
    for(auto to : G[x]) if(to != F[x] && to != hson[x]) {
        dfs2(to, to);
    }
}

int LCA(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = F[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 2, x, y; i  <= n; i++) 
        cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
    G[0].push_back(1);
    dfs1(1, 0); dfs2(1, 0);
    for(int i = 1, a, b ; i<= m; i++) {
        cin >> a >> b;
        int l = LCA(a, b);
        // cout << l << '\n';
        cnt[F[l]]--; 
        cnt[l]--;
        cnt[a]++; 
        cnt[b]++;
    }
    per(i, n, 1) {
        int x = pre[i];
        // cout << cnt[x] << '\n';
        for(auto to : G[x]) if(to != F[x])
            cnt[x] += cnt[to];
    }
    rep(i, 1, n) cout << cnt[i] << " \n"[i == n];
    return 0;
}