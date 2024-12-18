#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int h, w, n; cin >> h >> w >> n;
    int tp = (1 << max(h, w)) - 1;
    vector<string> A(h + 1);
    rep(i, 0, h - 1) cin >> A[i];
    vector<VI> H((1 << h) + 1, VI(10)), W((1 << w) + 1, VI(10)) ;
    rep(i, 0, h - 1) rep(j, 0, w - 1) rep(k, 1, 9) if(A[i][j] == '0' + k) 
        H[1 << i][k] |= 1 << j, W[1 << j][k] |= 1 << i;  
    rep(s, 1,( 1 << h )- 1) rep(i, 0, h - 1) rep(j, 1, 9) 
        H[s][j] |= H[s ^ (1 << i)][j];
    rep(s, 1, (1 << w )- 1) rep(i, 0, w - 1) rep(j, 1, 9) W[s][j] |= W[s ^ (1 << i)][j];
    vector<VI> F(2 * n + 1, VI(1 << max(w, h) + 1));
    F[0][(1 << h) - 1] = 1;
    rep(i, 0, 2 * n - 1) {
        if(i & 1) 
            rep(s, 0, (1 << w) - 1) rep(j, 1, 9) (F[i + 1][W[s][j]] += F[i][s]) %= mod;
        else
            rep(s, 0, (1 << h) - 1) rep(j, 1, 9) (F[i + 1][H[s][j]] += F[i][s]) %= mod; 
            
    }
    int ans = 0;
    rep(s, 1, (1 << max(h, w)) - 1) (ans += F[2 * n][s]) %= mod;
    cout << ans << '\n';
    return 0;
}