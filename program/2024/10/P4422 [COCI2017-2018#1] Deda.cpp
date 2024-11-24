// 10:05
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 2e5 + 6;

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    int n;
    int tr[N << 2];
    void build(int x = 1, int l = 1, int r = n) {
        tr[x] = INT_MAX;
        if(l == r) return ;
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
    }
    void init(int nn) {n = nn; build(); }
    void modify(int it, int v, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x] = v, void();
        int mid = l + r >> 1;
        if(it <= mid) modify(it, v, ls, l, mid);
        else modify(it, v, rs, mid + 1, r);
        tr[x] = min(tr[ls], tr[rs]);
    }
    int query(int L, int R, int v, int x = 1, int l = 1, int r = n) {
        if(r < L || l > R || tr[x] > v) return -1;
        if(l == r) return l;
        int ret = -1;
        int mid = l + r >> 1;
        ret = query(L, R, v, ls, l, mid);
        if(ret == -1) ret = query(L, R, v, rs, mid + 1, r);
        return ret;
    }
}
#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    SGT::init(n);
    while(q--) {
        char op; cin >> op;
        int x, y; cin >> x >> y;
        if(op == 'M') SGT::modify(y, x);
        else cout << SGT::query(y, n, x) << '\n'; 
    }
    return 0;
 }
 /*
3 3
M 10 3
M 5 1
D 5 1
 */