#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
const int N = 7.5e3 + 10, mod = 998244353;
int n, m, k, f[N][N], g[N][N];
vector<int> e[N];
int tmp[N], siz[N];
void dfs1(int u, int fa) {
    siz[u] = 1;
    for(auto v : e[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
    f[u][1] = 1;
    for(auto v : e[u]) {
        memset(tmp, 0, sizeof(tmp));
        for(int i = 1; i <= siz[u]; i++)
            for(int j = 0; j <= siz[v]; j++)
                tmp[i + j] = (tmp[i + j] + 1ll * f[u][i] * f[v][j]) % mod;
        memcpy(f[u], tmp, sizeof(f[u]));
        siz[u] += siz[v];
    }
    f[u][0] = 1;
}
void dfs2(int u, int fa) {
    memcpy(tmp, g[u], sizeof(tmp));

    for(int i = 0; i <= n; i++)
    for(auto v : e[u]) {
        if(v == fa) continue;
        memcpy(g[u], f[u], sizeof(g[u]));

    }
}
int main() {
    n = read(), m = read(), k = read();
    for(int i = 2; i <= n; i++) {
        int f = read();
        e[f].push_back(i);
        e[i].push_back(f);
    }
    for(int i = 1; i <= n; i++)
    return 0;
}