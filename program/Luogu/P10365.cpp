#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

constexpr int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   
    int n; cin >> n;
    vector<int> L(n + 1), R(n + 1);
    rep(i, 1, n) cin >> L[i] >> R[i];

    vector<int> inv(n + 1);
    inv[1] = 1;
    rep(i, 2, n) inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;

    vector<VI> tl(n + 1, VI(__lg(n) + 1)), tr(n + 1, VI(__lg(n) + 1));
    {
        set<array<int, 2>> s;
        per(i, n, 1) {
            auto it = s.lower_bound({L[i], 0});
            while(it != s.end() && (*it)[0] <= R[i]) {
                int t = (*it)[1];
                if(t < 0) tr[-t][0] = i;
                else tl[t][0] = i;
                it = s.erase(it);
            }
            s.insert({L[i], i});
            s.insert({R[i], -i});
        }
    }


    rep(j, 1, __lg(n)) rep(i, 1, n) tl[i][j] = tl[tl[i][j - 1]][j - 1], tr[i][j] = tr[tr[i][j - 1]][j - 1];

    map<AI, int> mp;
    function<int(int, int)> lca = [&](int x, int y) {      // 注意这里编号越大深度越小。
        if(x == y) return x;
        if(!x || !y) return 0;
        if(mp.count({x, y})) return mp[{x, y}];

        int ox = x, oy = y;
        if(x > y) {
            per(i, __lg(n), 0) if(tr[x][i] > y) 
                x = tr[x][i];
            x = tr[x][0];
        }
        else {
            per(i, __lg(n), 0) if(tl[y][i] > x) 
                y = tl[y][i];
            y = tl[y][0];
        }
        return mp[{ox, oy}] = lca(x, y);
    };
 
    vector<int> F(n + 1);
    per(i, n, 1) {
        int l = tl[i][0], r = tr[i][0];
        F[i]++;
        F[l] += F[i], F[r] += F[i];
        F[lca(l, r)] -= F[i];
    }

    int ans = 0;
    rep(i, 1, n) (ans += inv[F[i]]) %= mod;

    cout << ans << '\n';
 
    return 0;
}