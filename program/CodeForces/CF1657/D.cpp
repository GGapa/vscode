#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, C; cin >> n >> C;
    vector<LL> F(C + 1);
    for(int i = 1, c, d, h; i <= n; i++) {
        cin >> c >> d >> h;
        F[c] = max(F[c], 1ll * d * h);
    }
    for(int c = 1; c <= C; c++) for(int nc = c; nc <= C; nc += c) {
        F[nc] = max(F[nc], F[c] * (nc / c)) ;
    }
    rep(i ,1, C) F[i] = max(F[i - 1], F[i]);
    int m; cin >> m;
    for(int i = 1; i <= m; i++)  {
        LL d, h; cin >> d >> h;
        int t = upper_bound(F.begin() + 1, F.end(), d * h) - F.begin();
        if(t > C) t = -1;
        cout << t << " \n"[i == m];
    }
    return 0;
}