// P7492 [传智杯 #3 决赛] 序列
// https://www.luogu.com.cn/problem/P7492
// 2023-11-08 20:14
#include <iostream>
#include <algorithm>
#include <cstdio>
// #define int long long
using namespace std;
const int maxn = 5e5 + 5;

int n, m;

struct Node {
    int maxl, maxr, sumv, maxv;
    int l, r;
}t[maxn * 4];

int ls(int x) {
    return x * 2;
}
int rs(int x) {
    return x * 2 + 1;
}

void pushup(Node &rt,const Node &ls,const Node &rs, bool flag) {
	if(ls.maxr < 0 && rs.maxl < 0)      // 如果小于0要取最大的
	  rt.maxv=max(ls.maxr, rs.maxl);
	else {
	  	rt.maxv = 0;                    // 在这里只需要取得正数,负数是不需要的
	  	if(ls.maxr > 0) rt.maxv += ls.maxr;
	  	if(rs.maxl > 0) rt.maxv += rs.maxl;
	}
	//rt.maxv = max({rt.maxv, ls.maxv, rs.maxv});
	rt.maxl = max(ls.maxl, ls.sumv + rs.maxl);
	rt.maxr = max(rs.maxr, rs.sumv + ls.maxr);
	rt.sumv = ls.sumv + rs.sumv;
}

void make_tree(int x, int l, int r) {
    t[x].l = l; t[x].r = r;
    if(l == r) {
        cin >> t[x].sumv;
        t[x].maxv = t[x].maxl = t[x].maxr = t[x].sumv;
        return ;
    }
    int mid = (r + l) / 2;
    make_tree(ls(x), l, mid);
    make_tree(rs(x), mid + 1, r);
    pushup(t[x], t[ls(x)], t[rs(x)], true);
}

Node query(int x, int l, int r) {
    if(l <= t[x].l && t[x].r <= r) {
        return t[x];
    }
    int mid = (t[x].l + t[x].r >> 1);
    if(l <= mid && mid < r)  {          // 这里 mid < r 写反了警钟敲烂
        Node t;
        pushup(t, query(ls(x), l, r), query(rs(x), l, r), false);
        return t;
    }
    else if(l <= mid) return query(ls(x), l, r);
    else return query(rs(x), l, r);
}

void change(int x, int it, int val) {
    if(t[x].l == t[x].r) {
        t[x].maxl = t[x].maxr = t[x].sumv = t[x].maxv = val;
        return ;
    }
    int mid = (t[x].l + t[x].r) / 2;
    if(it <= mid) change(ls(x), it, val);
    else change(rs(x), it, val);
    pushup(t[x], t[ls(x)], t[rs(x)], true);
}

signed main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n >> m;
    make_tree(1, 1, n);
    while(m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) {
            if(x > y) swap(x, y);
            cout << query(1, x, y).maxv << '\n';
        }
        else {
            change(1, x, y);
        }
    }
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
2.25KB
用时
1.62s
内存
26.46MB
 GGapa

所属题目
P4513 小白逛公园
评测状态
Accepted
评测分数
100
提交时间
2023-11-08 21:54:48
*/