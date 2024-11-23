#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 100 + 5;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), F(n + 1, INF);
    rep(i, 1, n) cin >> A[i]; A[0] = 1;
    F[0] = 0;
    rep(i, 1, n) {
        int r = min(n, i + A[i] - 1);
        rep(j, i, r) F[r] = min(F[r], F[j - 1] + 1);
        rep(j, max(1, i - A[i] + 1), i) F[i] = min(F[i], F[j - 1] + 1);
        int t = INF;
        rep(j, max(1, i - A[i] + 1), i - 1) {
            t = min(t, F[j - 1]);
            r = min(A[j] + j - 1, n);
            if(r >= i) F[r] = min(F[r], t + 2);
        }
    }
    cout << F[n] << '\n';
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}