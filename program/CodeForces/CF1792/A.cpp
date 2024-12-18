#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end()) ;
    int ct1, ct2; ct1 = ct2 = 0;
    rep(i, 1, n) {
        if(A[i] == 1) ct1++;
        else if(A[i] == 2) ct2++;
    }
    int ans = 0; ans += ct1 / 2;
    n -= ct1 / 2 * 2;
    cout << ans + n << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}