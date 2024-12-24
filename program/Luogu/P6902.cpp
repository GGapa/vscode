#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; 
    while(cin >> n >> k) {
        vector<AI> itv(k + 1);
        rep(i, 1, k) {
            cin >> itv[i][0] >> itv[i][1];
            if(itv[i][0] > itv[i][1]) itv[i][1] += n;
        }
        sort(itv.begin() + 1, itv.end());
        vector<VI> F(2 * n + 1, VI(21 + 1));
        for(int i = 1, it = 1, mx = 0; i <= n * 2; i++) {
            while(it <= k && itv[it][0] <= i) mx = max(mx, itv[it][1] + 1), it++;
            F[i][0] = mx;
        }
        rep(j, 1, 21) rep(i, 1, 2 * n) F[i][j] = F[F[i][j - 1]][j - 1];
        int ans = k + 1;
        rep(i, 1, 2 * n) {
            int x = i, ret = 0;
            for(int j = 21; j >= 0; j--) {
                if(F[x][j] && F[x][j] - i < n) x = F[x][j], ret += 1 << j;
            }
            x = F[x][0], ret++;
            if(x - i >= n) ans = min(ans, ret);
        }
        if(ans >= k + 1)  cout << "impossible\n", 0;
        else cout << ans << '\n';
    }
    return 0;
}