// 20:07
// -1
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

#define ls (x << 1)
#define rs ((x << 1) | 1) 

namespace SGT {
    const int N = 2e5 + 5;
    struct Node {int  l, r; LL val, tag; } tr[N << 2];
    int n; 
    void pushup(int x) {tr[x].val = max(tr[ls].val, tr[rs].val); }
    void init(int nn) {n = nn; }
    void apply(int x, LL v) {
        tr[x].val += v;
        tr[x].tag += v;
    }
    void pushdown(int x) {
        if(tr[x].tag == 0) return ;
        apply(ls, tr[x].tag); apply(rs, tr[x].tag);
        tr[x].tag = 0;
    }
    void modify(int L, int R, LL v, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return apply(x, v); 
        int mid = l + r >> 1;
        pushdown(x);
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(mid < R) modify(L, R, v, rs, mid + 1, r);
        pushup(x);
    }
};
#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> G(n + 1);
    SGT::init(n);
    for(int i = 1, l, r, a; i <= m; i++) {
        cin >> l >> r >> a;
        G[r].emplace_back(l, a);
    }
    using SGT::tr;
    rep(r, 1, n) {
        SGT::modify(r, r, max(tr[1].val, 0ll));
        for(auto i : G[r]) {
            int l = i.first, a = i.second;
            SGT::modify(l, r, a);
        }
    }
    cout << max(0ll, tr[1].val) << '\n';
    return 0;
}