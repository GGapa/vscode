//Maximum Distance
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 5000 + 5;
#define int long long

int x[N];
int y[N], n;

int dis(int i, int j) {
    return pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> x[i];
    rep(i, 1, n) cin >> y[i];
    int ans = 0;
    rep(i, 1, n)
        rep(j, 1, n) 
            ans = max(ans, dis(i, j));
    cout << ans << '\n';
    return 0;
}