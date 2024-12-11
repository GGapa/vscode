#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> A(n + 1) ;
    rep(i, 1, n) cin >> A[i], A[i] = " " + A[i];
    for(int i = 1; i + 3 <= n; i += 3) {
        int it = 1;
        rep(j, 1, m) if(A[i + 1][j] == 'X' || A[i + 2][j] == 'X') it = j;
        A[i + 1][it] = A[i + 2][it] = 'X';
    }
    rep(j, 1, m) {
        bool tag = false;
        rep(i, n - (n - 1) % 3 + 1, n) if(A[i][j] == 'X') tag = true;
        if(tag) rep(i, n - (n - 1) % 3 + 1, n) A[i][j] = 'X';
    }
    rep(i, 1, n) rep(j, 1, m) cout << ((i - 1) % 3 == 0 ? 'X' : A[i][j]) << (j == m ? "\n" : "");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}