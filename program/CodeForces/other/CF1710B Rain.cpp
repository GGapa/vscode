#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;


void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 2>> a(n + 1);
    rep(i, 1, n) cin >> a[i][0] >> a[i][1];
    // sort(a.begin() + 1, a.end());

    map<LL, LL> sum;
    rep(i, 1, n) {
        sum[a[i][0] - a[i][1]]++;
        sum[a[i][0]] -= 2;
        sum[a[i][0] + a[i][1]]++;
    }

    const LL INF = 1e18;
    LL lst = -INF, now = 0, up = 0;
    LL mx1 = -INF, mx2 = -INF;
    for(auto p : sum) {
        if(lst != -INF) now += up * (p.first - lst);
        up += p.second;
        lst = p.first;
        if(now > m) mx1 = max(mx1, now + p.first - m);
        if(now > m) mx2 = max(mx2, now - p.first - m);
        // cout << now << '\n';
        // cerr << p.first << " " << now << '\n';
    }
    // cerr << mx1 << " " << mx2 << '\n';
    // rep(i, 1, n) cout << a[i][1] << " " << a[i][0] << '\n';
    rep(i, 1, n) cout << ((mx1 <= a[i][0] + a[i][1]) && (mx2 <= a[i][1] - a[i][0])) ;
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
3 6
1 5
5 5
3 4
*/