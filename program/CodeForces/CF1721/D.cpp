#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B = A;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i]; 
    auto check = [&](int x) {
        vector<int> a, b; 
        rep(i ,1, n) a.emplace_back(A[i] & x) ;
        rep(i, 1, n) b.emplace_back((~B[i]) & x) ;
        sort(a.begin(), a.end()); sort(b.begin(), b.end()) ;
        return a == b;
    };
    int ans  = 0;
    per(i, 30, 0) 
        if(check(ans | (1 << i))) ans |= (1 << i);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}