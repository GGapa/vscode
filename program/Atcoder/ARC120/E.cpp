#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 3), F(n + 3);
    rep(i, 1, n) cin >> A[i];
    A[0] = A[1]; A[n + 1] = A[n];
    F[1] = INT_MAX;
    
    rep(i, 2, n) {
        F[i] = max(F[i - 2], (A[i + 1] - A[i - 2]) / 2);
        if(i >= 3) F[i] = min(F[i], max(F[i - 3], (A[i + 1] - A[i - 3]) / 2));
    }
    cout << F[n] << '\n';
    return 0;
}
