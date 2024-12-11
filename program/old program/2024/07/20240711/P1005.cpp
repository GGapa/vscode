//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
using BI = __int128;

ostream &operator<<(ostream &os, const BI &n) {
    if (n > 9) os << (n / 10);
    return os << (int)(n % 10);
}

BI bpow(int x) {
    BI ret = 1;
    while(x--) ret *= 2;
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;    
    BI ans = 0;
    rep(c ,1, n) {
        vector<int> A(m + 1);
        rep(i ,1, m ) cin >> A[i]; 
        vector<vector<BI>> F(m + 2, vector<BI>(m + 2));
        rep(i, 1, m) per(j, m, i + 1) {
            auto &f = F[i][j];
            // cout << bpow(m - (j - i)) << " " << i << " " << j << '\n';
            F[i + 1][j] = max(F[i + 1][j], f + bpow(m - (j - i)) * A[i]);
            F[i][j - 1] = max(F[i][j - 1], f + bpow(m - (j - i)) * A[j]);
        }
        BI tmp = 0;
        rep(i, 1, m) tmp = max(tmp, F[i][i] + bpow(m) * A[i]);
        ans += tmp;
    }
    cout << ans << '\n';
    return 0;
}
/*
一行一行考虑
F[i][j] 第 i 个元素，左边选到了第 j 个元素。
*/