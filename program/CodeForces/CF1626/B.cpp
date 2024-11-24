#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    int it = 1;
    rep(i ,1, n - 1) if(s[i] - '0' + s[i + 1] - '0' >= 10) it = i;
    rep(i ,1 ,it - 1) cout << s[i] ;
    cout << s[it] + s[it + 1] - '0' - '0';
    rep(i, it + 2, n) cout << s[i];
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}