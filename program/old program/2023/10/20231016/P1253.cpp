
#include <limits.h>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;

int n, q;
int a[maxn];

struct Tree {
	ll tag1, tag2; 	//分别是改变值和加法
	ll mx; 
	int l, r;
    bool utg;
}t[maxn * 2];

int ls(int it) {
	return it * 2;
}
int rs(int it) {
	return it * 2 + 1;
}
void pushup(int it) {
    t[it].mx = max(t[ls(it)].mx, t[rs(it)].mx);
}

void bulid(int it, int l, int r) {
	t[it].l = l; t[it].r = r;
	t[it].mx = LLONG_MIN;
	if(l == r) {
		t[it].mx = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	bulid(ls(it), l, mid);
    bulid(rs(it), mid + 1, r);
    pushup(it);
}

void pushdown(int it) {
    if(t[it].utg) {
        t[ls(it)].tag1 = t[it].tag1;
        t[rs(it)].tag1 = t[it].tag1;
        t[ls(it)].tag2 = t[it].tag2;
        t[rs(it)].tag2 = t[it].tag2;
        t[ls(it)].mx = t[it].tag1 + t[it].tag2;      
        t[rs(it)].mx = t[it].tag1 + t[it].tag2;
        t[ls(it)].utg = 1;
        t[rs(it)].utg = 1;
    }
    else {
        t[ls(it)].tag2 += t[it].tag2;
        t[rs(it)].tag2 += t[it].tag2;
        t[ls(it)].mx += t[it].tag2;
        t[rs(it)].mx += t[it].tag2;
    }
    t[it].utg = t[it].tag1 = t[it].tag2 = 0;
}

void change(int it, int l, int r, ll val) {
    if(l <= t[it].l && t[it].r <= r) {
        t[it].utg = 1;
        t[it].tag1 = val;
        t[it].tag2 = 0;
        t[it].mx = val;
        return ;
    }
    pushdown(it);
    int mid = (t[it].l + t[it].r) >> 1;
    if(l <= mid) change(ls(it), l, r, val);
    if(mid + 1 <= r) change(rs(it), l, r, val);
    pushup(it);
}

void add(int it, int l, int r, ll val) {
    if(l <= t[it].l && t[it].r <= r) {
        t[it].tag2 += val;
        t[it].mx += val;
        return;
    }
    pushdown(it);
    int mid = (t[it].l + t[it].r) >> 1;
    if(l <= mid) add(ls(it), l, r, val);
    if(mid + 1 <= r) add(rs(it), l, r, val);
    pushup(it);
}

ll getmx(int it, int l, int r) {
    if(l <= t[it].l && t[it].r <= r) {
        return t[it].mx;
    }
    ll tmp = LLONG_MIN;
    pushdown(it);
    int mid = (t[it].l + t[it].r) >> 1;
    if(l <= mid) tmp = max(tmp, getmx(ls(it), l, r));
    if(mid + 1 <= r) tmp = max(tmp, getmx(rs(it), l, r));
    return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
    bulid(1, 1, n);
    while(q--) {
        int op;
        int l, r;
        ll v;
        cin >> op;
        if(op == 1) {
            
            cin >> l >> r >> v;
            change(1, l, r, v);
        }
        if(op == 2) {
            int l, r, v;
            cin >> l >> r >> v;
            add(1, l, r, v);
        }
        if(op == 3) {
            int l, r;
            cin >> l >> r;
            cout << getmx(1, l, r) << "\n";
        }
    }
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
2.85KB
用时
2.17s
内存
80.70MB
GGapa

所属题目
P1253 扶苏的问题
评测状态
Accepted
评测分数
100
提交时间
2023-10-16 22:23:04
*/