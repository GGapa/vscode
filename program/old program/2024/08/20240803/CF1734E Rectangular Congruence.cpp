#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> B(n + 1);
    rep(i, 1, n) cin >> B[i];
    vector<VI> A(n + 1, VI(n + 1)) ;
    rep(i, 1, n) rep(j, 1, n) A[i][j] = (A[i][j - 1] + i) % n;
    rep(i, 1, n) {
        int t = B[i] - A[i][i];
        rep(j, 1, n) A[i][j] = (A[i][j] + t + n) % n;
    }
    rep(i, 1, n) rep(j, 1, n) cout << A[i][j] << " \n"[j == n];
    return 0;
}