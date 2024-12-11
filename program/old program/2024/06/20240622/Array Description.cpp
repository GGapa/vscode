//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int mod = 1e9+ 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    vector<VI> F(n + 1, VI(m + 1));
    if(A[1] == 0) rep(j, 1, m) F[1][j] = 1;
    else F[1][A[1]] = 1;
    rep(i, 2, n) {
        if(A[i]) 
            rep(j, max(1, A[i] - 1), min(m, A[i] + 1)) (F[i][A[i]] += F[i - 1][j]) %= mod;
        else {
            rep(j, 1, m) rep(k, max(j - 1, 1), min(j + 1, m)) (F[i][j] += F[i - 1][k]) %= mod;
        }
    }
    if(A[n]) cout << F[n][A[n]];
    else {
        int res = 0;
        rep(j, 1, m) (res += F[n][j]) %= mod;
        cout << res << '\n';
    }
    return 0;
} 