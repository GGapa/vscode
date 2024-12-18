#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s[2];
    rep(i, 0, 1) cin >> s[i], s[i] = " " + s[i];
    vector<VI> F(2, VI(n + 1));
    int l = 1, r = n;
    while(l <= n && s[0][l] == s[1][l] && s[0][l] == '.') l++;
    while(r >= 1 && s[0][r] == s[1][r] && s[0][r] == '.') r--;
    rep(i, l, r) {
        F[0][i] = min(F[0][i - 1] + 1 + (s[1][i] == '*'), F[1][i - 1] + 2);
        F[1][i] = min(F[1][i - 1] + 1 + (s[0][i] == '*'), F[0][i - 1] + 2);
    }
    cout << min(F[0][r], F[1][r]) - 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
