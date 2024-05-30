#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1000 + 5, INF = 1e9;

int F[N][N], A[N], n, ans = INF, cnt = 0;

int dfs(int x,int v) {
    auto &f = F[x][v];
    if(f != -1) return f;
    if(x == 1 && v == 0) return 0;
    if(v == 0) return INF;
    f = INF;
    if(x + v <= n) f = min(f, dfs(x + v, v) + A[x]);
    if(x - v >= 1) f = min(f, dfs(x - v, v - 1) + A[x]);   
    // cout << x << " " << v << " " << f << '\n';
    return f;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n ;
    rep(i, 1, n) cin >> A[i]; 
    memset(F, -1, sizeof(F));
    rep(i, 1, n) ans = min(ans, dfs(n, i));
    cout << ans << '\n';
    return 0;
}