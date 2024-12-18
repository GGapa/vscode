#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

int n;

namespace LS {
    constexpr int N = 5e6 + 5, B = 6;
    int pri[N], phi[N], dep[N], fa[B +1][N];
    bool vis[N];

    void init(){
        rep(i, 2, N - 1) {
            if(!vis[i]) pri[++pri[0]] = i, phi[i] = i - 1;
            for(int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
                int tt = i * pri[j];
                vis[tt] = 1;
                if(i % pri[j] == 0) {
                    phi[tt]  = phi[i] * pri[j];
                    break;
                }
                else phi[tt] = phi[i] * phi[pri[j]];
            }
        }
        rep(i, 1, N - 1) dep[i] = dep[phi[i]] + 1, fa[0][i] = phi[i];
        rep(i, 1, B) rep(j, 1, N - 1) fa[i][j] = fa[i - 1][fa[i - 1][j]];
    }
    int lca(int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);
        for (int i = B; i >= 0; i--) 
            if (dep[fa[i][x]] >= dep[y]) x = fa[i][x];
        if (x == y) return x;
        for (int i = B; i >= 0; i--)
            if (fa[i][x] != fa[i][y]) {
                x = fa[i][x];
                y = fa[i][y];
            }
        return fa[0][x];
    }
}
using LS::phi;
using LS::lca;
using LS::dep;

constexpr int N = 1e5 + 5;

int A[N];

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    struct Node {
        LL sum; int v, mx;
        friend Node operator+(const Node &x, const Node &y) {
            Node ret;
            ret.v = lca(x.v, y.v);
            ret.sum = x.sum + y.sum;
            // ret.tag = x.tag && y.tag;
            ret.mx = max(x.mx, y.mx);
            return ret;
        };
    }tr[N << 2];
    void build(int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x].sum = dep[A[l]], tr[x].v = tr[x].mx = A[l], void();
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }
    void modify(int L, int R, int x = 1, int l = 1, int r = n) {
        if(tr[x].mx == 1) return ;
        if(l == r) {
            tr[x].mx = tr[x].v = phi[tr[x].v];
            tr[x].sum = dep[tr[x].v];
            return ;
        } 
        int mid = l + r >> 1;
        if(L <= mid) modify(L, R, ls, l, mid);
        if(mid < R) modify(L, R, rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }
    Node query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x];
        int mid = l + r >> 1;
        if(L <= mid && mid < R) return query(L, R, ls, l, mid) + query(L, R, rs, mid + 1, r);
        if(L <= mid) return query(L, R, ls, l, mid);
        if(mid < R) return query(L, R, rs, mid + 1, r);
        assert(0);
        return Node{};
    }
}
#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    rep(i, 1, n) cin >> A[i];

    LS::init();
    SGT::build();

    for(int o, l, r; q--; ) {
        cin >> o >> l >> r;
        if(o == 1) SGT::modify(l, r);
        else {
            auto tmp = SGT::query(l, r);
            cout << tmp.sum - dep[tmp.v] * 1ll * (r - l + 1) << '\n';
        }
    }
    return 0;
}
