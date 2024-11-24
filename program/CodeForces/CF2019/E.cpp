#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

int dis[N], F[N], pa[N], GG[N];
vector<int> G[N];
int n;

void dfs(int x, int fa) {
    pa[x] = fa;
    if(x != 1 && G[x].size() == 1) F[x] = 1;
    for(auto to : G[x]) if(to != fa) {
        dis[to] = dis[x] + 1; 
        dfs(to, x); 
        F[x] += F[to];
    }
}

void init(int n) {
    // fill(dis, dis + 1 + n, 0); fill(F, F + 1 + n, 0);  fill(pa, pa + 1 + n, 0);
    rep(i, 0, n + 1) dis[i] = F[i] = pa[i] = 0, G[i].clear(), GG[i] = 0;
}

void solve() {
    cin >> n;
    init(n);

    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);

    dfs(1, 0);
    vector<int> vec(1);
    rep(i, 2, n) if(G[i].size() == 1) vec.emplace_back(i);
    sort(vec.begin() + 1, vec.end(), [&](const int x, const int y) {
        return dis[x] < dis[y];
    });
    int cnt = 0;
    vector<int> dep(n + 3);
    rep(i, 1, n) dep[dis[i]]++;
    per(i, n, 1) dep[i] += dep[i + 1];
    int m = (int)vec.size() - 1;
    int ans = INT_MAX;

    auto del = [&](int x) {
        GG[x] = 1;
        while(F[x] == GG[x] && x != 1) GG[pa[x]] += GG[x], x = pa[x], cnt++;
    };
    for(int i = 0, j = 1; i <= n + 1; i++) {
        while(j <= m && dis[vec[j]] < i) del(vec[j]), j++;
        ans = min(ans, cnt + dep[i + 1]);
    }
    cout << ans << '\n';
}

signed main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
9
1 2
2 3
2 4
2 6
6 5
6 7
1 8
1 9
*/