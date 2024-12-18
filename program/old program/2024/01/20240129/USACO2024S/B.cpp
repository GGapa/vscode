#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int aa[N], si[N], can[N], cnt[N], a[N];
vector<int> G[N];

void dfs1(int x, int fa) {
    si[x] += (G[x].size() == 0);
    for(auto to : G[x]) {
        if(to == fa) continue;
        dfs1(to, x);
        si[x] += si[to];
    }
}

void dfs2(int x, int fa) {
    cnt[x] += a[x];
    for(auto to : G[x]) {
        if(to == fa) continue;
        dfs2(to, x);
        cnt[x] = min(cnt[to] + cnt[x], si[x]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1, tmp; i <= n; i++) {
        cin >> aa[i];
    }
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        // G[v].push_back(u);
    }
    dfs1(1, 1);
    for(int i = 1; i <= si[1]; i++) a[aa[i]]++;
    dfs2(1, 1);
    cout << cnt[1] << '\n';
    return 0;
}