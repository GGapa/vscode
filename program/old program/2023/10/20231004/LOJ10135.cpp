/*
祖孙询问(LOJ10135)
https://vjudge.csgrandeur.cn/contest/584212#problem/D
*/
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 4e4 + 5;
const int maxk = 20; 

int n, root, m;
vector<int> G[maxn];

int fa[maxk][maxn];
int depth[maxn];

void dfs(int x, int f) {
    fa[0][x] = f;
    depth[x] = depth[f] + 1;
    for (int i = 1; i < maxk; i++) {
        fa[i][x] = fa[i - 1][fa[i - 1][x]];
    }
    for (auto to : G[x]) {
        if (to == f)
            continue;
        dfs(to, x);
    }
}

int LCA(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    for (int i = maxk - 1; i >= 0; i--) {
        if (depth[fa[i][x]] >= depth[y])
            x = fa[i][x];
    }
    if (x == y)
        return x;
    for (int i = maxk - 1; i >= 0; i--) {
        if (fa[i][x] != fa[i][y]) {
            x = fa[i][x];
            y = fa[i][y];
        }
    }
    return fa[0][x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        if(v == -1) {root = u; continue;}
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> m;
    int x, y;
    dfs(root, 0);
    while(m--) {
        cin >> x >> y;
        int lca = LCA(x, y);
        if(lca == x) cout << "1\n";
        else if(lca == y) cout << "2\n";
        else cout << "0\n";
    }
}