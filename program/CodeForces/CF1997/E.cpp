#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct SegTree {
	int n, idx = 0;
	struct Node {
		int ls, rs, sum;
	};
	vector<Node> T;
	SegTree (int _n) : n(_n), T((_n * 100) + 5) {	}
	int modify(int it, int ls, int l = 1, int r = -1) {
		if(r == -1) r = n;
		int nw = ++idx, mid = l + r >> 1;
		T[nw] = T[ls]; T[nw].sum++;
		if(l < r) {
			if(it <= mid) T[nw].ls = modify(it, T[ls].ls, l, mid);
			else T[nw].rs = modify(it, T[ls].rs, mid + 1, r);
		}	
		return nw;
	} 
	int query(int L, int R, int k, int l = 1, int r = -1) {
		if(r == -1) r = n;
		if(l >= r) return l;
		int mid = l + r >> 1;
		int su = T[T[R].ls].sum - T[T[L].ls].sum;
		if(su >= k) return query(T[L].ls, T[R].ls, k, l, mid);
		else return query(T[L].rs, T[R].rs, k - su, mid + 1, r);
	}
}; 
 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    SegTree T(n);
    vector<int> A(n + 1), rt(n + 1);
    rep(i ,1, n) cin >> A[i];
    rep(i, 1, n) rt[i] = T.modify(A[i], rt[i - 1]);
    vector<array<int, 3>> ask;
    rep(i ,1, q) cin >> ask[i][1] >> ask[i][0], ask[i][2] = i;
    sort(ask.begin() + 1, ask.end());   
    for(int j = 1; j <= q; ) {
        int x = ask[j][0];
        for(int i = 1; i <= n; ) {
            int dn = x, up = n - i + 1;
            while(dn <= up) {
                int mid = dn + up >> 1;
                int ct = mid - T.query(i, i + mid - 1);
                
            }
        } 
    }
    return 0;
}
/*
注意到等级的函数是往上升且逐渐平缓的


*/