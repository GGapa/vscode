//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 50 + 5;

int F[N][N][N * N];

int n, m; 

struct Node {
    int x, y;
};
Node A[N];

int dfs(int i, int j, int k) {
    auto &f = F[i][j][k];
    if(f != -1) return f;
    if(i > n || j > m) return f = 0;
    f = 0;
    f = max(f, dfs(i + 1, j, k));
    if(j < m) f = max(f, dfs(i + 1, j + 1, k + A[i].y) + A[i].x * (2 * k +  A[i].y));
    return f;
}

void solve() {
    cin >> n >> m; 
    memset(F, -1, sizeof(F));
    rep(i, 1, n) cin >> A[i].x >> A[i].y;
    sort(A + 1, A + 1 + n, [](const Node &x, const Node &y) {
        return 1.0 * x.y / x.x > 1.0 * y.y / y.x;
    });
    cout << dfs(1, 0, 0) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int o = 1; o <= T; o++) {
        cout << "Case " << o << ": ";
        solve();
    }
    return 0;
}