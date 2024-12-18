#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    struct Node {
        LL sum; 
        friend Node operator+(const Node &x, const Node &y) {
            Node ret;
            ret.sum = x.sum + y.sum;
            return ret;
        };
    }tr[N << 2];
    void build(int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x].sum = 0, void();
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }
    void modify(int L, int R, int v, int x = 1, int l = 1, int r = n) {
        if(tr[x].mx == 1) return ;
        if(l == r) {
            tr[x].sum = v;
            return ;
        } 
        int mid = l + r >> 1;
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(mid < R) modify(L, R, v, rs, mid + 1, r);
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
