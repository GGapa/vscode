// Bigger is Better
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int INF = 1e9;

vector<int> num{6, 2, 5, 5, 4, 5, 6, 3, 7, 6} ;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int n, m, ca = 1; cin >> n >> m && n ; ca++) {
        cout << "Case " << ca << ": ";
        using VI = vector<int>;
        vector<VI> F(n  + 5, VI(m + 5, INF));
        vector<int> ans(n + 1);
        int l = 1, r = n, mid, res = 0;
        F[0][0] = 0;
        rep(i, 0, n) rep(j, 0, m - 1) if(F[i][j] != INF) 
            rep(k, 0, 9) {
                auto &f = F[i + 1][(j * 10 + k) % m];
                f = min(f, F[i][j] + num[k]);
            }
        vector<int> pw(n + 10);
        // int res ;
        for (res = n + 1 ; F[res][0] > n ; res--);
        int p = 0, cost = n; pw[1] = 1;
        rep(i, 2, res) pw[i] = pw[i - 1] * 10 % m;
        rep(i, 1, res) {
            per(j, 9, 0) {
                int t = j * pw[res - i + 1] % m;
                if(num[j] + F[res - i][((m - p - t) % m + m) % m] <= cost) {
                    cost -= num[j]; (p += t) %= m;
                    ans[i] = j;
                    break;
                }
            }
        }
        int q = 1; 
        while(!ans[q] && q < res) ++ q;
        rep(i, q, res) cout << ans[i];
        if(!res) cout << "-1\n";
        else cout << '\n';
    }
    return 0;
}