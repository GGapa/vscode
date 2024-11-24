#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    if(n == 1) return cout << 0 << '\n', void();
    int t = 1, sum = 0;
    int ans = 0;
    bool tag = 0;
    while(t <= k && t < n) {
        ans++; t =  t * 2;
    }
    n -= t;
    if(n <= 0) return cout << ans << '\n', void();
    cout << max(n + k - 1, 0ll) / k + ans + tag << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}