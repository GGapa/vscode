#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> cnt(5), deg(n + 1);
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, deg[u]++, deg[v]++;
    string s; cin >> s; s = " " + s;
    rep(i, 2, n) {
        if(deg[i] == 1) {
            if(s[i] == '?') cnt[2]++;
            else cnt[s[i] - '0']++;
        }
        else if(s[i] == '?') cnt[3]++;
    }
    cnt[3] += s[1] == '?';
    if(s[1] != '?') return cout << cnt[(s[1] - '0') ^ 1] + (cnt[2] + 1) / 2 << '\n', void() ;
    int ans = max(cnt[0], cnt[1]) + cnt[2] / 2;
    if(cnt[0] == cnt[1] && (cnt[3] & 1) == 0) ans = max(ans, (cnt[2] + 1) / 2 + cnt[0]);
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