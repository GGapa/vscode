#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    int c1, c2; c1 = c2 = 1;
    rep(i ,1, s.size() - 1)  (s[i] == 'R' ? c1 : c2)++;
    if(c1 == s.size() && c2 == 1 || c2 == s.size()  && c1 == 1) return cout << n << '\n', void();
    c1 = n - c1, c2 = n - c2;
    int ans = 1;
    int i = 2; 
    while(s[i] == s[i - 1]) i++, ans++;
    for(; i < s.size(); i++) {
        ans++;
        ans += (s[i] == 'R' ? c2 : c1);
    }
    ans += (c1 + 1) * (c2 + 1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}