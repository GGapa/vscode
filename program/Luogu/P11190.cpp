#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n; string s; cin >> s; s = " " + s;
    vector<int> cnt(27);
    int tag = 1;
    rep(i, 1, n) if(s[i] != s[1]) tag = false;
    if(tag || n == 1) return cout << "Shuiniao\n", void();
    tag = 0;
    rep(i, 1, n) cnt[s[i] - 'a']++;
    rep(i, 0, 26) if(cnt[i]) tag++;
    if(tag <= 2 && cnt[s[n / 2 + 1] - 'a'] == 1 && (n & 1)) return cout << "Shuiniao\n", void();
    else {
        cout << "Huoyu\n";
        cout << 1 << '\n';
        cout << n << " ";
        rep(i, 1, n) cout << i << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int qwq; cin >> qwq;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
5
1
5
aabaa
*/