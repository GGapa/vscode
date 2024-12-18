#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    if(count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')) return cout << -1 << '\n', void();
    
    vector<int> bel(n + 1); int ans = 1;
    for(int i = 1, cnt = 0, lt = 1; i <= n; i++) {
        if(s[lt] == ')') {
            if(s[i] == ')') cnt++;
            else cnt--;
        }
        else {
            if(s[i] == '(') cnt++;
            else cnt--;
        }
        if(cnt < 0) ans++, lt = i, cnt = 1;
        bel[i] = ans;
    }

    cout << min(ans, 2) << '\n';
    rep(i, 1, n) cout << 2 - bel[i] % 2 << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}