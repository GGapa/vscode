#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const LL INF = 1e17;

void solve() {
    int n, m, k; cin >> n >> k >> m;
    vector<int> A(n + 1); 
    rep(i, 1, n) cin >> A[i] ;
    vector<vector<LL>> F(m + 1, vector<LL>(n + 1, -INF)) ;
    // fill(F[0].begin(), F[0].end(), 0);
    F[0][0] = 0;
    rep(i, 1, m) {
        list<int> q; q.push_back(0);
        rep(j, 1, n) {
            while(*q.begin() + k < j) q.pop_front();
            F[i][j] = F[i - 1][q.front()] + A[j] ;
            while(!q.empty() && F[i - 1][q.back()] < F[i - 1][j]) q.pop_back();
            q.push_back(j);
        }
    }
    LL ans = -1;
    rep(i, n - k + 1, n) ans = max(ans, F[m][i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
/*
F[i][j] [1, i] 选择了 j 个数字的方案数量。
*/