#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 2);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin(), A.end());

    for(int i = 1, l = 1, r = n / 2 + 1; i <= n; i++) {
        if(i & 1) B[i] = A[l++];
        else B[i] = A[r++];
    }

    B[0] = B[n], B[n + 1] = B[1];
    rep(i, 1, n) if(!(B[i - 1] < B[i] && B[i] > B[i + 1]) && !(B[i - 1] > B[i] && B[i] < B[i + 1])) return cout << "NO\n", void();
    cout << "YES\n";
    rep(i, 1 ,n) cout << B[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}