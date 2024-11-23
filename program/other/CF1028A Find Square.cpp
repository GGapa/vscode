#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<string> s(n + 1);
    rep(i, 1, n) cin >> s[i], s[i] = " " + s[i];
    vector<VI> pre(n + 1, VI(m + 1)), suf(n + 1, VI(m + 1));
    rep(i, 1, n) rep(j, 1, m) if(s[i][j] == 'B') pre[i][j] = pre[i][j - 1] + 1;
    rep(i, 1, n) rep(j, 1, m) if(s[i][j] == 'B') suf[i][j] = suf[i - 1][j] + 1;
    int ax, ay;
    rep(i, 1, n) per(j, m, 1) if(pre[i][j]) {
        ax = (j + j - (pre[i][j] - 1) + 1) / 2;
        goto s1;
    }
    s1 :
    per(i, n, 1) rep(j, 1, m) if(suf[i][j]) {
        ay = (i + i - (suf[i][j] - 1) + 1) / 2;
        goto s2;
    } 
    s2 : 
    cout << ay << " " << ax << '\n';
    return 0;
}