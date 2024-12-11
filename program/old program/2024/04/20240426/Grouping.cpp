// Grouping AT_dp_u
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<VI> A(n + 1, VI(n + 1)); 
    rep(i, 0, n - 1) rep(j, 0, n - 1) cin >> A[i][j];
    int tp = (1 << n) - 1;
    vector<ll> F(tp + 1, 0), D(tp + 1, 0);
    rep(s, 0, tp) {
        vector<int> tmp;
        rep(i, 0, n - 1) if(s & (1 << i)) {
            for(auto j : tmp) F[s] += A[i][j];
            tmp.push_back(i);
        }
    }
    rep(s, 0, tp) {
        for(int t = s; t; t = (t - 1) & s) {
            D[s] = max(D[s], F[t] + D[s ^ t]);
        }
    }
    cout << D[tp] << '\n';
    return 0;
}
