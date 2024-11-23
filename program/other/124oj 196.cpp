#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for (int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> mx1(n + 1), mx2(n + 1), x(n + 1), y(n + 1), d(n + 2), ax(n + 2), ay(n + 2);
    mx1[0] = -2e9, mx2[0] = 2e9;
    rep(i, 1, n) {
        cin >> x[i] >> y[i] >> d[i];
        mx1[i] = max(mx1[i - 1], x[i] + y[i]);
        mx2[i] = min(mx2[i - 1], x[i] - y[i]);
    }
    ax[n + 1] = x[n]; ay[n + 1] = y[n] - d[n]; d[n + 1] = d[n];
    per(i, n, 1) {
        int A = max(mx1[i] - d[i], ax[i + 1] + ay[i + 1] - d[i + 1] + d[i]);
        int D = min(mx2[i] + d[i], ax[i + 1] - ay[i + 1] + d[i + 1] - d[i]);
        ax[i] = (A + D) / 2, ay[i] = (A - D + 1) / 2;
    }
    rep(i, 1, n) cout << ax[i] << " " << ay[i] << '\n';
    return 0;
}
/*
6
21 27 1
23 27 3
19 27 5
21 33 6
23 29 6
26 30 7
*/