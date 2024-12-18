#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> s(n + 1), ans(1000);
    int mx = 0;
    vector<int> F(n + 1);
    rep(i, 1, n) {
        cin >> s[i];
        mx = max(mx, (int)s[i].size());
        F[i] = max(F[i - 1], mx);
        while(s[i].size() < mx) s[i] += "*";
    }
    rep(j, 0, mx - 1) {
        per(i, n, 1) if(j < F[i]) cout << s[i][j];
        cout << '\n';
    }
    return 0;
}