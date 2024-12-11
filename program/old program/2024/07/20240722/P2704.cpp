#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

const int M = 10;
int F[1 << M][1 << M][3];
vector<int> nxt[1 << M][1 << M];
vector<int> nt[1 << M];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n + 1);
    rep(i, 1, n) rep(j, 0, m - 1)  {
        char c; cin >> c;
        if(c == 'H') A[i] |= (1 << j);
    }
    int tp = (1 << m) - 1;
    vector<int> use;
    rep(x, 0, tp) if(((x << 2) & x) == 0 && ((x << 1) & x) == 0) use.push_back(x);
    for(auto x : use) if((x & A[1]) == 0)F[0][x][1] = __builtin_popcount(x);
    for(auto x : use) rep(y, 0, tp) if((x & y) == 0 && ((y << 2) & y) == 0 && ((y << 1) & y) == 0) nt[x].push_back(y);
    for(auto x : use) for(auto y : nt[x]) if((x & A[1]) == 0 && (y & A[2]) == 0) F[x][y][2] = __builtin_popcount(x) + __builtin_popcount(y);
    for(auto x : use) for(auto y : nt[x]) rep(z, 0, tp) if(((z << 2) & z) == 0 && (z & y) == 0 && (z & x) == 0 && ((z << 1) & z) == 0) nxt[x][y].push_back(z);
    int ans = 0;
    rep(i, 3, n) {
        int i1=  (i - 1) % 3, i2 = (i - 2) % 3, i0 = i % 3;
        for(auto x : use) for(auto y : nt[x]) for(auto z : nxt[x][y]) if((z & A[i]) == 0) {
            F[y][z][i0] = max(F[y][z][i0], F[x][y][i1] + __builtin_popcount(z));
        }
    }
    for(auto x : use) for(auto y : nt[x]) ans = max(ans, F[x][y][n % 3]);
    cout << ans << '\n';
    return 0;
}