#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    int ans = INT_MAX;
    for(int i = 1; i + k - 1 <= n; i++) {
        ans = min(ans, abs(A[i + k - 1]) + abs(A[i + k - 1] - A[i]));
        ans = min(ans, abs(A[i]) + abs(A[i + k - 1] - A[i]));
    }
    cout << ans << '\n';
    return 0;
}