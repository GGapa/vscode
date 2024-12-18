// Second Largest Query
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

struct SegTree {
    struct Node {
        int a, b, c, d;
        void insert(int x, int y) {
            if(!x) return ;
            if(x == a) b += y;
            else if(x == c) d += y;
            else if(x > a) c = a, d = b, a = x, b = y;
            else if(x > c) c = x, d = y;
        }
        friend Node operator+(Node A, Node B) {
            A.insert(B.a, B.b); A.insert(B.c, B.d);
            return A;
        }
        void init(int x) {
            a = x, b = 1;
            c = d = 0;
        }
    }res;
    vector<Node> T;
    bool tag;
    int n;
    SegTree(int _n) : n(_n), T((_n << 2) + 2) {}
    void modify(int it, int v, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        int rs = x * 2  + 1, ls = x * 2, mid = l + r >> 1;
        if(l == r) {
            T[x].init(v);
            return ;
        }
        if(it <= mid) modify(it, v, ls, l, mid);
        else modify(it, v, rs, mid + 1, r);
        T[x] = T[ls] + T[rs];
    }
    void query(int L, int R, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        // cout << l << " " << r << " " << (l + r >> 1) << '\n';
        if(L <= l && r <= R) {
            if(!tag) res = T[x];
            else res = res + T[x];
            tag = true; 
            return ;
        }
        int rs = x * 2  + 1, ls = x * 2, mid = l + r >> 1;
        if(L <= mid) query(L, R, ls, l, mid);
        if(R > mid) query(L, R, rs, mid + 1, r);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    SegTree T(n);
    for(int i = 1, x; i <= n; i++) cin >> x, T.modify(i, x);
    for(int i = 1, op, l, r; i <= q; i++) {
        cin >> op >> l >> r;
        if(op == 1) T.modify(l, r);
        else {
            T.tag = false;
            T.query(l, r);
            cout << T.res.d << '\n';
        }
    }
    return 0;
}