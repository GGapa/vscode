// Dropping water balloons
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using ull  = unsigned long long;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    using VU = vector<ull>;
    vector<VU> F(100 + 1, VU(64));
    rep(i, 1, 100) rep(j, 1, 63) F[i][j] = F[i - 1][j - 1] + 1 + F[i][j - 1];   //如果气球破掉了，如果气球没有破
    ull n;
    for(int k; cin >> k >> n && k; ) {
        int ans = -1;
        rep(i, 1, 63) if(F[k][i] >= n) {
            ans = i;
            break;
        }
        if(ans < 0) cout << "More than 63 trials needed.\n";
        else cout << ans << '\n';
    }
    return 0;
}