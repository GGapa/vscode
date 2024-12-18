#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

#define ls (x << 1)
#define rs ((x << 1) | 1) 
struct SegTree {
    int n;
    struct Node {
        int v, tg;
    };
    vector<Node> T;
    SegTree(int _n) : n(_n), T(n << 2) {}
    void update(int x, int v) {
        T[x].v = T[x].tg = v;
    }
    void pushdown(int x) {
        if(T[x].tg == 0) return ;
        update(ls, T[x].tg); update(rs, T[x].tg);
        T[x].tg = 0;
    }
    void modify(int v, int L, int R, int x = 1, int l = 1, int r = -1)  {
        if(r == -1) r = n;
        if(L <= l && r <= R) return update(x, v);
        pushdown(x);
        int mid = l + r >> 1;
        if(L <= mid) modify(v, L, R, ls, l, mid);
        if(mid < R) modify(v, L, R, rs, mid + 1, r);
    }
    int query(int it, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(it == l && l == r) return T[x].v;
        pushdown(x);
        int mid = l + r >> 1;
        if(it <= mid) return query(it, ls, l, mid);
        else return query(it, rs, mid + 1, r);
        return 0;
    }
};
#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n + 1), B = A;
    rep(i ,1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    SegTree T(n);
    vector<array<int, 2>> q;
    q.push_back({1, 1}) ;
    for(int i = 1, op, x, y, k; i <= m; i++) {
        cin >> op >> x;
        if(op == 1) {
            cin >> y >> k;
            T.modify(q.size(), y, y + k - 1);
            q.push_back({y, x});
        }
        else {
            int id = T.query(x);
            int t = x - q[id][0];
            
            cout << (id == 0 ? B[x] : A[q[id][1] + t]) << '\n';
        }
    }
    return 0;
}