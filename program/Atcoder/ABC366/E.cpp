#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, d; cin >> n >> d;
    vector<int> X(n + 1), Y(n + 1);
    rep(i, 1, n) cin >> X[i] >> Y[i];
    sort(X.begin() + 1, X.end()); sort(Y.begin() + 1, Y.end());
    vector<int> sx(d + 1), sy(d + 1);
    auto calc = [&](vector<int> &t, int it) {
        int ret = 0;
        rep(i, 1, n) ret += abs(t[i] - it);
        return ret; 
    };
    int s = calc(X, X[(n + 1) / 2] - d);
    if(s <= d) sx[s]++;
    for(int i = X[(n + 1) / 2] - d + 1, j = 0; i <= X[(n + 1) / 2] + d; i++) {
        while(j < n && X[j + 1] < i) j++;
        s += j - (n - j);
        if(s <= d) sx[s]++;
    }
    // rep(i, 0, d) cout << sx[i] << " \n"[i == d];
    s = calc(Y, Y[(n + 1) / 2] - d);
    if(s <= d) sy[s]++;
    for(int i = Y[(n + 1) / 2] - d + 1, j = 0; i <= Y[(n + 1) / 2] + d; i++) {
        while(j < n && Y[j + 1] < i) j++;
        s += j - (n - j);
        if(s <= d) sy[s]++;
    }
    rep(i, 1, d) sy[i] += sy[i - 1];
    // rep(i, 0, d) cout << sy[i] << " \n"[i == d];
    int ans = 0;
    rep(i, 0, d) ans += sx[i] * sy[d - i];
    cout << ans << '\n';
    return 0;
}