#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = unsigned long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("1.in", "r", stdin);
    LL n, k; cin >> n >> k;
    string s, t; cin >> s >> t; 
    s = " " + s, t = " " + t;
    LL ans = 0, cnt = 1;
    rep(i, 1, n) {
        cnt = cnt * 2 - (s[i] == 'b') - (t[i] == 'a');
        cnt = min(cnt, k * 2); ans += min(cnt, k);
    }
    cout <<  ans << '\n';
    return 0;
}