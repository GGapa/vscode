#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    vector<int> cnt(30);
    ll ans = 0;
    bool tag  = 1;
    for(auto c : s) {
        int t = c - 'a';
        ans += accumulate(cnt.begin(), cnt.end(), 0) - cnt[t];
        if(cnt[t]) ans += tag, tag = 0;
        cnt[t]++;
    }
    cout << ans << '\n';
    return 0;
}