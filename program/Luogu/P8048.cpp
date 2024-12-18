#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, L; cin >> n >> k >> L;
    vector<double> ans(k + 1), cnt(k + 1);
    for(int i = 1, lst = 0, del = 0, d, c; i <= n; i++) {
        cin >> d >> c;
        char op; cin >> op;
        if(op == 'L') {
            ans[c] += (d - lst) / 2.0;
            ans[(c + del) % k] += d / 2.0;
            rep(i, 0, k - 1) ans[(i + c) % k ] += cnt[i];
        }
        else {
            ans[c] += L - d;
            rotate(cnt.begin(), cnt.begin() + k - c, cnt.begin() + k);
            cnt[c] += (d - lst) / 2.0   ;
            (del += c) %= k;
            lst = d;
        }
    }
    rep(i, 0, k - 1) cout << fixed << setprecision(1) << ans[i] << '\n';
    return 0;
}