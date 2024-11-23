#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<LL> A(n + 1) ;
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    LL l = 1, r = n, ans = A[n];
    auto check = [&](LL x) {
        LL ti = 0;
        rep(i, 1, n) {
            if(!x) return false;
            if(A[i] >= ti + x) {
                ti = ti + x;
                x--;
            }
        }
        return true;
    };
    while(l <= r) {
        LL mid = l + r >> 1;
        if(check(mid)) {
            ans = min(ans, mid * (mid + 1) / 2);
            r = mid - 1; 
        }  
        else l = mid + 1;
    }
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