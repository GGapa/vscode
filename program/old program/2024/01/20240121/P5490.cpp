#include <iostream>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
#define int long long

int n;
int x1, x2, y1, y2, X[N << 2];

struct Sline {
	int l, r, h;
	int mark;
}line[N << 2];

struct tr {
	int l, r, sum;
	ll len;
}t[N << 2];

#define ls (x << 1)
#define rs (x << 1 | 1)

void bulid(int x, int l, int r) {
	t[x].l = l, t[x].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	bulid(ls, l, mid);
	bulid(rs, mid + 1, r);
}

void pushup(int x) {
	int l = t[x].l, r = t[x].r;
	if(t[x].sum) 
		t[x].len = X[r + 1] - X[l];
	else
		t[x].len = t[ls].len + t[rs].len;
}

void modify(int x, int l, int r, int c) {
	int L = t[x].l, R = t[x].r;
	if(X[R + 1] <= l || r <= X[L]) return;
	if(l <= X[L] && X[R + 1] <= r) {
		t[x].sum += c;
		pushup(x);
		return ;
	}
	modify(ls, l, r, c);
	modify(rs, l, r, c);
	pushup(x);
}

#undef ls
#undef rs
signed main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("A.in", "r", stdin);
	cin >> n;
	rep(i, 1, n) {
		cin >> x1 >> y1 >> x2 >> y2;
		X[i * 2 - 1] = x1; X[2 * i] = x2;
		line[2 * i - 1]  = {x1, x2, y1, 1};
		line[2 * i] = {x1, x2, y2, -1};
	}
	n <<= 1;
	sort(line + 1, line + 1 + n, [](const Sline& xx, const Sline& yy) {
		return xx.h < yy.h;
	});
	sort(X + 1, X + 1 + n);
	int tot = unique(X + 1, X + n + 1) - X - 1;
	bulid(1, 1, tot - 1);
	ll ans = 0;
	rep(i, 1, n - 1) {
		modify(1, line[i].l, line[i].r, line[i].mark);
		ans += t[1].len * (line[i + 1].h - line[i].h);
	}
	cout << ans << '\n';
	return 0;
}

