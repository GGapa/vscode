// Company Queries I
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    using VI = vector<int>;
    vector<VI> F(21, VI(n + 1, 0));
    for(int i = 2, x; i <= n; i++) {
        cin >> x;
        F[0][i] = x;
    }
    rep(i, 1, 20) rep(j, 1, n) 
        F[i][j] = F[i - 1][F[i - 1][j]];
    for(int i = 1, x, k ; i <= q; i++) {
        cin >> x >> k;
        per(j, 20, 0) if((1 << j) & k)
           x = F[j][x]; 
        cout << (x == 0 ? -1 : x) << '\n';
    }
    return 0;
}