#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(5);
    int we = 0;
    for(auto c : s) {
        if(c != '?') cnt[c - 'A']++;
        else we++;
    }
    int ans = 0;
    rep(i, 0, 3) {
        ans += min(n, cnt[i]) ;
        cnt[i] = n - cnt[i];
        cnt[i] = max(cnt[i], 0);
        int t = min(cnt[i], we);
        we -= t;
        // ans += t;
    }
    ans += we;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}