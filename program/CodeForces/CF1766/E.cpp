#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 3e5 + 5;
LL F[N][4][4][4];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LL ans = 0;
    for(int i = 1, a; i <= n; i++) {
        cin >> a;
        F[i - 1][0][0][0]++;
        if(a == 0) {
            ans += 1LL * i * (n - i + 1) ;
            rep(x, 0, 3) rep(y, 0, 3) rep(z, 0, 3) F[i][x][y][z] += F[i - 1][x][y][z];    
        }
        else {
            rep(x, 0, 3) rep(y, 0, 3) rep(z, 0, 3) {
                if(x == 0 || (x & a)) F[i][a][y][z] += F[i - 1][x][y][z];
                else if(y == 0 || (y & a)) F[i][x][a][z] += F[i - 1][x][y][z];
                else F[i][x][y][a] += F[i - 1][x][y][z];
            }
        }
        rep(x, 0, 3) rep(y, 0, 3) rep(z, 0, 3) ans += 1ll * F[i][x][y][z] * ((x > 0) + (y > 0) + (z > 0)) ;
    }
    cout << ans << '\n';
    return 0;
}
/*
7
1 3 2 1 3 2 1
*/