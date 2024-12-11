#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1000 + 5;

int n;
vector<int> G[N];
vector<array<int, 2>> e;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1, u, v, cnt = 0; i < n; i++) {
        cin >> u >> v;
        if(v != n) return cout << "NO\n", 0;
        e.push_back({u, v}) ;
    }
    using AI = array<int, 2> ;
    sort(e.begin(), e.end(), [&](const AI &x, const AI &y) {
        return x[0] < y[0] ;
    });
    vector<int> ans(n + 1), vis(n + 1);
    rep(i, 1, n - 1) {
        int t = e[i - 1][0] ;
        vis[t] = 1;
        if(i == 1 || e[i - 1] != e[i - 2]) ans[i] = t;
    }
    ans[n] = n;
    for(int i = 1, t = 1, nw = 1; i < n; i++) {
        if(ans[i]) nw = ans[i] ;
        else {
            while(vis[t]) t++;
            if(t > nw) return cout << "NO\n", 0;
            ans[i] = t; t++;
        }
    } 
    cout << "YES\n";
    rep(i, 1, n - 1) cout << ans[i] << " " << ans[i + 1] << '\n';
    return 0;
}
