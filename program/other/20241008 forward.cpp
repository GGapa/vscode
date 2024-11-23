#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

struct Mat {
    int n; 
    vector<VI> A;
    vector<int>& operator [](int i)  {return A[i];} 
    const vector<int>& operator [](int i) const { return A[i]; } //在矩阵乘法中放入这两个函数之后，便可以直接通过 `ans[1][5]` 访问数组元素，而不是 `ans.a[1][5]`。
    Mat(int _n) : n(_n) {A.assign(n + 1, VI(n + 1, 0)); }
    const Mat operator*(const Mat &B) const {
        Mat C(n);
        rep(i, 0, n) rep(j, 0, n) 
            rep(k, 0, n) (C[i][j] += (A[i][k] * B[k][j]) % mod) %= mod;
        return C;
    }
};

signed main() {
#ifdef ONLINE_JUDGE
    freopen("forward.in", "r", stdin);
    freopen("forward.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q, s, t; cin >> n >> m >> q >> s >> t;
    
    return 0;
}