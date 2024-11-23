#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 1e7 + 5;
bitset<N> vis;
int n, T, p[N / 10], mn[N];

void init() {
    for (int i = 2; i <= N - 1; i++) {
        if (!vis[i]) {
            p[++p[0]] = i;
            mn[i] = i;
        }
        for (int j = 1; j <= p[0] && 1ll * i * p[j] < N; j++) {
            vis[i * p[j]] = 1;
            mn[i * p[j]] = p[j];
            if (i % p[j] == 0)
                break;
        }
    }
}

void solve() {
    int x, y; cin >> x >> y;
    if(x > y) swap(x, y) ;
    if(__gcd(x, y) != 1) return cout << 0 << '\n', void();
    if(y - x == 1) return cout << -1 << '\n', void();
    // rep(i, 1, p[0]) if(x % p[i] == y % p[i]) return cout << p[i] - x % p[i] << '\n', void();
    vector<int> tt;
    int t = y - x;
    while(t > 1) {
        tt.push_back(mn[t]);
        int ttt = mn[t];
        while(t % ttt == 0) t /= ttt;
    }
    int ans = INT_MAX;
    for(auto a : tt) ans = min(ans, a - x % a);
    cout << ans << '\n';
}

signed main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}