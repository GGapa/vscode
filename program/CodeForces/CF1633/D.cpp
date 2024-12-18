#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e3 + 5, INF = 1e9;

int ex[N];

void init(){
    fill(ex, ex + N, INF);
    ex[1] = 0;
    rep(i ,1, 1e3) rep(j, 1, i) if(i + i / j < N)  
        ex[i + i / j] = min(ex[i + i / j], ex[i] + 1);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> b(n + 1), c = b;
    rep(i, 1, n) cin >> b[i];   // 花费
    rep(i, 1, n) cin >> c[i];   // 价钱
    rep(i ,1, n) {
        // int t = 1, cnt = 0;
        // while(t < b[i]) {
        //     rep(j, 1, t) if(t + t / j <= b[i]) {
        //         t += t / j;
        //         cnt++;
        //         break;
        //     }
        // }
        b[i] = ex[b[i]];
    }
    // rep(i ,1, n) cout << b[i] << " \n"[i == n];
    vector<int> F(k + 1);
    int ans = 0;
    rep(i, 1, n) per(j, k, b[i]) {
        auto &f = F[j];
        f = max(f, F[j - b[i]] + c[i]);
        ans = max(ans, f);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T; cin >> T;
    while(T--) solve();
    return 0;
}