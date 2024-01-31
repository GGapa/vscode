#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;
const int maxn = 1e5 + 5;

int n, q, op, k;
int a[maxn];

struct Node {
	int f0 = maxn, l0 = 0, f1 = maxn, l1 = 0;
	int l, r;
	int tf0 = maxn, tl0 = 0, tf1 = maxn, tl1 = 0;
	int cnt = 0;
}t[maxn * 4];


void bulid(int x, int l, int r) {
	t[x].l = l; t[x].r = r;
	if(l == r)  {
		if(a[l]) t[x].l1 = t[x].f1 = l;
		else t[x].l0 = t[x].f0 = l;
		return ;
	}
	int mid = (l + r) >> 1;
	bulid(x << 1, l, mid);
	bulid(x << 1 | 1, mid + 1, r);
	t[x].f0 = min(t[x << 1].f0, t[x << 1 | 1].f0); t[x].f1 = min(t[x << 1].f1, t[x << 1 | 1].f1);
	t[x].l0 = max(t[x << 1].l0, t[x << 1 | 1].l0); t[x].l1 = max(t[x << 1].l1, t[x << 1 | 1].l1);
}

void update(int x) {
	if(t[x].cnt % 2 != 0) {
	swap(t[x << 1].f0, t[x << 1].f1);
	swap(t[x<< 1].l0, t[x << 1].l1);
	swap(t[x << 1 | 1].f0, t[x << 1 | 1].f1);
	swap(t[x<< 1 | 1].l0, t[x << 1 | 1].l1);
}
	t[x << 1].cnt += t[x].cnt;
	t[x << 1 | 1].cnt += t[x].cnt;
	t[x].cnt = 0;
}

void change(int x, int l, int r) {
	if(l <= t[x].l && t[x].r <= r) {
		swap(t[x].f0, t[x].f1);
		swap(t[x].l0, t[x].l1);
		t[x].cnt++;
		return ;
	}
	update(x);
	int mid = (t[x].l + t[x].r) >> 1;
	if(l <= mid) change(x << 1, l ,r);
	if(r > mid) change(x << 1 | 1, l, r);
	t[x].f0 = min(t[x << 1].f0, t[x << 1 | 1].f0); t[x].f1 = min(t[x << 1].f1, t[x << 1 | 1].f1);
	t[x].l0 = max(t[x << 1].l0, t[x << 1 | 1].l0); t[x].l1 = max(t[x << 1].l1, t[x << 1 | 1].l1);
}

int qurey1(int x, int l, int r) { 
	if(!t[x].l1) return maxn;
	if(t[x].l == t[x].r) return t[x].l;
	if(l <= t[x].l && t[x].r <= r) return t[x].f1; 
	update(x);
	int tmp = maxn;
	int mid = (t[x].l + t[x].r) >> 1;
	if(l <= mid) tmp = qurey1(x << 1, l ,r);
	if(r > mid) tmp = min(tmp, qurey1(x << 1 | 1, l, r));
	t[x].f0 = min(t[x << 1].f0, t[x << 1 | 1].f0); t[x].f1 = min(t[x << 1].f1, t[x << 1 | 1].f1);
	t[x].l0 = max(t[x << 1].l0, t[x << 1 | 1].l0); t[x].l1 = max(t[x << 1].l1, t[x << 1 | 1].l1);
	return tmp;
}

int qurey2(int x, int l, int r) { 
	if(!t[x].l1) return 0;
	if(t[x].l == t[x].r) return t[x].l;
	if(l <= t[x].l && t[x].r <= r) return t[x].l1; 
	update(x);
	int tmp = 0;
	int mid = (t[x].l + t[x].r) >> 1;
	if(l <= mid) tmp = qurey2(x << 1, l ,r);
	if(r > mid) tmp = max(tmp, qurey2(x << 1 | 1, l, r));
	t[x].f0 = min(t[x << 1].f0, t[x << 1 | 1].f0); t[x].f1 = min(t[x << 1].f1, t[x << 1 | 1].f1);
	t[x].l0 = max(t[x << 1].l0, t[x << 1 | 1].l0); t[x].l1 = max(t[x << 1].l1, t[x << 1 | 1].l1);
	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> n >> q;
	rep(i, 1, n) cin >> a[i];
	bulid(1, 1, n);
	while(q--) {
		cin >> op;
		int sum = 0;
		if(op == 1) {
			int l, r;
			cin >> l >> r;
			change(1, l, r);
		}
		if(op == 2) {
			int l, r;
			cin >> k;
			rep(i, 1, k) {
				cin >> l >> r;
				int q1 = qurey1(1, l, r);
				int q2 = qurey2(1, l, r);
				if(!q2) continue;
				sum ^= r - l + 1 - 2 * min(q1 - l, r - q2);
			}
			cout << (sum ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}
