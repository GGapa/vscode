#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    ll sum = 0; cin >> sum;
    ll ans = 0;
    for(int i = 1, x; i < n; i++) {
        cin >> x;
        int t = ceil(1.0 * x * 100 / k);
        ans = max(t - sum, ans);
        sum += x;
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