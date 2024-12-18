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
    rep(i, 1, n) cin >> A[i];
    int ans = 0;
    rep(i, 1, n) rep(j, i + 1, n) if(__gcd(A[i], 2 * A[j]) > 1 || __gcd(A[i] * 2, A[j]) > 1) ans++;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}