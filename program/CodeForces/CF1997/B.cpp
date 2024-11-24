#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string a[2];
    cin >> a[0] >> a[1];
    a[0] = " " + a[0], a[1] = " " + a[1];
    int cnt = 0;
    rep(i, 0, 1) rep(j, 2, n - 1) 
        if(a[i][j] == '.' && a[i][j - 1] == '.' && a[i][j + 1] == '.' && a[i ^ 1][j] == '.' && a[i ^ 1][j - 1] == 'x' && a[i ^ 1][j + 1] == 'x') cnt++;
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}