/*
P2015 二叉苹果树
https://www.luogu.com.cn/problem/P2015
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#define ll long long
#define maxn 105
using namespace std;

int n, m, f[maxn][maxn];

struct Edge {
    int w, to, next;
} edges[maxn << 1];
int tot, head[maxn];

void add(int u, int v, int w) {
    edges[tot] = {w, v, head[u]};
    head[u] = tot++;
}

int sz[maxn];

void dfs(int u, int fa) {
    for (int i = head[u]; ~i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v] + 1;
        for (int j = min(sz[u], m); j; --j) {
            for (int k = min(sz[v], j - 1); k >= 0; --k) {
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + edges[i].w);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, -1);
    cout << f[1][m] << endl;
    return 0;
}
