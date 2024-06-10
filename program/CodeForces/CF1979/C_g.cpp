//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), ans(n + 1);
    rep(i, 1, n) cin >> A[i];
    ll sum = 2e9 - 1;
    rep(i, 1, n ) ans[i] = sum / A[i] + 1;
    sum = 0;
    rep(i, 1, n) sum += ans[i];
    rep(i, 1, n) if(ans[i] * A[i] <= sum) return cout << "-1\n", void();
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
7 9 3 17 9 13
857142858 666666667 2000000001 352941177 666666667 461538462
*/
// 5,004,955,832
// 