#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int mod = 2017;

struct Mat {
    int n; 
    vector<VI> A;
    vector<int>& operator [](int i)  {return A[i];} 
    const vector<int>& operator [](int i) const { return A[i]; }
    Mat(int _n) : n(_n) {A.assign(n + 1, VI(n + 1, 0)); }
    const Mat operator*(const Mat &B) const {
        Mat C(n);
        rep(i, 0, n) rep(j, 0, n) 
            rep(k, 0, n) (C[i][j] += (A[i][k] * B[k][j]) % mod) %= mod;
        return C;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    Mat ans(n), base(n);
    rep(i, 0, n) base[i][i] = base[i][0] = 1;
    for(int i = 1, u ,v; i <= m; i++) 
        cin >> u >> v, base[u][v] = base[v][u] = 1;
    int T; cin >> T;
    rep(i, 0, n) ans[i][i] = 1;
    while(T) {
        if(T & 1) ans = ans * base;
        base = base * base;
        T >>= 1;
    }
    int cnt = 0;
    rep(i, 0, n) (cnt += ans[1][i]) %= mod;
    cout << cnt << '\n'; 
    return 0;
}