#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int mx = 0;

namespace LS {
    constexpr int N = 1e7 + 1e6 + 5;
    int pri[N], phi[N], mi[N], mu[N], sum[N];
    bitset<N> vis;

    void init(){
        mu[1] = 1;
        rep(i, 2, N - 1) {
            if(!vis[i]) pri[++pri[0]] = i, mi[i] = i, phi[i] = i - 1, mu[i] = -1;
            for(int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
                int tt = i * pri[j];
                vis[tt] = 1;
                mi[tt] = pri[j];
                if(i % pri[j] == 0) {
                    phi[tt]  = phi[i] * pri[j];
                    break;
                }
                else phi[tt] = phi[i] * phi[pri[j]];
                mu[tt] = -mu[i];
            }
        }
        rep(i, 2, N - 1) sum[i] = sum[i - 1] + !vis[i];
        rep(i, 1, pri[0]) {
            if(pri[i] > 1e7) break;
            mx = i;
        }
    }
}
using LS::pri;
using LS::sum;
using LS::vis;

void solve() {
    int k, l, m; cin >> k >> l >> m;
    int L = 1, R = mx, res = -1;
    if(l == 0) {
        if(pri[mx + 1] - pri[mx] < k) return cout << -1 << '\n', void();
        return cout << pri[mx] << '\n', void();
    }
    while(L <= R) {
        int mid = L + R >> 1;   
        int t = pri[mid];
        if(t <= m) L = mid + 1;
        if(sum[t + k - 1] - sum[t - 1] > l) L = mid + 1;
        else if(sum[t + k - 1] - sum[t - 1] < l) R = mid - 1;
        else return cout << t << '\n', void();
    }
    rep(i, 1, m) {
        int cnt = 0;
        rep(j, i, i + k - 1) if(j <= m || vis[j]) cnt++;
        if(cnt == l) return cout << i << '\n', void();
    }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LS::init(); 
    int T; cin >> T;
    while(T--) solve() ;
    return 0;
}