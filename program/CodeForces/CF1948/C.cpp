#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<array<char, 2>> a(n + 1);
    bool tag = true;
    rep(i, 1, n) cin >> a[i][0];
    rep(i, 1, n) cin >> a[i][1];
    vector<array<int, 2>> F(n + 2);
    F[1][0] = 1;
    rep(i, 1, n) {
        if(i % 2 == 0) {
            F[i][0] |= F[i][1]; F[i + 1][1] |= F[i][1];
            if(a[i][0] != '<') F[i + 1][0] |= F[i][0];

            // if(a[i][1] != '<') F[i + 1][1] |= F[i][1];
        }
        else {
            F[i][1] |= F[i][0]; F[i + 1][0] |= F[i][0];
            if(a[i][1] != '<') F[i + 1][1] |= F[i][1];
            // F[i][1] |= F[i][0], F[i][0] |= F[i][1];
            // F[i + 1][0] |= F[i][0], F[i + 1][1] |= F[i][1];

        }
    }
    cout << (F[n][1] ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}