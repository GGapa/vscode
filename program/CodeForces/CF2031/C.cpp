#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    if((n & 1) && n < 26) return cout << -1 << '\n', void();
    vector<int> A(n + 1);
    if(n & 1) {
        A[1] = A[10] = A[26] = 1;
        rep(i, 2, 9) A[i] = (i) / 2 + 1;
        A[11] = A[27] = 6;
        rep(i, 12, 25) A[i] = i / 2 + 2;
        rep(i, 28, n) A[i] = i / 2 + 1;
    }
    else {
        rep(i, 1, n) A[i] = (i + 1) / 2;
    }
    rep(i, 1, n) cout << A[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}