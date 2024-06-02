#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    // int cnt = 0;
    vector<array<int, 2>> ans;
    set<array<int, 2>> cnt;
    for(int i = n, t; i > 2; i = ceil(1.0 * i / t)) {
        // cout << i << '\n';
        t = round(sqrt(i));
        // cout << t << '\n';
        rep(j, t + 1, min(n - 1, i)) if(!cnt.count({j, n}))ans.push_back({j, n}), cnt.insert({j, n});
        ans.push_back({n, t}); 
    }
    ans.push_back({n, 2});
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a[0] << " " << a[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1 2 3 4 5 6 7 8
1 2 3 1 1 1 1 8
1 2 3 1 1 1 1 3
1 2 1 1 1 1 1 3
1 2 1 1 1 1 1 2
1 1 1 1 1 1 1 2

*/