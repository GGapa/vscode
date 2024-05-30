// Tour
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
using VD = vector<long double>;
const long double INF = 1e18 * 1.0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int n; cin >> n; ) {
        vector<array<int, 2>> A(n + 1);
        rep(i, 1, n) cin >> A[i][0] >> A[i][1];
        // sort(A.beign() + 1, A.end());
        vector<VD> F(n + 2, VD(n + 2, INF)), dis(n +1, VD(n  + 1));
        rep(i, 1, n ) rep(j, 1, n) 
            dis[i][j] = sqrt((A[i][0] - A[j][0]) * (A[i][0] - A[j][0]) + (A[i][1] - A[j][1]) * (A[i][1] - A[j][1]));
        F[1][1] = 0;
        rep(i, 1, n - 1) rep(j, 1, i) {
            F[i + 1][j] = min(F[i + 1][j], F[i][j] + dis[i][i + 1]);
            F[i + 1][i] = min(F[i + 1][i], F[i][j] + dis[j][i + 1]);
        }
        cout << fixed << setprecision(2) << F[n][n - 1] + dis[n][n - 1]<< '\n';
    }
    return 0;
}

// F(i, j) + dis(i, i + 1)-> F(i + 1, j) ;
// F(i, j) + dis(j, i + 1)-> F(i + 1, i) ;