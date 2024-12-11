#include <bits/stdc++.h>
using namespace std;
const int N = 50000 + 5;

int n, m;

struct tree {
    int l, r;
    int perl, perr, mx, len;
    int tag;
}t[N << 2];

#define ls x << 1 
#define rs x << 1 | 1

void apply(int x, int tag) {
    t[x].perl = t[x].perr = t[x].mx = tag;
}

void pushdown(int x) {
    if(t[x].tag == 0) return;
    t[ls].tag = t[rs].tag = t[x].tag;
    if(t[x].tag == 1) {
        apply(ls, 0); 
        apply(rs, 0);
    }
    if(t[x].tag == 2) {
        apply(ls, t[ls].len);
        apply(rs, t[rs].len);
    }
    t[x].tag = 0;
}

void pushup(int x) {
    if(t[ls].mx == t[ls].len) 
        t[x].perl = t[ls].mx + t[rs].perl;
    else 
        t[x].perl = t[ls].perl;
    if(t[rs].mx == t[rs].len) 
        t[x].perr = t[rs].mx + t[ls].perr;
    else 
        t[x].perr = t[rs].perr;
    t[x].mx = max({t[ls].mx, t[rs].mx, t[ls].perr + t[rs].perl});
}

void bulid(int x, int l, int r) {
    t[x].l = l; t[x].r = r;
    t[x].len = t[x].perl = t[x].perr = t[x].mx = r - l + 1;
    if(l == r) 
        return ;
    int mid = (l + r) >> 1;
    bulid(ls, l, mid);
    bulid(rs, mid + 1, r);
}

void modify(int x, int l, int r, int tag) {
    if(l <= t[x].l && t[x].r <= r) {
        if(tag == 1) apply(x, 0);
        if(tag == 2) apply(x, t[x].len);
        t[x].tag = tag;
        return ;
    }
    pushdown(x);
    int mid = (t[x].l + t[x].r) >> 1;
    if(l <= mid) modify(ls, l, r, tag);
    if(r > mid) modify(rs, l, r, tag); 
    pushup(x);
}

int query(int x, int l, int r, int v) {
    if(t[x].l == t[x].r) return t[x].l;
    pushdown(x);
    int mid = (t[x].l + t[x].r) >> 1;
    if(t[ls].mx >= v) return query(ls, l, r, v);
    if(t[ls].perr + t[rs].perl >= v) return mid - t[ls].perr + 1;
    else return query(rs, l, r, v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    cin >> n >> m;
    bulid(1, 1, n);
    for(int i = 1, op, x, y; i <= m; i++) {
        cin >> op >> x;
        if(op == 1) {
            if(t[1].mx < x) {
                cout << 0 << '\n';
                continue;
            }
            int tmp = query(1, 1, n, x);
            modify(1, tmp, tmp + x - 1, 1);
            cout << tmp << '\n';
        }
        if(op == 2) {
            cin >> y;
            modify(1, x, x + y - 1, 2);
        }
    }
    return 0;
}