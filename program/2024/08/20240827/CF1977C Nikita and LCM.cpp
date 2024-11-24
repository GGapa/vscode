#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<LL> A(n + 1) ;
    set<int> s;
    rep(i ,1, n) cin >> A[i], s.insert(A[i]);;
    sort(A.begin() + 1, A.end()) ;

    for(LL i = 1, x = 1; i <= n; i++) {
        x = x * A[i] / __gcd(x, A[i]) ;
        if(x > A[n]) return cout << n << '\n', void() ;
    }

    vector<map<LL, int>> F(n + 1);
    int ans = 0;
    rep(i, 1, n) {
        F[i] = F[i - 1];
        F[i][A[i]] = max(F[i][A[i]], 1);
        for(auto &p : F[i - 1]) {
            LL nt = p.first * A[i] / __gcd(p.first, A[i]) ;
            F[i][nt] = max(F[i][nt], p.second + 1) ;
            if(s.count(nt) == 0) ans = max(ans, F[i][nt]) ;
        }
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