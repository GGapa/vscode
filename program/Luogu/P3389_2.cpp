#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using VD = vector<double>;

constexpr double eps = 1e-7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<VD> A(n + 1, VD(n + 2));
    rep(i, 1, n) rep(j, 1, n + 1) cin >> A[i][j];
    rep(j, 1, n) {
        int mx = j;
        rep(i, j, n) if(fabs(A[i][j]) >= eps) mx = i;
        if(fabs(A[mx][j]) < eps) return cout << "No Solution\n", 0;
        swap(A[j], A[mx]);
        per(i, n + 1, j) A[j][i] /= A[j][j];
        rep(i, 1, n) if(i != j){
            per(k, n + 1, j) A[i][k] -= A[j][k] * A[i][j];
        }
    }
    rep(i, 1, n) cout << fixed << setprecision(2) << A[i][n + 1] << '\n';
    return 0;
}
