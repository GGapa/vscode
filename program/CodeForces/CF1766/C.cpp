#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;



void solve() {
    int n; cin >> n;
    string s[2];
    rep(i, 0, 1) cin >> s[i], s[i] = " " + s[i] + " ";
    vector<VI> vis(2, VI(n + 1)) ;
    function<void(int, int)> dfs = [&](int x, int y) {
        vis[x][y] = 1;
        if(s[x ^ 1][y] == 'B' && vis[x ^ 1][y] == 0) return dfs(x ^ 1, y);
        else if(s[x][y + 1] == 'B' && vis[x][y + 1] == 0) return dfs(x, y + 1);
    };
    bool ans = 0;
    if(s[0][1] == 'B') dfs(0, 1);
    ans = 1;
    rep(i, 0, 1) rep(j, 1, n) if(s[i][j] == 'B' && vis[i][j] == 0) ans = 0;
    if(ans) return cout << "YES\n", void(); 
    vis.assign(2, VI(n + 1));
    if(s[1][1] == 'B') dfs(1, 1);
    ans = 1;
    rep(i, 0, 1) rep(j, 1, n) if(s[i][j] == 'B' && vis[i][j] == 0) ans = 0;
    if(ans) return cout << "YES\n", void(); 
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}