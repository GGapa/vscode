//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
#define int long long
const int lg = 18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    vector<int> a(q + 1), c(q + 1), dep(q + 1);
    vector<VI> F(q + 1, VI(lg + 1, -1));
    cin >> a[0] >> c[0];
    rep(i, 1, q) {
        int op; cin >> op;
        if(op == 1) {
            cin >> F[i][0];
            dep[i] = dep[F[i][0]] + 1;
            for(int j = 1; (1 << (j - 1)) <= dep[i]; j++) F[i][j] = F[F[i][j - 1]][j - 1];
            cin >> a[i] >> c[i];
        }
        else {
            int v, w; cin >> v >> w;
            int sum = 0, cost = 0;
            while(w && a[v]) {
                int u = v;
                per(j, lg, 0) if(F[u][j] != -1 && a[F[u][j]]) u = F[u][j];
                int t = min(w, a[u]);
                sum += t;
                cost += 1ll * c[u] * t;
                a[u] -= t;
                w -= t;
            } 
            cout << sum << " " << cost << endl;
        }
    }
    return 0;
}