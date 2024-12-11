#include<iostream>
#include<cstdio>
template <typename T> T Min(T x, T y) { return x < y ? x : y; }
template <typename T> T Max(T x, T y) { return x > y ? x : y; }
template <typename T>
T &read(T &r) {
	r = 0; bool w = 0; char ch = getchar();
	while(ch < '0' || ch > '9') w = ch == '-' ? 1 : 0, ch = getchar();
	while(ch >= '0' && ch <= '9') r = r * 10 + (ch ^ 48), ch = getchar();
	return r = w ? -r : r;
}
const int N = 100010;
int n, m, a[N];
#define ls tree[x].lson
#define rs tree[x].rson
#define tl tree[x].l
#define tr tree[x].r
int trnt;
struct SGT {
	int l, r, lson, rson;
	int f0, f1;
	int l0, l1;
	bool tag;
}tree[N << 1];
inline void pushup(int x) {
	tree[x].f0 = Min(tree[ls].f0, tree[rs].f0);
	tree[x].f1 = Min(tree[ls].f1, tree[rs].f1);
	tree[x].l0 = Max(tree[ls].l0, tree[rs].l0);
	tree[x].l1 = Max(tree[ls].l1, tree[rs].l1);
}
inline void pushdown(int x) {
	if(tree[x].tag) {
		tree[x].tag = 0;
		std::swap(tree[ls].f0, tree[ls].f1);
		std::swap(tree[ls].l0, tree[ls].l1);
		std::swap(tree[rs].f0, tree[rs].f1);
		std::swap(tree[rs].l0, tree[rs].l1);
		tree[ls].tag ^= 1, tree[rs].tag ^= 1;
	}
}
int build(int l, int r) {
	int x = ++trnt;
	tl = l; tr = r;
	if(l == r) {
		tree[x].f0 = a[l] ? N : l;
		tree[x].f1 = a[l] ? l : N;
		tree[x].l0 = a[l] ? 0 : l;
		tree[x].l1 = a[l] ? l : 0;
		return x;
	}
	ls = build(l, (l+r)>>1);
	rs = build(((l+r)>>1)+1, r);
	pushup(x);
	return x;
}
void modify(int x, int l, int r) {
	if(tl >= l && tr <= r) {
		std::swap(tree[x].f0, tree[x].f1);
		std::swap(tree[x].l0, tree[x].l1);
		tree[x].tag ^= 1;
		return ;
	}
	pushdown(x);
	int mid = (tl + tr) >> 1;
	if(mid >= l) modify(ls, l, r);
	if(mid < r) modify(rs, l, r);
	pushup(x);
}
int query1(int x, int l, int r) {
	if(!tree[x].l1) return N;
	if(tl == tr) return tl;
	if(tl >= l && tr <= r) return tree[x].f1;
	int mid = (tl + tr) >> 1, ans = N;
	pushdown(x);
	if(mid >= l) ans = query1(ls, l, r);
	if(mid < r) ans = Min(ans, query1(rs, l, r));
	pushup(x);
	return ans;
}
int query2(int x, int l, int r) {
	if(!tree[x].l1) return 0;
	if(tl == tr) return tl;
	if(tl >= l && tr <= r) return tree[x].l1;
	int mid = (tl + tr) >> 1, ans = 0;
	pushdown(x);
	if(mid >= l) ans = query2(ls, l, r);
	if(mid < r) ans = Max(ans, query2(rs, l, r));
	pushup(x);
	return ans;
}
#undef ls
#undef rs
#undef tl
#undef tr
signed main() {
	read(n); read(m);
	for(int i = 1; i <= n; ++i) read(a[i]);
	build(1, n);
	for(int i = 1; i <= m; ++i) {
		int opt, k, x, y, sum = 0;
		read(opt);
		if(opt == 1) {
			read(x); read(y);
			modify(1, x, y);
		}
		else {
			read(k);
			while(k--) {
				read(x), read(y);
				int q1 = query1(1, x, y);
				int q2 = query2(1, x, y);
				if(!q2) continue ;
				sum ^= y - x + 1 - 2 * Min(q1 - x, y - q2);
			}
			printf("%s\n", sum ? "Yes" : "No");
		}
	}
	return 0;
}
