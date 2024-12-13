#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int mx = 0;

namespace LS {
    constexpr int N = 1e7 + 200;
    int pri[N], sum[N];
    bitset<N> vis;

    void init(){
        rep(i, 2, N - 1) {
            if(!vis[i]) pri[++pri[0]] = i;
            for(int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
                int tt = i * pri[j];
                vis[tt] = 1;
                if(i % pri[j] == 0) {
                    break;
                }
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

bool btw(int x, int y, int z) {
    if(x > y) swap(x, y);
    return x <= z && z <= y;   
}

void solve() {
    int k, l, m; cin >> k >> l >> m; 
    auto calc = [&](int L, int R) {
        int ret = 0;
        rep(i, L, R) if(i <= m || !vis[i]) ret++;
        return ret;
    };
    int L = 1, R = 4652357, res = -1;   
    int cnt = calc(L, L + k - 1);
    while(L <= R) {
        int mid = L + R >> 1;
        int t = calc(mid, mid + k - 1);
        if(t == l) return cout << mid << '\n', void();
        else if(btw(cnt, t, l)) R = mid - 1;
        else L = mid + 1;
        cnt = calc(L, L + k - 1);
    }
    cout << -1 << '\n', void();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LS::init(); 
    int T; cin >> T;
    while(T--) solve() ;
    return 0;
}