#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s[3] ;
    rep(i, 0, 1) cin >> s[i], s[i] = "0" + s[i] ;
    vector<VI> F(2, VI(n + 3)) ;
    int sum = 0;
    rep(i, 0, 1) rep(j, 1, n) sum += (s[i][j] == '1') ;
    per(j, n - 1, 0) rep(i, 0, 1) {
        if(s[i^1][j] == '0') F[i][j] = F[i][j + 1] ;
        else if(s[i][j + 1] == '0') F[i][j] = min(F[i^1][j+1], F[i][j + 1] + 1) ;
        else if(s[i^1][j + 1] == '0') F[i][j] = min(F[i][j + 2] + 1, F[i^1][j + 2] + 1) ;
        else F[i][j] = min(F[i][j + 2] + 2, F[i^1][j + 2] + 1); 
    }
    cout << sum - F[0][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
/*
001110
111011

3 3 2 2 1 1
2 2 2 2 1 1

*/