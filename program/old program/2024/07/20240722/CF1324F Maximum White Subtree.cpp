#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 2e5 + 5;

int n;
int A[N], F[N], ans[N];
vector<int> G[N];

void dfs1(int x, int fa) {
    F[x] = A[x];
    for(auto to : G[x]) if(to != fa) {
        dfs1(to, x);
        F[x] += max(0, F[to]);
    }
}

void dfs2(int x, int fa) {
    ans[x] = F[x];
    for(auto to : G[x]) if(to != fa){
        F[x] -= max(0, F[to]);
        F[to] += max(0, F[x]);
        dfs2(to, x);
        F[to] -= max(0, F[x]);
        F[x] += max(0, F[to]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> A[i], A[i] = (A[i] == 0 ? -1 : 1);
    for(int i = 1, u, v; i < n; i++)
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dfs1(1, 0);
    dfs2(1, 0);
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
    return 0;
}