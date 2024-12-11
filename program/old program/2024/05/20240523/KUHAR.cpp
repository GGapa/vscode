#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n + 1), B(n + 1), sm = A, pm = A, sv = A, pv = A;
    rep(i, 1, n) cin >> A[i] >> B[i] >> sm[i] >> pm[i] >> sv[i] >> pv[i];
    auto calc = [&](int x) {
        int res = 0;
        rep(i, 1, n) {
            int nd = max(0, x * A[i] - B[i]);
            int ct = (nd + sm[i] - 1) / sm[i];
            int tmp = ct * pm[i];
            // cout << nd << " " << ct << '\n';
            rep(j, 0, ct) {
                int nnd = nd - j * sm[i];
                int vct = (nnd + sv[i] - 1) / sv[i];
                // cout << nnd << " " <<  vct << '\n';
                tmp = min(tmp, j * pm[i] + vct * pv[i]);
            }
            res += tmp;
        }   
        return res;
    };
    int l = 0, r = 1e5, ans;
    while(l <= r) {
        int mid = l + r >> 1;
        if(calc(mid) <= m) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}

