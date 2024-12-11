#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7;

LL add(const LL x, const LL y) {
    return (x + y + mod) % mod;
} 
 
LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), B(n +1), sa(n + 1), sb(n + 1) ;
    rep(i, 1 ,n) cin >> A[i], sa[i] = sa[i - 1] + A[i];
    rep(i, 1, n) cin >> B[i], sb[i] = sb[i - 1] + B[i];
    vector<VI> F(n + 1, VI(n + 1)), ia = F, ib = F;
    F[0][0] = 1;
    rep(i, 0, n) {
        auto &ta = ia[i];
        iota(ta.begin() + 1, ta.begin() + 1 + n - i, i + 1);
        sort(ta.begin() + 1, ta.begin() + 1 + n - i, [&](const int &x, const int &y) {
            return 1ll * (sa[x] - sa[i]) * (y - i) <= 1ll * (sa[y] - sa[i]) * (x - i);
        });
        auto &tb = ib[i];
        iota(tb.begin() + 1, tb.begin() + 1 + i, 1);
        sort(tb.begin() + 1, tb.begin() + 1 + i, [&](const int &x, const int &y) {
            return 1ll * (sb[i] - sb[x - 1]) * (i - y + 1) <= 1ll * (sb[i] - sb[y - 1])  * (i - x + 1 );
        });
    }
    rep(i, 0, n) rep(j, 1, n) {
        vector<int> S(j + 2);
        per(y, j, 1) S[y] = add(S[y + 1], F[i][ib[j][y] - 1]);
        for(int x = 1, y = 1; x <= n - i; x++) {
            while(y <= j && 1ll * (sa[ia[i][x]] - sa[i]) * (j - ib[j][y] + 1) > 1ll * (sb[j] - sb[ib[j][y] - 1]) * (ia[i][x] - i)) {
                y++;
            }
            F[ia[i][x]][j] = add(F[ia[i][x]][j], S[y]);     
        }
    }
    cout << F[n][n] << '\n';
    return 0;  
}
/*
可以双指针维护操作。

*/