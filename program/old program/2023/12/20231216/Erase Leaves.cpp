#include <iostream>
#include <vector>
using namespace std;
const int maxn = 3e5 + 5;

vector<int> G[maxn];
int siz[maxn], ans = 0, n, mx = 0;

void dfs(int x, int fa) {
    siz[x] = 1;
    for(auto to : G[x]) {
        if(to == fa) continue;
        dfs(to, x);
        siz[x] += siz[to];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for(auto i : G[1]) {
        mx = max(mx, siz[i]);
        ans += siz[i];
    }
    ans -= mx;
    cout << ans + 1;
    return 0;
}