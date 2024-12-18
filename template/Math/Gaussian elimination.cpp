#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


using VD = vector<double>;
constexpr double eps = 1e-8;
bool Gauss(vector<VD> &A) {
    int n = (int)A.size() - 1;
    rep(i, 1, n) {
        int mx = i;
        rep(j, i + 1, n) if(fabs(A[j][i]) > fabs(A[mx][i])) mx = j;
        rep(j, 1, n + 1) swap(A[mx][j], A[i][j]);
        if(fabs(A[i][i]) < eps) return false;
        per(j, n + 1, 1) A[i][j] /= A[i][i];
        rep(j, 1, n) if(j != i) {
            double t = A[j][i] / A[i][i];
            rep(k, 1, n + 1) A[j][k] -= A[i][k] * t;
        }
    }
    return true;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<VD> A(n + 1, VD(n + 2));
    rep(i, 1, n) rep(j, 1, n + 1) cin >> A[i][j];
    if(Gauss(A) == false) return cout << "No Solution\n", 0;
    rep(i, 1, n) cout << fixed << setprecision(2) << A[i][n + 1] << '\n';
    return 0;
}