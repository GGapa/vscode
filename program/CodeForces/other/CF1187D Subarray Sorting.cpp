#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

#define ls (x << 1)
#define rs ((x << 1) + 1)
 

struct SegTree {
    int n; 
    struct Node {
        LL mx, tag;
    };
    vector<Node> T;
    SegTree(int _n) : n(_n), T((n << 2) + 1) {}
    void apply(int x, int v) {
        T[x].mx = v;
        T[x].tag = v;
    }
    void pushdown(int x) {
        if(!T[x].tag) return ;
        apply(ls, T[x].tag);
        apply(rs, T[x].tag);
        T[x].tag = 0;
    }
    void update(int L, int R, LL v, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) {
            T[x].mx = v;
            T[x].tag = v;
            return ;
        }
        int mid = l + r >> 1;
        pushdown(x);
        if(L <= mid) update(L, R, v, ls, l, mid);
        if(R > mid) update(L, R, v, rs, mid + 1, r);
        T[x].mx = max(T[ls].mx, T[rs].mx);
    }
    LL query(int L, int R, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) 
            return T[x].mx;
        LL res = -1e18;
        int mid = l + r >> 1;   
        pushdown(x);
        if(L <= mid) res = max(res, query(L, R, ls, l, mid));
        if(R > mid) res = max(res, query(L, R, rs, mid + 1, r));
        return res;
    }
};
#undef ls
#undef rs

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1), nxt(n + 1), pos(n + 1, n + 1), dec(n + 1);
    vector<int> ca(n + 1), cb(n + 1) ;
    rep(i, 1, n) cin >> A[i], ca[A[i]]++; 
    rep(i, 1, n) cin >> B[i], cb[B[i]]++;
    per(i, n, 1) pos[B[i]] = i, nxt[i] = pos[A[i]];     // 最近的一个在哪里。
    int cnt = 0;
    SegTree tr(n);
    rep(i ,1, n) {
        cnt -= dec[i];
        int j = i + cnt;
        if(A[i] == A[j]) continue;
        int mx = tr.query(i + 1, nxt[i] + cnt);
        if(mx > A[i]) goto fail;
        cnt++; dec[nxt[i]];
    }
    fail: return cout << "NO\n", void();
}
/*
题意等价于若相邻元素 a > b 则 swap(a, b)
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}