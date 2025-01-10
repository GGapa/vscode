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
    rep(j, 1, n) {
        int mx = j;
        rep(i, j, n) if(fabs(A[i][j]) >= eps) mx = i;
        if(fabs(A[mx][j]) < eps) return false;
        swap(A[j], A[mx]);
        per(i, n + 1, j) A[j][i] /= A[j][j];
        rep(i, 1, n) if(i != j){
            per(k, n + 1, j) A[i][k] -= A[j][k] * A[i][j];
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
/*
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<LL>;

constexpr int mod = 1e9 + 7;

namespace pre {
    constexpr LL qpow(LL x, LL y){
        LL ret = 1;
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod);
            (x = x * x % mod) ;
        }
        return ret;
    }

    constexpr LL inv(LL x) {return qpow(x, mod - 2); }
}   
using namespace pre;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<VI> A(n + 1, VI(n + 2));
    rep(i, 1, n) rep(j, 1, n) cin >> A[i][j];
    rep(j, 1, n) {
        int mx = j;
        rep(i, j, n) if(A[i][j]) mx = i;
        if(A[mx][j] == 0) return cout << "No Solution\n", 0;
        swap(A[j], A[mx]);
        per(i, n + 1, j) (A[j][i] *= inv(A[j][j])) %= mod;
        rep(i, 1, n) if(i != j){
            per(k, n + 1, j) A[i][k] = (A[i][k] - A[j][k] * A[i][j] % mod + mod) % mod;
        }
    }
    rep(i, 1, n) cout << A[i][n + 1] << '\n';
    return 0;
}
*/