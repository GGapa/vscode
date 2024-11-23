#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 2e5 + 5;
vector<int> G[N];
int dis[N], siz[N];

void dfs(int x, int fa) {
    siz[x] = 1;
    for(auto to : G[x]) if(to != fa) {
        dis[to] = dis[x] + 1;
        dfs(to, x);
        siz[x] += siz[to];
    }
}

void solve() {
    int n, k; cin >> n >> k;    
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    dfs(1, 0);
    vector<int> A;
    rep(i, 1, n) A.emplace_back(dis[i] - (siz[i] - 1));
    sort(A.begin(), A.end());
    LL ans = 0;
    rep(i, 1, k) ans += A.back(), A.pop_back();
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
/*
计算贡献，选择一个节点的答案即为 dep[x] - (选到了的子树数量)
显然可以贪心从深处往浅选，一定会先选择叶子节点，选择非叶子节点会导致答案减少。

*/