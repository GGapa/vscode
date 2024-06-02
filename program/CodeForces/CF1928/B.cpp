#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto & i : a) cin >> i;
    sort(a.begin(), a.end());
    int len = unique(a.begin(), a.end()) - a.begin();
    int ans = 0;
    for(int l = 0, r = 0; r < len; r++) {
        while(a[r] - a[l] >= n && l <= r) l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
      
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}