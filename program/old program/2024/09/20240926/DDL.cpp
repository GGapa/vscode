/*
这道题的名字是 DDL 虽然说网上他的意思是  deadline 
但是我坚信他是 dandelion 也就是 蒲公英 的缩写哦
以自己名字为题的题肯定要好好写啦 qwq

好耶o(*￣▽￣*)ブ
就只花了 71 min 就写完了这道题！！！
懒得查错了，我就要直接交，我相信肯定没有问题的啦 awa

哦哦哦哦哦，不小心挂了一发呢，没有关系，好像是为了调试方便把数组开小了呢。
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

LL qpow(LL x, LL y) {
    LL ret = 1;
    for(; y; y >>= 1) {
        if(y & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
    }
    return ret;
}

LL inv(LL x) {return qpow(x, mod - 2); }

LL add(LL x, LL y) {return (x + y + mod) % mod; }
LL mul(LL x, LL y) {return x * y % mod; }

const int iv2 = inv(2);

struct BIT {
    vector<LL> T;
    int n;
    BIT(int _n) : n(_n), T(_n + 5) {}
    int lowbit(int x) {return x & -x; }
    void add(int x, LL v) { for(x++; x <= n; x += lowbit(x)) (T[x] += v) %= mod; }
    LL ask(int x) {
        LL ret = 0;
        for(x++; x; x -= lowbit(x)) (ret += T[x]) %= mod;
        return ret;
    }
};


#define ls (x << 1) 
#define rs ((x << 1) | 1)
namespace SGT {
    const int N = 5e5 + 5;
    struct Node {LL sum, tag = 1; int l, r;} tr[N << 2];
    int type, n;
    void pushup(int x) {
        tr[x].sum = (tr[ls].sum + tr[rs].sum) % mod;
    }
    void build(int x = 1, int l = 1, int r = n) {
        tr[x].l = l, tr[x].r = r; tr[x].tag = 1;
        if(l == r) return tr[x].sum = (type == 0 ? iv2 : 0), void();
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    void init(int nn, int ty) {n = nn; type = ty; build(); }
    void apply(int x, LL v) {
        (tr[x].tag *= v) %= mod;
        (tr[x].sum *= v) %= mod;
    }
    void pushdown(int x) {
        if(tr[x].tag == 1) return ;
        apply(ls, tr[x].tag); apply(rs, tr[x].tag);
        tr[x].tag = 1;
    }
    void Mul(int L, int R, LL v, int x = 1) {
        if(L <= tr[x].l && tr[x].r <= R) return apply(x, v);
        int mid = tr[x].l + tr[x].r >> 1;
        pushdown(x);
        if(L <= mid) Mul(L, R, v, ls);
        if(mid < R) Mul(L, R, v, rs);
        pushup(x);
    }   // 区间乘法
    void modify(int it, LL v, int x = 1) {
        if(tr[x].l == tr[x].r) return tr[x].sum = v, void();
        int mid = tr[x].l + tr[x].r >> 1;
        pushdown(x);
        if(it <= mid) modify(it, v, ls);
        else modify(it, v, rs);
        pushup(x);
    }
    LL query(int L, int R, int x = 1) {
        if(L <= tr[x].l && tr[x].r <= R) return tr[x].sum;
        int mid = tr[x].l + tr[x].r >> 1;
        // cout << x << " " << L << " " << R << endl;
        pushdown(x);
        LL ret = 0;
        if(L <= mid) (ret += query(L, R, ls)) %= mod;
        if(mid < R) (ret += query(L, R, rs)) %= mod;
        return ret;
    } 
};
#undef ls
#undef rs
/*
需要做的事情有，区间乘法，全局和查询，单点修改，单点查询
*/


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), id(n); vector<LL> F(n + 1);
    rep(i, 1, n) cin >> A[i];
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        return A[x] < A[y];
    });
    vector<int> exc(n + 1), rk(n + 1);
    rep(i, 0, n - 1) exc[id[i]] = i + 1;
    BIT few(n + 1);
    per(i, n, 1) {
        few.add(exc[i], 1);
        rk[i] = n - i - few.ask(exc[i])  +1;
    }

    SGT::init(n, 0);
    reverse(id.begin(), id.end());
    for(auto t : id) {
        int i = exc[t];
        F[t] = A[t] * SGT::query(1, t) % mod * qpow(2, rk[t]) % mod;
        few.add(i, -1); SGT::Mul(1, t, iv2);
    }

    SGT::init(n + 1, 1);
    LL ans = 0;
    rep(i, 1, n) {
        SGT::Mul(1, exc[i], iv2);
        SGT::modify(exc[i], F[i]);
        (ans += SGT::tr[1].sum) %= mod;
    }
    cout << ans << '\n';
    return 0;
}