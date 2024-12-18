#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n +1);
    rep(i, 1, n) cin >> A[i];
    auto check = [&](int ct, int mx) {
        int c0 = ct / 2, c1 = (ct + 1) / 2 ;
        rep(i, 1, n) {
            int t = mx - A[i], op = min(t / 2, c0); 
            c0 -= op; t -= op * 2;
            c1 -= t;            
        }
        return c1 >= 0 && c0 >= 0 ;
    };
    int mx = *max_element(A.begin() + 1, A.end()) ;
    LL l = 0, r = 1e18, ans = 1;
    while(l <= r) {
        LL mid = l + r >> 1;
        if(check(mid, mx) || check(mid, mx + 1)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}