#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

struct DSU {
    vector<int> sz, fa;
    vector<array<int, 2>> his;

    void init(int n) {
        sz.assign(n + 1, 1);
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }

    DSU() {}
    DSU(int n) {init(n); }

    int find(int x) {
        while(x != fa[x]) x = fa[x];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        his.push_back({x, y});
        sz[x] += sz[y];
        fa[y] = fa[x];
        return true;
    }

    int time() {return his.size(); }
    int size(int x) {return sz[x]; }
    bool same(int x, int y) {return find(x) == find(y); }

    void revert(int tim) {
        while(his.size() > tim) {
            int x = his.back()[0], y = his.back()[1];
            his.pop_back();
            fa[y] = y;
            sz[x] -= sz[y];
        }
    }
}dsu;

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    constexpr int N = 2e5 + 5;
    vector<AI> tr[N << 2];
    int ans[N << 2];
    int n, m;

    void init(int nn) {n = nn; ans[1] = 1; } 

    void modfiy(int L, int R, AI v, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x].emplace_back(v), void();
        int mid = l + r >> 1;
        if(L <= mid) modfiy(L, R, v, ls, l, mid);
        if(mid < R) modfiy(L, R, v, rs, mid + 1, r);
    }    
    void query(int x = 1, int l = 1, int r = n) {
        int otim = dsu.time();

        if(ans[x]) {
            for(auto i : tr[x]) {
                int u = i[0], v = i[1], uu = u + m, vv = v + m;
                if(dsu.same(u, v)) {
                    ans[x] = 0; 
                    break;
                }
                dsu.merge(u, vv);
                dsu.merge(uu, v);
            }
        }
    
        if(l == r) {
            cout << (ans[x] ? "Yes" : "No") << '\n';
            return dsu.revert(otim);
        }   

        ans[ls] = ans[rs] = ans[x];
        int mid = l + r >> 1;
        query(ls, l, mid); query(rs, mid + 1, r);
        dsu.revert(otim);
    }
}
#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    SGT::init(k); SGT::m = n;
    dsu.init(n * 2 + 1);
    for(int i = 1, x, y, l, r; i <= m; i++) {
        cin >> x >> y >> l >> r;
        SGT::modfiy(l + 1, r, {x, y});
    }
    SGT::query();
    return 0;
}