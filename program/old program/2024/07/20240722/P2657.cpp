#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int F[35][11][2];

string s;

int dfs(int i, int j, bool p) {
    auto &f = F[i][j][p];
    if(f != -1) return f;
    if(i >= s.size()) 
        return f = (j != 10);
    // cout << i << " " << j << ' ' << p << '\n';
    f =  0;
    bool ok = (j == 10);
    int mx = (p ? 9 : s[i] - '0');
    rep(t, ok, mx) if(abs(t - j) >= 2 || ok) {
        f += dfs(i + 1, t, p || t != mx);
    } 
    if(ok) f += dfs(i + 1, 10, 1);
    return f; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int l, r; cin >> l >> r;
    memset(F, -1, sizeof(F));
    s = to_string(r);
    int rr = dfs(0, 10, 0);
    s = to_string(l - 1);
    memset(F, -1, sizeof(F));
    cout << rr - dfs(0, 10, 0) << '\n';
    return 0;
}