//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> F(n + 1), G(n + 1); //  从  0 开始 和 从 1 开始
    for(int i = 1, x = 0; i <= n; i++, x ^= 1) {
        if(x == s[i] - '0' || s[i] == '?') F[i] = 1;
        if((x ^ 1) == s[i] - '0' || s[i] == '?') G[i] = 1;
    }
    rep(i, 1, n)  {
        if(F[i] == 1) F[i] += F[i - 1];
        if(G[i]) G[i] += G[i - 1];
    }
    int ans= 0;
    rep(i, 1, n)  ans += max(F[i], G[i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >>  T;
    while(T--) solve();
    return 0;
}