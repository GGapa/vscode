#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x, y; cin >> n >> x >> y;
    vector<VI> F(n + 1, VI(x + 1, INF));
    F[0][0] = 0;    
    for(int i = 1, A, B; i <= n; i++)  {
        cin >> A >> B;
        per(c, i - 1, 0) per(d, x, A) F[c + 1][d] = min(F[c + 1][d], F[c][d - A] + B);
    }
    int ans = 0;
    rep(c, 0, n - 1) rep(d, 0, x) if(F[c][d] <= y) ans = max(ans, c + 1);
    cout << ans << '\n';
    return 0;
}