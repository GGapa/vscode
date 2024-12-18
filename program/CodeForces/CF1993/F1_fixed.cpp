#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

map<pair<int, int>, LL> cnt;

void solve() {
    int n, k, w, h; cin >> n >> k >> w >> h;
    string s; cin >> s;
    LL x = 0, y = 0;
    LL L = 2 * w, R = 2 * h;
    cnt.clear();
    for(auto c : s) {
        if(c == 'L') x--;
        else if(c == 'R') x++;
        else if(c == 'D') y--;
        else y++;
        x = (x + L) % L, y = (y + R) % R;
        cnt[{x, y}]++;
    }
    LL ans = 0;
    rep(i, 0, k - 1 ) {
        LL nx = (-i * x % L + L) % L;
        LL ny = (-i * y % R + R) % R;
        ans += cnt[{nx, ny}];
    } 
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}