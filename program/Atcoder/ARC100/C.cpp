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
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i], A[i] -= i; 
    sort(A.begin() + 1, A.end());
    int b = A[(n + 1) / 2];
    LL ans = 0;
    rep(i, 1, n) ans += abs(A[i] - b);
    cout << ans << '\n';
    return 0;
}