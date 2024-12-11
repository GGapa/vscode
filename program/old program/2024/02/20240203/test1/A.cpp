//CSES-2425 Stack Weights
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
const int N = 2e5 + 5;
using namespace std;

int n;

struct tree {
    int mn, mx, tag;
    int l, r;
}t[N << 2];

#define ls x << 1
#define rs x << 1 | 1

void bulid(int x, int l, int r) {
    t[x].l = l; t[x].r = r;
    if(l == r) return ;
    int mid = l + r >> 1;
    bulid(ls, l, mid);
    bulid(rs, mid + 1, r);
}

void apply(int x, int tag) {    
    t[x].mx += tag; t[x].mn += tag; t[x].tag += tag;
}

void pushdown(int x) {
    if(!t[x].tag) return;
    apply(ls, t[x].tag);
    apply(rs, t[x].tag);
    t[x].tag = 0;
}

void pushup(int x) {
    t[x].mx = max(t[rs].mx, t[ls].mx);
    t[x].mn = min(t[rs].mn, t[ls].mn);
}

void modify(int x, int l, int r, int v) {
    if(t[x].r < l || t[x].l > r) return;
    if(l <= t[x].l && t[x].r <= r) 
        return apply(x, v);
    int mid = l + r >> 1;
    pushdown(x);
    modify(ls, l, r, v);
    modify(rs, l, r, v);
    pushup(x);
}

#undef ls
#undef rs

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    bulid(1, 1, n);
    rep(i, 1, n)  {
        int c, s;
        cin >> c >> s;
        if(s == 2) s = -1;
        modify(1, 1, c, s);
        if(t[1].mn >= 0) cout << ">\n";
        else if(t[1].mx <= 0) cout << "<\n";
        else cout << "?\n";
    }
    return 0;
}


