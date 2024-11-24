#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244853, N = 250e3;

namespace Math {
    namespace pre {
        template <typename T>
        constexpr T qpow(T x, int y){
            T ret = 1;
            for(; y; y >>= 1) {
                if(y & 1) (ret = ret * x) %= mod;
                (x = x * x) %= mod;
            }
            return ret;
        }

        template <typename T>
        constexpr T inv(T x) {return qpow(x, mod - 2); }
    }  	
    using namespace pre;

    constexpr LL add(const LL x, const LL y) {return (x + y + mod) % mod; }
    constexpr LL mul(const LL x, const LL y) {return (x * y % mod + mod) % mod; }

    LL fac[N], iv[N];

    void init() {
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = mul(fac[i - 1], i);
        iv[N - 1] = inv(fac[N - 1]); 
        per(i, N - 2, 0) iv[i] = mul(iv[i + 1], i + 1) ;
    }

    LL C(int y, int x) {
        if(x < 0 || y < 0 || y - x < 0) return 0;
        return mul(fac[y], mul(iv[x], iv[y - x])) ;
    }   
}
using Math::C; 
using namespace Math::pre;

struct Mat {
    int n; 
    LL A[2][2];

    LL* operator [](int i)  {return A[i];} 
    const LL* operator [](int i) const { return A[i]; } //在矩阵乘法中放入这两个函数之后，便可以直接通过 `ans[1][5]` 访问数组元素，而不是 `ans.a[1][5]`。

    Mat(int _n = 1) : n(_n) {A[0][0] = A[0][1] = A[1][0] = A[1][1] = 0;}
    const Mat operator*(const Mat &B) const {
        Mat C(n);
        rep(i, 0, n) rep(j, 0, n) 
            rep(k, 0, n) (C[i][j] += (A[i][k] * B[k][j]) % mod) %= mod;
        return C;
    }
    bool check() {
        return A[0][0] == A[1][1] && A[0][1] == A[1][0] && A[0][0] == 1 && A[0][1] == 0;
    }
};

int A[N];
Mat mt[3][2];

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    int n;

    struct Node {
        vector<Mat> mat;
        int tag = 0;
    }tr[N << 2];

    Node operator+(const Node &x, const Node &y) {
        Node ret; ret.mat.assign(3, Mat(1));
        rep(i, 0, 2) ret.mat[i] = x.mat[i] * y.mat[i];
        return ret;
    }

    void apply(int x, int v) {
        rotate(tr[x].mat.begin(), tr[x].mat.begin() + v, tr[x].mat.end());
        tr[x].tag += v;
    }

    void pushdown(int x) {
        tr[x].tag %= 3;
        if(tr[x].tag == 0) return ;
        apply(ls, tr[x].tag);
        apply(rs, tr[x].tag);
        tr[x].tag = 0;
    }

    void build(int x = 1, int l = 1, int r = n) {
        if(l == r) {
            tr[x].tag = 0;
            tr[x].mat.assign(3, Mat(1));
            rep(i, 0, 2) tr[x].mat[i] = mt[(i + A[l]) % 3][!(l & 1)];
            return ;
        }
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }

    void init(int nn) {n = nn; build(); }

    void modify(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return apply(x, 1);
        int mid = l + r >> 1;
        pushdown(x);
        if(L <= mid) modify(L, R, ls, l, mid);
        if(mid < R) modify(L, R, rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }

    Node query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x];
        int mid = l + r >> 1;
        pushdown(x);
        if(L <= mid && mid < R) return query(L, R, ls, l, mid) + query(L, R, rs, mid + 1, r);
        if(L <= mid) return query(L, R, ls, l, mid);
        if(mid < R) return query(L, R, rs, mid + 1, r);
        assert(0);
        return Node();
    }
}
#undef ls
#undef rs

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> rg(0, mod - 1);

Mat getinv(const Mat &x) {
    LL a = x[0][0], b = x[1][0], c = x[1][1];
    Mat ret(1);
    ret[0][0] = inv(a);
    ret[1][0] = mod - (b * inv(a * c % mod) % mod); ret[1][1] = inv(c);
    return ret;
}

void gmat() {
    rep(i, 0, 2) {
        auto &t = mt[i][0];
        t[0][0] = rg(rnd); 
        t[1][0] = rg(rnd); t[1][1] = rg(rnd);
        mt[i][1] = getinv(t);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    gmat();
    int n, q; cin >> n >> q;
    rep(i, 1, n) cin >> A[i];
    SGT::init(n);
    for(int op, l, r; q--; ) {
        cin >> op >> l >> r;
        if(op == 1) SGT::modify(l, r);
        else cout << (SGT::query(l, r).mat[0].check() ? "Yes" : "No") << '\n';
    }
    return 0;
}