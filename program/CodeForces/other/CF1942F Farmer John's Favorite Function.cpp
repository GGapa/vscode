#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2e5 + 5, B = 500;
constexpr LL INF = 1e18 + 1;

int n, q; 
int bl[N], br[N], bel[N];
int idx;
LL A[N], F[N], G[N];

void update(int x) {
    int l = bl[x], r = br[x];
    F[x] = 0;
    rep(i, l, r) F[x] = sqrtl(F[x] + A[i]);
    G[x] = F[x] + 1;
    per(i, r, l) {
        __int128_t t = G[x];
        if(t * t > INF) {
            G[x] = INF;
            break;
        }
        G[x] = t * t - A[i];
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep(i, 1, n) cin >> A[i];
    for(int l = 1, r = min(n, B); l <= n; l = r + 1, r = min(n, r + B)) {
        ++idx;
        bl[idx] = l, br[idx] = r;
        rep(i, l, r) bel[i] = idx;
        update(idx);
    }

    for(int k; q--; ) {
        LL x;
        cin >> k >> x;
        A[k] = x;
        update(bel[k]);
        LL ans = 0;
        rep(i, 1, idx - 1) ans = F[i] + (ans >= G[i]);
        rep(i, bl[idx], n) ans = sqrtl(ans + A[i]);
        cout << ans << '\n';
    }

    return 0;
}