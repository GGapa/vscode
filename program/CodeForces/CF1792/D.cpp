#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<VI> A(n + 1, VI(m + 1));
    vector<int> B(m + 1);
    rep(i, 1, n) rep(j, 1, m) cin >> A[i][j];
    set<vector<int>> s[11];
    rep(i, 1, n) {
        rep(j, 1, m) B[A[i][j]] = j;
        rep(j, 1, m) s[j].emplace(B.begin() + 1, B.begin() + 1 + j);
    }  
    rep(i, 1, n) {
        int ans = 0;
        per(j, m, 1) if(s[j].count(vector<int>(A[i].begin() + 1, A[i].begin() + 1 + j))) {
            ans = j; break;
        }
        cout << ans << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}