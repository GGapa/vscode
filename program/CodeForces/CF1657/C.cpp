#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int  n; cin >> n;
    string s; cin >> s; s = " " + s;
    int ans = 0, r = n;
    rep(i, 1, n) {
        if(s[i] == '(' && i != n) ans++, i++, r = min(r, n - i);
        else {
            
            for(i = i + 1; i <= n; i++) if(s[i] == ')') {
                r = min(r, n - i);
                ans++;
                break;
            }
        }
    }
    cout << ans << " " << r << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}