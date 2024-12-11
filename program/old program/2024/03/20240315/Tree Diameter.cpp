// Tree Diameter
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

vector<int> G[N];
int dep[N], rt;

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1; 
    if(dep[x] > dep[rt]) rt = x;
    for(auto to : G[x]) {
        if(to == fa) continue;
        dfs(to, x);
    }
 }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i = 2,u, v; i <=n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    fill(dep + 1, dep + 1 + n, 0);
    dfs(rt, 0);
    cout << dep[rt] - 1 << '\n';
    return 0;
}