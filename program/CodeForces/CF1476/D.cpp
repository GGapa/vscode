#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1), C = A, F= A;
    rep(i, 1, n) cin >> C[i];
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    int tmp = 0, ans = 0;
    rep(i, 2, n) {
        if(A[i] == B[i]) F[i] = C[i] + 1;
        else F[i] = max(C[i] + 1 + F[i - 1] - abs(A[i] - B[i]), C[i] + 1 + abs(A[i] - B[i]));
        ans = max(ans, F[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}