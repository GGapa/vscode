#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 1e9, mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> op(n + 1), val(n + 1), A(1);
    for(int i = 1, w = 0; i <= n; i++) {
        cin >> op[i];
        if(op[i] != 3) cin >> val[i];
        if(op[i] == 2) w = min(INF, w + val[i]);
        if(op[i] == 3) val[i] = w, w = min(INF, w * 2);
    }
    LL ans = 0;
    for(int i = n, w = 0, ct = 1; i >= 1; i--) {
        if(op[i] == 2) w = min(INF, w + val[i]);
        if(op[i] == 3) {
            if(!val[i]) (ct *= 2) %= mod;
            else if(val[i] != INF) A.emplace_back(val[i]);
        }
        else {
            int x = val[i] - w;
            if(x <= 0) continue;
            int d = 1;
            rep(i, 1, A.size() - 1) if(x > A[i]){
                x -= A[i], (d += (1 << A.size() - 1 - i)) %= mod;
            }
            cout << d << " " << ct << '\n';
            (ans += 1ll * d * ct % mod) %= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}