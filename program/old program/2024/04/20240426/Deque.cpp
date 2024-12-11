// Deque AT_dp_l
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
using VL = vector<ll>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> S(n + 1), A(n + 1);
    vector<VL> F(n + 1, VL(n + 1));
    rep(i, 1, n) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
        F[i][i] = A[i];
        per(j, i - 1, 1) {
            F[j][i] = max(S[i] - S[j - 1] - F[j + 1][i], S[i] - S[j - 1] - F[j][i - 1]);
        }
    }
    cout << F[1][n] - (S[n] - F[1][n]);
    return 0;
}