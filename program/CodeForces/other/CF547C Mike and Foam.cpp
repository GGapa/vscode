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
int F[N];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int n, q; cin >> n >> q;
    vector<vector<int>> rec(n + 1);
    vector<int> A(n + 1); 
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) {
        int t = A[i];
        set<int> tmp; 
        while(t > 1) {
            tmp.insert(mn[t]); rec[i].emplace_back(mn[t]);
            int tt = mn[t];
            while(t % tt == 0) t /= tt;
        }
    }
    vector<int> vis(n + 1);
    LL ans = 0, cnt = 0, n1 = 0, sum = 0;
    for(int x; q--; ) {
        cin >> x;
        if(vis[x]) {
            int m = rec[x].size(), tp = (1 << m) - 1;
            rep(i, 1, tp) {
                int t = __builtin_popcount(i);
                int tmp = 1;
                rep(j, 0, m - 1) if(i >> j & 1) tmp *= (rec[x][j]);
                F[tmp] -= 1;
            }
            rep(i, 1, tp) {
                int t = __builtin_popcount(i);
                int tmp = 1;
                rep(j, 0, m - 1) if(i >> j & 1) tmp *= (rec[x][j]);
                ans -= ((t & 1) ? 1 : -1) * F[tmp];
            }
        }
        else {
            int m = rec[x].size(), tp = (1 << m) - 1;
            rep(i, 1, tp) {
                int t = __builtin_popcount(i);
                int tmp = 1;
                rep(j, 0, m - 1) if(i >> j & 1) tmp *= (rec[x][j]);
                ans += ((t & 1) ? 1 : -1) * F[tmp];
            }
            rep(i, 1, tp) {
                int t = __builtin_popcount(i);
                int tmp = 1;
                rep(j, 0, m - 1) if(i >> j & 1) tmp *= (rec[x][j]);
                F[tmp] += 1;
            }
        }
        cnt += (vis[x] ? -1 : 1);
        vis[x] ^= 1;
        cout << cnt * (cnt - 1) / 2 - ans << '\n';
    }
    return 0;
}
/*
5 9
1 2 3 4 6
1
2
2
3
3
4
4
5
5

*/