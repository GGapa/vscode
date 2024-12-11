#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


void solve() {
    int n, m; cin >> n >> m;
    vector<VI> A(n + 1) ;
    vector<int> mx(n + 1), S(n + 2);
    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        mx[x] = max(mx[x], y);
        S[x]++; S[y + 1]--;
    }
    rep(i, 1, n) S[i] += S[i - 1], mx[i] = max(mx[i], mx[i - 1]); 
    vector<int> F(n + 1);
    rep(i, 1, n) {
        F[i] = max(F[i], F[i - 1]);
        F[mx[i]] = max(F[mx[i]], F[i - 1] + S[i]);
    }
    cout << F[n] << '\n';
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}