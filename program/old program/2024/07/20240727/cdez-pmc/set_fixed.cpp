#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 26;
vector<int> G(N);
int n, m; 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u] |= 1 << v, G[v] |= 1 << u;
    int tp = (1 << n) - 1;
    vector<int>  F(tp + 1);
    rep(i, 0, n - 1) F[1 << i] = 1, G[i] |= 1 << i;
    rep(s, 1, tp) if(!F[s]) {
        int t = s & -s, x;
        for(x = 0; ((s >> x) & 1) == 0; x++)  ;
        // cout << bitset<10>(s) << "\n" << bitset<10>(s & (tp & ~G[x])) << "\n--------\n";
        F[s] = max(F[s ^ t], F[s & (tp & ~G[x])] + 1); 
    }
    int ans = 0;
    // rep(i, 1, tp) cout << F[i] << " \n"[i == tp];
    rep(i, 1, tp) ans += F[i];
    cout << ans << '\n';
    return 0;
}