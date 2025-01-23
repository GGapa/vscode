#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 3e5 + 5;

int n;
int sz[N], dep[N], A[N];
LL ans = 0;
vector<int> G[N];

void clear() {
    ans = 0;
    rep(i, 1, n) vector<int>(0).swap(G[i]);
    fill(A, A + 1 + n, 0);
}

void dfs(int x, int fa) {
    sz[x] = 1; dep[x] = dep[fa] + 1; A[dep[x]]++;
    ans += (n - 1ll) * dep[x];
    LL a, b; a = b = 0;
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        sz[x] += sz[to];
        a += sz[to] * b; b += sz[to];
    }
    ans -= 2 * (a + sz[x] - 1) * dep[x];
    ans += sz[x] - 1;
}

void solve() {
    cin >> n;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    
    dfs(1, 0);
    for(int i = 1, x = 0; i <= n; x += A[i++]) ans -= 1ll * i * A[i] * (x - (n - A[i] - x));
 
    cout << ans - 1ll * n * (n - 1) / 2 << '\n';

    clear();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}