// Partitioning by Palindromes
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<VI> hui(n + 1, VI(n + 1));
    rep(i, 1, n) {
        for(int l = i, r = i; l >= 1 && r <= n && s[l] == s[r]; l--, r++) 
            hui[l][r] = 1;
        for(int l = i, r = i + 1; l >= 1 && r <= n && s[l] == s[r]; l--, r++) 
            hui[l][r] = 1;
    }
    vector<int> D(n +1, -1);
    function<int(int)> dp=  [&](int x) {
        auto &d = D[x];
        if(d != -1) return d;
        if(hui[1][x]) return d = 1;
        if(x < 1) return d = 0;
        d = INT_MAX;
        rep(i, 1, x) if(hui[i][x]) {
            d = min(d, dp(i - 1) + 1);
        }
        return d;
    };
    cout << dp(n) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}