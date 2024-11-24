#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    vector<VI> F(n + 1, VI(m + 1));
    vector<int> G(n + 1), H(m + 1);
    rep(i, 1, n) rep(j ,1 ,m) {
        auto &f = F[i][j];
        f = F[i - 1][j - 1] + 2 * (a[i] == b[j]);
        f = max({f, G[i] - 1, H[j] - 1});
        G[i] = max(G[i], f), H[j] = max(H[j], f);
    }
    cout << F[n][m] << "\n";
    return 0;
}