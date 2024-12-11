#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m = sqrt(n);
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i] ;
    int q; cin >> q;
    vector<VI> F(n + 1, VI(m + 1)) ;
    per(i, n, 1) rep(j, 1, m) {
        if(i + A[i] + j > n) F[i][j] = 1;
        else F[i][j] = F[i + A[i] + j][j] + 1;
    }
    for(int p, k; q--; ) {
        cin >> p >> k;
        if(k <= m) cout << F[p][k] << '\n';
        else {
            int cnt = 0;
            while(p <= n) {
                cnt++;
                p += A[p] + k; 
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}