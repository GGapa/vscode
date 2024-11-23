#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, T; LL a, b; cin >> n >> T >> a >> b;
    vector<int> tp(n + 1), ti(n + 1), id(n);
    rep(i, 1, n) cin >> tp[i];
    rep(i, 1, n) cin >> ti[i];
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        return ti[x] < ti[y];
    });
    int cnt1 = accumulate(tp.begin(), tp.end(), 0), cnt0 = n - cnt1;
    int ans = 0, ct1, ct0; ct1 = ct0 = 0;
    for(auto i : id) {
        int t = ti[i] - 1;
        if(ct1 * b + ct0 * a <= t) {
            int nt = t - ct1 * b - ct0 * a;
            int cnt = ct1 + ct0;
            cnt += min(nt / a, cnt0 * 1ll);
            nt -= min(nt / a, 1ll * cnt0) * a;
            cnt += min(nt / b, 1ll * cnt1);
            ans = max(ans, cnt);
        }
        if(tp[i] == 0) cnt0--, ct0++;
        else cnt1--, ct1++;
    }
    if(ct1 * b + ct0 * a <= T) ans = max(ans, ct1 + ct0);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
5 17 2 5
0 1 1 1 1
4 6 10 11 17
*/