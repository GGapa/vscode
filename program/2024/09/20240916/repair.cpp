#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define NOIP2024 RP++
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7;

LL add(const LL x, const LL y) {
    return (x + y + mod) % mod;
} 
 
LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> A(n), pw(n + 1);
    rep(i, 2, n) pw[i] = pw[i - 1] * 2 + 1;
    for(auto &a : A) cin >> a;
    int tp = (1 << n) - 1;
    vector<VI> F(tp + 1, VI(n + 1)), G = F;     // F[s][i] 以 S 的集合中，最大值比最大值大 i 的方案数，G 则代表代价
    rep(i, 0, n - 1) F[1 << i][0] = 1;

    rep(s, 1, tp) {
        int mx = 0, siz = 0;
        rep(i, 0, n - 1) if(s >> i & 1) mx = max(mx, A[i]), siz++;
        rep(i, 0, siz) if(F[s][i]) {
            rep(j, 0, n - 1) if(!(s >> j & 1)) {
                int nw = mx + i; nw = max(nw, A[j]) + (nw == A[j]); nw = max(mx, nw) - max(mx, A[j]);
                F[s | (1 << j)][nw] = add(F[s | (1 << j)][nw], F[s][i]);
                G[s | (1 << j)][nw] = add(G[s | (1 << j)][nw], G[s][i] + (1ll * (nw + max(mx, A[j])) * k % mod + pw[siz]) * F[s][i] % mod);
            }
       }
    }
    per(i, n, 0) if(F[tp][i]) 
        return cout << *max_element(A.begin(), A.end()) + i << " " << G[tp][i] << '\n', 0;
    return 0;
}