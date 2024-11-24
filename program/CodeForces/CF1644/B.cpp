#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    iota(A.begin(), A.end(), 0);
    per(i, n, 1) cout << A[i] << " \n"[i == 1];
    rep(i, 1, n - 1) {
        swap(A[i], A[i + 1]) ;
        per(j, n, 1) cout << A[j] << " \n"[j == 1];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}