#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e4 + 5, V = 100 + 5;

int n;
int A[N];
vector<int> G[N];
bitset<V> L[N], R[N];

void dfs(int x, int fa) {
    L[x][A[x]] = R[x][A[x]] = 1;
    for(auto to : G[x]) if(to != fa) dfs(to, x);
    sort(G[x].begin(), G[x].end(), [&](const int x, const int y) {
        return A[x] < A[y];
    });
    for(auto to : G[x]) if(to !=  fa) 
        if(A[to] > A[x] && ((R[x] << 1) & L[to]).any()) R[x] |= R[to];
    reverse(G[x].begin(), G[x].end());
    for(auto to : G[x]) if(to != fa) 
        if(A[to] < A[x] && ((L[x] >> 1) & R[to]).any()) L[x] |= L[to];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u); 
    dfs(1, 0);
    cout << 1ll * L[1].count() * R[1].count() << '\n';

    return 0;
}