#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    int k; 
    int x, t;
    int ans = 0;
    cin >> k;  
    cin >> x;
    rep(i, 2, k) cin >> t;
    ans = max(ans, (t - x) * m);
    cin >> k;  
    cin >> x;
    rep(i, 2, k) cin >> t;
    ans = max(ans, (t - x) * m);
    cin >> k;  
    cin >> x;
    rep(i, 2, k) cin >> t;
    ans = max(ans, (t - x) * n);
    cin >> k;  
    cin >> x;
    rep(i, 2, k) cin >> t;
    ans = max(ans, (t - x) * n);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}