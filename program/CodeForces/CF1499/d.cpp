//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int N = 2e7;

int vis[N + 5]; // 记录质因子个数
int prime[N];

void init() {
    const int n = N;
    rep(i, 2, n) {
        if(!vis[i]) 
            prime[++prime[0]] = i, vis[i] = 1;
        for(int j = 1; j <= prime[0]; j++) {
            int p = prime[j];
            if(i * p > N) break;
            if(i % p == 0) {
                // cout << i << " " << p << endl; 
                vis[i * p] = vis[i];
                break;
            }
            vis[p * i] = vis[i] + 1;
        }
    }
}
 
void solve() {
    int c, d, x; cin >> c >> d >> x;
    int ans = 0;
    // g = x / (ck1k2-  d);
    // g = x / y
    // y = ck1k2 - d;
    // k1k2 = (y + d) / c                               
    // 
    for(int i = 1; i * i <= x; i++) {
        if(x % i) continue;
        int y1 = i, y2 = x / i;
        if((y1 + d) % c == 0) { 
            int k1k2 = (y1 + d) / c;
            ans += (1ll << vis[k1k2] );
        }
        if(y1 == y2) continue;
        if((y2 + d) % c == 0) { 
            int k1k2 = (y2 + d) / c;
            ans += (1ll << vis[k1k2] );
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    // for(auto p : prime) cout << p << '\n';
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
