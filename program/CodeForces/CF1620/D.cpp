#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;



void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    auto check = [&](int x, int y) {
        int ret = 0;
        rep(i ,1, n) {
            int cnt = -1;
            rep(a, 0, x) rep(b, 0, y) if((A[i] - a - b * 2) % 3 == 0) {
                int t = (A[i] - a - b * 2) / 3;
                cnt = (cnt == -1 || t < cnt ? t : cnt);
            }
            if(cnt == -1) return (int)2e9;
            ret = max(ret, cnt);

        } 
        // cout << ret << '\n';
        return ret;
    };
    int ans = INT_MAX;
    rep(x, 0, 2) rep(y, 0, 2) ans = min(ans, check(x, y) + x + y);
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