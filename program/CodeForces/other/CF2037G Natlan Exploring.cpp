#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 5, mod = 998244353;

vector<int> num[N], p;
int F[N], mn[N], vis[N], A[N], cnt[N], n;

void init() {
    for(int i = 2; i < N; i++) {
        if(!vis[i]) p.emplace_back(i), mn[i] = i;
        for(auto pr : p) {
            if(i * pr >= N) break;
            vis[i * pr] = 1;
            mn[i * pr] = pr;
            if(i % pr == 0) break;
        }
    }

    rep(i, 1, N - 1) {
        int x = i;
        while(x > 1) {
            num[i].emplace_back(mn[x]);
            int t = mn[x];
            while(x % t == 0) x /= t;
        }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    cin >> n;
    rep(i, 1, n) cin >> A[i];
    
    F[1] = 1;
    rep(i, 1, n) {
        int m = num[A[i]].size(), tp = (1 << m) - 1;
        rep(s, 1, tp) {
            int nw = 1;
            rep(j, 0, m - 1) if(s >> j & 1) nw *= num[A[i]][j];
            (F[i] += (cnt[nw] * (__builtin_popcount(s) & 1 ? 1 : -1) % mod + mod) % mod) %= mod;
        }
        rep(s, 1, tp) {
            int nw = 1;
            rep(j, 0, m - 1) if(s >> j & 1) nw *= num[A[i]][j];
            (cnt[nw] += (F[i] % mod + mod) % mod) %= mod;
        }
    }
    // rep(i, 1, n) cerr << F[i] << "\n";
    cout << F[n] << '\n';
    return 0;
}