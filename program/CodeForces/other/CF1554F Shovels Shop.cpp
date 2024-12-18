#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(n + 1);
    rep(i, 1, n)cin >> A[i];
    sort(A.begin() + 1, A.end());

    vector<LL> S(n + 1);
    rep(i, 1, n) S[i] = S[i - 1] + A[i];
    vector<int> bu(n + 1);
    LL ans = LLONG_MAX;
    for(int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        if(a >= k) ans = min(ans, S[a] - S[b]) ;
        bu[a] = max(bu[a], b);
    }
    rep(i, 1, n) bu[i] = max(bu[i], bu[i - 1]);
    vector<LL> F(n + 1, 1e18);
    F[0] = 0;
    rep(i, 1, k) per(j, i, 1) {
        int len = i - j + 1;
        int t = bu[len];
        F[i] = min(F[i], F[j - 1] + S[i] - S[j + t - 1]) ;
    }
    cout << F[k] << '\n';
    return 0;
}