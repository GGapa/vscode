//Stock Market
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int s, d, m;
int a[100][100], dp[500010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> d >> m;
    rep(i, 1, s) rep(j, 1, d) cin >> a[i][j];
    rep(i, 2, d) {
        int mx = 0;
        memset(dp, 0, sizeof(dp));
        rep(j, 1, s) rep(k, a[j][i - 1], m) {
                dp[k] = max(dp[k], dp[k - a[j][i - 1]] + a[j][i] - a[j][i - 1]);
                mx = max(dp[k], mx);
            }
        m += mx;
    }
    cout << m << '\n';
    return 0;
}
