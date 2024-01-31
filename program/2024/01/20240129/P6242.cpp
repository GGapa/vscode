#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i ,a ,b) for(int i = (a); i >= (b); i--)

using namespace std;
const int N = 5e5 + 5;
typedef long long ll;

int n, m;
int a[N];

struct tree{
    ll sum; 
    int l, r, maxa, cnt, se, maxb;
    int add1, add2, add3, add4;
}t[N << 4];

#define ls x << 1
#define rs x << 1 | 1

void pushup(int x) {
    t[x].sum = t[ls].sum + t[rs].sum;
    t[x].maxa = max(t[ls].maxa, t[rs].maxa);
        t[x].maxb = max(t[ls].maxb, t[rs].maxb);
        if(t[ls].maxa == t[rs].maxa) {
        t[x].cnt = t[ls].cnt + t[rs].cnt;
        t[x].se = max(t[ls].se, t[rs].se);
    }
    if(t[ls].maxa > t[rs].maxa)  {
        t[x].cnt = t[ls].cnt;
        t[x].se = max(t[ls].se, t[rs].maxa);
    }
    if(t[ls].maxa < t[rs].maxa) {
        t[x].cnt = t[rs].cnt;
        t[x].se = max(t[ls].maxa, t[rs].se);
    }
}

void apply(int x, int tag1, int tag2, int tag3, int tag4) {
	t[x].sum += 1ll * tag1 * t[x].cnt + 1ll * tag2 * (t[x].r - t[x].l + 1 - t[x].cnt);
	t[x].maxb = max(t[x].maxb, t[x].maxa + tag3);       //在给maxb赋值的时候，将 = 写成 +=，表现：区间历史最大值莫名其妙很大。
	t[x].maxa += tag1;
	if(t[x].se != -2e9) t[x].se += tag2;
	t[x].add3 = max(t[x].add3, t[x].add1 + tag3);
	t[x].add4 = max(t[x].add4, t[x].add2 + tag4);
	t[x].add1 += tag1; t[x].add2 += tag2;
} 
    
void pushdown(int x) {

    int mxn = max(t[ls].maxa, t[rs].maxa);
	if(t[ls].maxa == mxn) 
        apply(ls, t[x].add1, t[x].add2, t[x].add3, t[x].add4);
	else apply(ls, t[x].add2, t[x].add2, t[x].add4, t[x].add4);     //else 的赋值错误，若不是最大值则应该赋非最大值的懒标记，表现：极少情况下（有可能是数据范围太小了）会偶尔冒出来一个错误的求和操作。
	if(t[rs].maxa == mxn) 
        apply(rs, t[x].add1, t[x].add2, t[x].add3, t[x].add4);
	else apply(rs, t[x].add2, t[x].add2, t[x].add4, t[x].add4);     // else 的赋值错误，若不是最大值则应该赋非最大值的懒标记，表现：极少情况下（有可能是数据范围太小了）会偶尔冒出来一个错误的求和操作。
	t[x].add1 = t[x].add2 = t[x].add3 = t[x].add4 = 0; 
}
void bulid(int x, int l, int r) {
    t[x].l = l; t[x].r = r;
    t[x].add1 = t[x].add2 = t[x].add3 = t[x].add4 = 0;
    if(l == r) {
        t[x].maxa =  t[x].maxb = t[x].sum = a[l];
		t[x].se = -2e9; t[x].cnt = 1; 
        return ;
    }
    int mid = (l + r) >> 1;
    bulid(ls, l, mid);
    bulid(rs, mid + 1, r);
    pushup(x);
}

void modify_add(int x, int l, int r, int v) {
    if(t[x].r < l || t[x].l > r) return ;
	if(l <= t[x].l && t[x].r <= r) {
		apply(x, v, v, v, v);
        return ;
	}
    pushdown(x);    
    modify_add(ls, l, r, v); modify_add(rs, l, r, v);
    pushup(x);
}

void modify_min(int x, int l, int r, int v) {
    if(t[x].r < l || t[x].l > r || v >= t[x].maxa) return ;     //退出条件少写了，表现：把最小值改大了。
    if(l <= t[x].l && t[x].r <= r && t[x].se < v) {             //条件少写了，表现：把最小值改大了。
        int tmp = t[x].maxa - v;
        // t[x].sum -= 1ll * t[x].cnt * tmp;
        // t[x].maxa = v; t[x].add1 -= tmp;
        apply(x, -tmp, 0, -tmp, 0);
        // apply(x, v - t[x].maxa, 0, v - t[x].maxa, 0);
        return ;
    }
    pushdown(x);
    modify_min(ls, l, r, v); modify_min(rs, l, r, v);
    pushup(x);
}

ll query_sum(int x, int l, int r) {
    if(t[x].r < l || t[x].l > r) return 0;
    if(l <= t[x].l && t[x].r <= r) 
        return t[x].sum;
    pushdown(x);
    return query_sum(ls, l, r) + query_sum(rs, l, r);
}

int query_maxa(int x, int l, int r) {
    if(t[x].r < l || t[x].l > r) return -2e9;   //不小心 return 0，而不是返回-inf，表现：最大值输出0
    if(l <= t[x].l && t[x].r <= r) 
        return t[x].maxa;
    pushdown(x);
    return max(query_maxa(ls, l, r), query_maxa(rs, l, r));
}


int query_maxb(int x, int l, int r) {
    if(t[x].r < l || t[x].l > r) return -2e9;   //不小心 return 0，而不是返回-inf，表现：最大值输出0
    if(l <= t[x].l && t[x].r <= r) 
        return t[x].maxb;
    pushdown(x);
    return max(query_maxb(ls, l, r),query_maxb(rs, l, r));
}

#undef ls
#undef rs

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    bulid(1, 1, n);
    while(m--) {
        int op, l, r, v;
        cin >> op >> l >> r;
        if(op == 1) {
            cin >> v;
            modify_add(1, l, r, v);
        }
        if(op == 2) {
            cin >> v;
            modify_min(1, l, r, v);
        } 
        if(op == 3) cout << query_sum(1, l, r) << '\n';
        if(op == 4) cout << query_maxa(1, l, r) << '\n';
        if(op == 5) cout << query_maxb(1, l, r) << '\n';
    }

    return 0;
}

// P6242 【模板】线段树 3（区间最值操作、区间历史最值）
