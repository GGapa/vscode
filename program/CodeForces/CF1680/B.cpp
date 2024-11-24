#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> A(n + 1);
    rep(i, 1, n) cin >> A[i], A[i] = " " + A[i];
    int sx, sy; sx = sy = 1e9;
    rep(i, 1, n) rep(j, 1, m) if(A[i][j] == 'R' && i + j < sx + sy) 
        sx = i, sy = j;
    rep(i, 1, n) rep(j, 1, m) if(A[i][j] == 'R' &&(i - sx < 0 || j - sy < 0)) 
        return cout << "NO\n", void();
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}