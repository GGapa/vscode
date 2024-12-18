#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 2e5 + 5;
struct tree {
    int sum;
    int m1, m2;
    int t1, t2, t3, t4;
    int l, r;
}t[N << 2];

int n, q;

#define ls x << 1
#define rs x << 1 | 1

void apply(int x, int t1, int t2, int t3, int t4) {
    if(t2 != -1) {
        t[x].t2 = t2;
        t[x].t1 = 0;
        t[x].m1 = t2;
    }   
    t[x].t1 += t1, t[x].m1 += t1;
    if(t4 != -1) {
        t[x].t4 = t4;
        t[x].t3 = 0;
        t[x].m2 = t4;
    }
    t[x].t3 += t3, t[x].m2 += t3;
}

void pushdown(int x) {
    apply(ls, t[x].t1, t[x].t2, t[x].t3, t[x].t4);
    apply(rs, t[x].t1, t[x].t2, t[x].t3, t[x].t4);
    t[x].t1 = t[x].t3 = 0; 
    t[x].t2 = t[x].t4 = -1;
}

void pushup(int x) {
    t[x].sum = t[ls].sum + t[rs].sum;
    t[x].m1 = max({t[ls].m1, t[rs].m1});
    t[x].m2 = max({t[ls].m2, t[rs].m2});
}

void bulid(int x, int l, int r) {
    t[x].l = l ;t[x].r = r; 
    t[x].t2 = t[x].t4 = -1;         //死因：没有赋初值
    if(l == r) {
        t[x].sum = 1;
        return;
    }
    int mid = l + r >> 1;
    bulid(ls, l, mid);
    bulid(rs, mid + 1, r);
    pushup(x);
}

void modify1(int x, int l, int r, int v ,int type) {    //赋值
    if(t[x].r < l || t[x].l > r || t[x].sum == 0) return ;
    if(l <= t[x].l && t[x].r <= r) {
        if(type == 0) apply(x, 0, v, 0, -1);
        else apply(x, 0, -1, 0, v);
        return ;
    }
    int mid = l + r >> 1;
    pushdown(x);
    modify1(ls, l, r, v, type);
    modify1(rs, l, r, v, type);
    pushup(x);
}

void modify2(int x, int l, int r, int v, int type) {    //增加
    if(t[x].r < l || t[x].l > r || t[x].sum == 0) return ; 
    if(l <= t[x].l && t[x].r <= r) {
        if(type == 0) apply(x, v, -1, 0, -1);
        else apply(x, 0, -1, v, -1);
        return ;
    } 
    int mid = l + r >> 1;
    pushdown(x);
    modify2(ls, l, r, v, type);
    modify2(rs, l, r, v, type);
    pushup(x);
}

void modify3(int x, int l, int r, int v) {  
    if(t[x].r < l || t[x].l > r || max(t[x].m1, t[x].m2) < v || t[x].sum == 0) return ;
    if(t[x].l == t[x].r) {                          //死因，判断的是此区间，不是询问区间
        if(max(t[x].m1, t[x].m2) >= v && t[x].sum) {
            t[x].sum = 0;
            apply(x, 0, 0, 0, 0);
            // t[x].t2 = t[x].t4 = -1;
        }
        return ;
    }
    int mid = l+ r >> 1;
    pushdown(x);
    modify3(ls, l, r, v);
    modify3(rs, l, r, v);
    pushup(x);
}

#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    bulid(1, 1, n);
    while(q--) {
        int op, x, y, z;
        cin >> op;
        if(op == 1) {
            cin >> x >> y >> z;
            modify1(1, x, y, 0, 1);
            modify1(1, 1, x - 1, 0, 0);
            modify1(1, y + 1, n, 0, 0);
            modify2(1, x, y, z, 0);
            modify2(1, 1, x - 1, z, 1);
            modify2(1, y + 1, n, z, 1);
        }
        if(op == 2) {
            cin >> x >> y >> z;
            modify3(1, x, y, z);
        }
        if(op == 3) {
            cout << t[1].sum << '\n';
        }
    }  
    return 0;
}