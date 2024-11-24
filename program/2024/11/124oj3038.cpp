// 20:23
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 5>;

constexpr int N = 5e5 + 5;

int A[N];

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    int n;
    int tr[N << 4]; 
    void pushup(int x) {
        tr[x] = max(tr[ls], tr[rs]);
    }
    void build(int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x] = A[l], void();
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    void init(int nn) {n = nn; build(); }
    void modify(int it, int v, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x] = v, void();
        int mid = l + r >> 1;
        if(it <= mid) modify(it, v, ls, l, mid);
        else modify(it, v, rs, mid + 1, r);
        pushup(x);
    }
    int query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x];
        int mid = l + r >> 1, ret = 0;
        if(L <= mid) ret = max(ret, query(L, R, ls, l, mid));
        if(mid < R) ret = max(ret, query(L, R, rs, mid + 1, r));
        return ret;
    }
} // 单点修改，区间最大线段树。
#undef ls
#undef rs

int n, m;
int itv[N][2];      // interval
int fi[2][N][20];   // 往前包含的操作区，左右端点分开处理。
AI que[N];          // id, op, l, r, x || id, op, x, y
int le[N];          // 操作 i 第一个符合条件的区间。


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, m) rep(j, 0, 1) cin >> itv[i][j];

    rep(j, 0, 1) {
        set<array<int, 2>> s;
        per(i, m, 1) {
            vector<array<int, 2>> del;
            auto lit = s.lower_bound({itv[i][0], 0});
            auto rit = s.lower_bound({itv[i][1] + 1, 0});
            for(auto p = lit; p != rit; p++) {
                fi[j][(*p)[1]][0] = i;
                del.emplace_back(*p);
            }
            for(auto p : del) s.erase(p);
            s.insert({itv[i][j], i});
        }
    }

    rep(k, 0, 1) {
        rep(j, 1, 19) rep(i, 1, m) fi[k][i][j] = fi[k][ fi[k][i][j - 1] ][j - 1];
    }   // F[i][j] = F[F[i][j - 1]][j - 1]

    // 以上是处理倍增数组，接下来应当处理询问也就是第一满足 <= R 且包含 x 的区间，同样可以仿照预处理倍增数组的方式来。

    int q; cin >> q;
    for(int i = 1, op, l, r, x; i <= q; i++) {
        cin >> op;
        if(op == 1) {
            cin >> l >> r;
            que[i] = {i, op, l, r, -1};
        }
        else {
            cin >> l >> r >> x;
            que[i] = {i, op, l, r, x};
        }
    }
 
    sort(que + 1, que + 1 + q, [](const AI &x, const AI &y) {
        return x[3] < y[3];
    });

    {
        set<array<int, 2>> s;
        for(int i = m, j = q; i >= 1; i--) {
            while(j >= 1 && (que[j][3] >= i || que[j][1] == 1)) {
                if(que[j][1] != 1) {
                    s.insert({que[j][4], que[j][0]});
                }
                j--;
            }
            vector<array<int, 2>> del;
            auto lit = s.lower_bound({itv[i][0], 0});
            auto rit = s.lower_bound({itv[i][1] + 1, 0});
            for(auto p = lit; p != rit; p++) {
                le[(*p)[1]] = i;
                del.emplace_back(*p);
            }
            for(auto p : del) s.erase(p);
            // s.insert({itv[i][j], i});
        }
    }  

    // 以上是预处理每个询问 <= R 的第一个包含 x 的区间编号，接下来开始处理每一个询问。
    
    sort(que + 1, que + 1 + q); // 之前预处理的时候排过序，现在复位。

    SGT::init(n);
    rep(i, 1, q) {
        if(que[i][1] == 1) {
            SGT::modify(que[i][2], que[i][3]);
        }
        else {
            int x = que[i][4], L = que[i][2], R = que[i][3], nw = le[i];
            if(nw < L) {
                cout << SGT::query(x, x) << '\n';
                continue;
            }
            int l = nw, r = nw;
            per(j, 19, 0) {
                if(fi[0][l][j] >= L) l = fi[0][l][j];
                if(fi[1][r][j] >= L) r = fi[1][r][j];
            }
            l = itv[l][0], r = itv[r][1];
            cout << SGT::query(l ,r) << '\n';
         }
    }

    return 0;
}
/*
需要先预处理出倍增数组 le 和 ri 从 i 往前第一个包含 li 的区间，ri 同理
具体如何操作可以倒着然后用 set 维护，要这样做两次。
需要一颗单点修改，区间最大值线段树。
*/