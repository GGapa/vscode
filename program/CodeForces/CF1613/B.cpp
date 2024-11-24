#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n ;
    m = n / 2;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    // cout << m << '\n';
    rep(i, 1, m) cout << A[i + 1] << " " << A[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}