#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e5 + 5;

int A[N];
LL F[N], ans[N], g[N];
pair<LL, int> mx[N][2];
priority_queue<pair<LL, int>> q;
vector<int> G[N];

void update(int x, int to) {
    if(F[to] > mx[x][0].first) {
        mx[x][1] = mx[x][0];
        mx[x][0] = {F[to], to};
    }
    else if(F[to] > mx[x][1].first) {
        mx[x][1] = {F[to], to};
    }
}

void dfs(int x, int fa) {
    F[x] = A[x];
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        F[x] = max(F[x], A[x] + F[to]);
    }
}

void dfs2(int x, int fa) {
    while(!q.empty()) q.pop();
    for(auto to : G[x]) if(to != fa) q.emplace(F[to], to);
    if(fa) q.emplace(g[x], fa);
    rep(i, 0, 1) if(!q.empty()) mx[x][i] = q.top(), q.pop();
    rep(i, 0, 1) if(mx[x][i].first > 0) ans[x] += mx[x][i].first;
    ans[x] += A[x];
}

signed main() {
    freopen("test.in", "r", stdin);
    freopen("std.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, u, v; i < n; i++)
        cin >> u >> v, u++, v++, G[u].emplace_back(v), G[v].emplace_back(u);
    rep(i, 1, n) {
		fill(F, F + 1 + n, 0); fill(g, g + 1 + n, 0); fill(ans, ans + 1 + n, 0);
		dfs(i, 0);
    	dfs2(i, 0);
		cout << ans[i] << '\n';
	}
    return 0;
}