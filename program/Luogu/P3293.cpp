#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct SegTree {
	struct Node {
		int l, r, cnt = 0; 
	};
	int tot = 0, n;
    vector<Node> T;
	SegTree(int _n) : n(_n), T(n * 100) { }
    int modify(int it, int ls, int l = 1, int r = -1) {
        if(r == -1) r = n;
        int x = ++tot, mid = l + r >> 1;
        T[x] = T[ls]; T[x].cnt++;
        if(l == r) return x;
        if(it <= mid) T[x].l = modify(it, T[ls].l, l, mid);
		else T[x].r = modify(it, T[ls].r, mid + 1, r);
        return x;
    }
	int query(int x, int y, int L, int R, int l = 1, int r = -1) {
		if(r == -1) r = n;
		if(L <= l && r <= R) return T[y].cnt - T[x].cnt;
		int mid = l + r >> 1, ret = 0;
		if(L <= mid) ret += query(T[x].l, T[y].l, L, R, l, mid);
		if(mid < R) ret += query(T[x].r, T[y].r, L, R, mid + 1, r);
		return ret;
	}
    bool ask(int x, int y, int i, int j) {
        i = max(0, i), j = min(j, n) ;
        if(i > j) return false;
        int tmp = query(x, y, i, j);
        return tmp;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >>  m;
    vector<int> A(n + 1), rt(n + 1);
    rep(i, 1, n) cin >> A[i];
    int mx = *max_element(A.begin(), A.end()) ;
    SegTree tr(mx + 10) ;
    rep(i, 1, n) rt[i] = tr.modify(A[i], rt[i - 1]);
    for(int testcase = 1, b, x, l, r; testcase <= m; testcase++) {
        cin >> b >> x >> l >> r;    
        int ans = 0;
        per(i, 17, 0) {
            int t = ((b >> i) & 1) ^ 1;
            t = ans | (t << i) ;
            // cout << t - x << " " << (t + (1 << i) - 1 - x) << '\n';
            if(tr.ask(rt[l - 1], rt[r], t - x, t + (1 << i) - 1 - x)) 
                ans = t;
            else ans |= ((b >> i) & 1) << i;
        }
        cout << (ans ^ b) << '\n';
    }
    return 0;
}
/*
0000001000
9
0000000101
7
0000000101
6
0000000011
7
*/