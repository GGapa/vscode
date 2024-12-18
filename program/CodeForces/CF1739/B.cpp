#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i] ;
    vector<int> ans = {A[1]} ;
    for(int i = 2, x = A[1]; i <= n; i++) {
        if(x - A[i] >= 0 && A[i] != 0) return cout << -1 << '\n', void();
        x += A[i];
        ans.push_back(x);
    }
    for(auto a : ans) cout << a << " ";
    cout << '\n'; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}