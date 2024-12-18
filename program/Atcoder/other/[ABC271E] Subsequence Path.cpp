// [ABC271E] Subsequence Path
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(m + 1), B(m + 1), C(m + 1);
    rep(i, 1, m) cin >> A[i] >> B[i] >> C[i];
    vector<long long > F(n + 1, 1e18) ;
    F[1] = 0;
    for(int i = 1, x; i <= k; i++) {
        cin >> x;
        F[B[x]] = min(F[B[x]], F[A[x]] + C[x]);
    }
    cout << (F[n] < 1e18 ? F[n] : -1) << '\n';
    return 0;
}