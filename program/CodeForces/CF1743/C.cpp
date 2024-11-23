#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    int ans = 0;
    A[0] = INT_MAX;
    auto calc = [&](int l, int r) {
        if(l > r) return;
        int it = 0;
        rep(i, l, r) {
            if(A[it] > A[i]) it = i;
            ans += A[i];
        }
        if(s[l] == '0') ans -= A[it];
    };

    s += "0";
    for(int i = 1, l = 1, r = 1; i <= n + 1; i++) {
        if(s[i] != '1') {
            calc(l, r);
            l = i;
        }
        else {
            r = i;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}