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
    vector<VI> A(n + 1, VI(2 * n + 1));
    rep(i, 1, n) rep(j, 1, n) cin >> A[i][j];
    rep(i, 1, n) A[i][n + i] = 1;
    rep(j, 1, n) {
        int mx = j;
        rep(i, j, n) if(A[i][j]) mx = i;
        if(A[mx][j] == 0) return cout << "No Solution\n", 0;
        swap(A[j], A[mx]);
        per(i, 2 * n, j) (A[j][i] *= inv(A[j][j])) %= mod;
        rep(i, 1, n) if(i != j){
            per(k, 2 * n, j) A[i][k] = (A[i][k] - A[j][k] * A[i][j] % mod + mod) % mod;
        }
    }
    rep(i, 1, n) rep(j, 1, n) cout << A[i][j + n] << " \n"[j == n];
    return 0;
}