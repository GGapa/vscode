#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if(a < b) swap(a, b) ;
    vector<int> A(n + 1) ;
    set<LL> s;
    rep(i ,1, n) cin >> A[i], s.insert(A[i]);
    if(s.size() == 1) return cout << 0 << '\n', void();
    sort(A.begin() + 1, A.end()) ;
    int g = __gcd(a, b) ;
    LL ans = LLONG_MAX;
    rep(i, 1, 2 * n) {
        if(s.size() == 1) return cout << 0 << '\n', void();
        LL t = *s.begin(); s.erase(s.begin());
        LL ad = (*s.rbegin() - t) / g;
        ad += (ad == 0) ;
        s.insert(t + ad * g) ;
        ans = min(*s.rbegin() - *s.begin(), ans) ;
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
/*

*/
