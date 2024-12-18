#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;


LL calc(int x) {return x * (x - 1) / 2; }

void solve() {
    int n, b, x; cin >> n >> b >> x;
    vector<int> c(n + 1) ;
    rep(i, 1, n) cin >> c[i];
    int mx = *max_element(c.begin(), c.end()) ;
    vector<LL> F(mx + 1), ad(mx + 2);
    rep(i ,1, n) {
        vector<LL> g(c[i] + 1) ;
        rep(j, 2, c[i]) {
            LL t1 = c[i] / j, t2 = c[i] % j;
            if(t2 == 0) 
                g[j] += calc(j) * t1 * t1 * b;    
            else {
                g[j] += calc(t2) * (t1 + 1) * (t1 + 1) * b;
                g[j] += calc(j - t2) * t1 * t1 * b;
                g[j] += t2 * (j - t2) * (t1 + 1) * t1 * b;
            }
            F[j] += g[j];
        }
        ad[c[i] + 1] += g[c[i]];
    }    
    for(int i = 1, xx = 0; i <= mx; i++) xx += ad[i], F[i] += xx;
    LL ans = 0;
    rep(i, 1, mx) ans = max(ans, F[i] - (i - 1) * x) ;
    cout << ans << '\n';
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}