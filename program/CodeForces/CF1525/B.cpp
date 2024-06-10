//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    bool tag = true;
    rep(i, 1, n) cin >> A[i];
    rep(i, 2, n) if(A[i] < A[i - 1]) {
        tag = false;
        break;
    }
    if(tag ) return cout << 0 << '\n', void();
    if(A[1] == n && A[n] == 1) return cout << 3 << '\n', void();
    int ans = (A[1] != 1) + (A[n] != n);
    if(ans == 0) ans++;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}