#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> ans;
    ans.push_back(a);
    for(int i = 1, t = n; i < n / 2; i++, t--) {
        if(t != b)ans.push_back(t);
        else i--;
        if(t <= a)  return cout << -1 << '\n', void();
    }
    ans.push_back(b);
    for(int i = 1, t = 1; i < n / 2; i++, t++) {
        if(t != a) ans.push_back(t);
        else i--;
        if(t >= b ) return cout << -1 << '\n', void();
    }
    rep(i, 0, n - 1) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}