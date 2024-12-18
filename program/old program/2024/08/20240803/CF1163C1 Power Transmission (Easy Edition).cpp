#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const double INF = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<array<double, 2>> A(1);
    vector<int> X(n + 1), Y(n +1);
    rep(i ,1, n) cin >> X[i] >> Y[i];
    rep(i ,1, n) rep(j, i + 1, n) {
        double  k = (X[j] == X[i]) ? INF : 1.0 * (Y[j] - Y[i]) / (X[j] - X[i]);
        double b = (k >= INF) ? X[i] : 1.0 * Y[i] - k * X[i];
        // A.push_back({k, 1.0 * Y[i] - X[i] * k});
        A.push_back({k, b});
        
    }
    sort(A.begin() + 1, A.end()) ;
    A.erase(unique(A.begin() + 1, A.end()), A.end());
    int m = A.size() - 1;
    int ans = 0;
    rep(i, 1, m) rep(j, i + 1, m) {
        if(A[i][0] != A[j][0] || A[i][0] == A[j][0] && A[i][0] < INF && A[i][0] > 0 && A[i][1] == A[j][1]) ans++;
    }
    cout << ans << '\n';
    return 0;
}