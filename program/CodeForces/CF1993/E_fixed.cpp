#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 1e9;

void solve() {
    int n, m; cin >> n >> m;
    vector<VI> A(n + 1, VI(m + 1)) ;
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> A[i][j], A[i][m] ^= A[i][j], A[n][j] ^= A[i][j], A[n][m] ^= A[i][j];
    vector<VI> dn(n + 1, VI(n + 1)), dm(m + 1, VI(m + 1));
    rep(i, 0, n) rep(j, 0, n) if(i != j) 
        rep(k, 0, m) dn[i][j] += abs(A[i][k] - A[j][k]);
    rep(i, 0, m) rep(j, 0, m) if(i != j) 
        rep(k, 0, n) dm[i][j] += abs(A[k][i] - A[k][j]);
    int tn = (1 << n + 1) - 1, tm = (1 << m + 1) - 1;
    vector<VI> ans(n + 1, VI(m + 1, INF));
    vector<VI> F(tn + 1, VI(n + 1, INF));
    rep(ban, 0, m) {
        fill(F.begin(), F.end(), VI(n + 1, INF));
        rep(i, 0, n) F[1 << i][i] = 0;
        rep(s, 0, tn) rep(i, 0, n) if(s >> i & 1 && F[s][i] < INF)  
            rep(j, 0, n) if(!(s >> j & 1))
                F[s | 1 << j][j] = min(F[s | 1 << j][j], F[s][i] + dn[i][j] - abs(A[i][ban] - A[j][ban]));
        rep(i, 0, n) rep(j, 0, n) if(i != j) 
            ans[i][ban] = min(ans[i][ban], F[tn ^ 1 << i][j]);
    }
    F.assign(tm + 1, VI(m + 1, INF)) ;
    rep(ban, 0, n) {
        fill(F.begin(), F.end(), VI(m + 1, INF));
        rep(i, 0, m) F[1 << i][i] = 0;
        rep(s, 0, tm) rep(i, 0, m) if(s >> i & 1 && F[s][i] < INF)
            rep(j, 0, m) if(!(s >> j & 1)) 
                F[s | 1 << j][j] = min(F[s | 1 << j][j], F[s][i] + dm[i][j] - abs(A[ban][i] - A[ban][j]));
        rep(i, 0, m) {
            int x = INF;
            rep(j, 0, m) if(i != j) 
                x = min(x, F[tm ^ (1 << i)][j]);
            ans[ban][i] += x;
        }
    }
    int ret = INF;
    rep(i, 0, n) ret = min(ret, *min_element(ans[i].begin(), ans[i].end()));
    cout << ret << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}