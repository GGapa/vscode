/*
P1073 [NOIP2009 提高组] 最优贸易
*/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

const int maxn = 100000 + 5;

vector<int> G[maxn];
int n, m;
int mi[maxn], c[maxn], f[maxn];

void dfs(int x, int minn, int fa) {
    bool flag = true;
    minn = min(c[x], minn);
    if(mi[x] > minn) {
        mi[x] = minn;
        flag = false;
    }
    int maxx = max(f[fa], c[x] - minn);
    if(f[x] < maxx) {
        f[x] = maxx;
        flag = false;
    }
    if(flag) return;
    for(int i = 0; i < G[x].size(); i++) dfs(G[x][i], minn, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= maxn - 5; i++) mi[i] = INT_MAX;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back(v);
        if(w == 2) G[v].push_back(u);
    }
    dfs(1, INT_MAX, 0);
    cout << f[n] << endl;
    return 0;
}
