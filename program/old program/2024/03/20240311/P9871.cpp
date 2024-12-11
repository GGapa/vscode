// P9871 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

#define ls (x << 1)
#define rs ((x << 1) + 1)

struct SegTree {
    int n; 
    struct Node {
        ll mx, tag;
    };
    vector<Node> T;
    SegTree(int _n) : n(_n), T((n << 2) + 1) {}
    void apply(int x, int v) {
        T[x].mx += v;
        T[x].tag += v;
    }
    void pushdown(int x) {
        if(!T[x].tag) return ;
        apply(ls, T[x].tag);
        apply(rs, T[x].tag);
        T[x].tag = 0;
    }
    void modify(int L, int R, ll v, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        // if(l > r) return ;
        if(L <= l && r <= R) {
            apply(x, v);
            return ;
        }
        int mid = l + r >> 1;
        // cout << l << " " << r << " " << mid << endl;
        pushdown(x);
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(R > mid) modify(L, R, v, rs, mid + 1, r);
        T[x].mx = max(T[ls].mx, T[rs].mx);
    }
    ll query(int L, int R, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) 
            return T[x].mx;
        ll res = -1e18;
        int mid = l + r >> 1;   
        pushdown(x);
        if(L <= mid) res = max(res, query(L, R, ls, l, mid));
        if(R > mid) res = max(res, query(L, R, rs, mid + 1, r));
        return res;
    }
};

#undef ls
#undef rs
#undef mid
void solve() {
    int n ,m ,k ,d; cin >> n >> m >> k >> d;
    vector<int> L(m + 1), R(m + 1), v(m + 1), l(m + 1), r(m + 1), ls(1);
    rep(i, 1, m) {
        cin >> R[i] >> L[i] >> v[i];
        L[i] = R[i] - L[i] + 1;
        ls.push_back(L[i] - 1), ls.push_back(R[i] + 1);
    }
    sort(ls.begin(), ls.end());
    // int le = unique(ls.begin(), ls.end()) - ls;
    int nl = unique(ls.begin() + 1, ls.end()) - ls.begin() - 1;
    SegTree T(nl);
    T.modify(1, 1, ls[1] * d);
    using AI = array<int, 2>;
    vector<AI> Q[2 * m + 5];;
    rep(i, 1, m) {
        r[i] = lower_bound(ls.begin() + 1, ls.begin() + 1 + nl, R[i] + 1) - ls.begin();
        l[i] = lower_bound(ls.begin() + 1, ls.begin() + 1 + nl, L[i] - 1) - ls.begin();
        Q[r[i]].push_back({l[i], v[i]});
    }
    int it = 0, ans = 0;
    rep(i, 2, nl) {
        for(auto q : Q[i]) 
            T.modify(1, q[0], q[1]);
        while(ls[i] - ls[it] > k + 1) it++;
        ans = max(ans, T.query(it, i - 1) - (ls[i] - 1) * d);
        T.modify(i, i, ans + ls[i] * d);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, T; cin >> c >> T;
    while(T--) solve();
    return 0;
}

// https://www.luogu.com.cn/article/4t11n28u
// https://www.luogu.com.cn/paste/zigrrkm9