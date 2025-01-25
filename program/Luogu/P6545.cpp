#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int r, s, n; cin >> r >> s >> n;
    vector<VI> A(r + 1, VI(s + 1));
    rep(i, 1, r) rep(j, 1, s) cin >> A[i][j];
    return 0;
}
/*
考虑暴力 DP, F(i, j, k) 为走到 (i, j) 权值为 k 的方案数量。
值得注意的一点是，最多只会走 log 次就能够超过 n。
考虑容斥
*/