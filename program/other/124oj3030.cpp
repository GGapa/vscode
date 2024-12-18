#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 1e5 + 5, mod = 100007;


struct Mat {
    int n; 
    LL A[4][4];
    LL* operator [](int i)  {return A[i];} 
    const LL* operator [](int i) const { return A[i]; } //在矩阵乘法中放入这两个函数之后，便可以直接通过 `ans[1][5]` 访问数组元素，而不是 `ans.a[1][5]`。
    Mat() : n(3) { rep(i, 0, n) rep(j, 0, n) A[i][j] = 0; }
    const Mat operator*(const Mat &B) const {
        Mat C; 
        rep(i, 0, n) rep(j, 0, n) 
            rep(k, 0, n) (C[i][j] += A[i][k] * B[k][j] % mod) %= mod;
        return C;
    }
    void debug() {
        rep(i, 0, n) rep(j, 0, n) cerr << A[i][j] << " \n"[j == n];
    }
    void clear() {
        rep(i, 0, n) rep(j, 0, n) A[i][j] = 0;
    }
};

Mat val[N];
string s; 

#define ls (x << 1)
#define rs ((x << 1) | 1)
namespace SGT {
    int n;
    Mat tr[N << 2];
    void pushup(int x) { tr[x] = tr[ls] * tr[rs]; }
    void build(int x =  1, int l = 1, int r = n) {
        if(l == r) return tr[x] = val[l], void();
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    void init(int nn) {n = nn, build(); }
    Mat query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x];
        int mid = l + r >> 1;
        if(L <= mid && mid < R) return query(L, R, ls, l, mid) * query(L, R, rs, mid + 1, r);
        if(L <= mid) return query(L, R, ls, l, mid);
        if(mid < R)return query(L, R, rs, mid + 1, r);
        assert(false);
        return {};
    }
    void modify(int it, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x] = val[it], void();
        int mid = l + r >> 1;
        if(it <= mid) modify(it, ls, l, mid);
        else modify(it, rs, mid + 1, r);
        pushup(x);
    } 
}
#undef ls
#undef rs

void update(char c, int i) {
    auto &v = val[i];
    v.clear();
    if(isdigit(c)) {
        v[0][0] = v[1][1] = v[3][3] = 1;
        v[1][2] = c - '0'; v[2][2] = 10;
    }
    else if(c == '+') {
        v[0][0] = v[3][3] = v[2][0] = v[3][1] = 1;
    }
    else {
        v[0][0] = v[2][1] = v[3][3] = 1;
    }
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s; s += "+";
    int n = s.size();
    s = " " + s ;
    rep(i, 1, n) {
        char c = s[i];
        update(c, i);
    }
    SGT::init(n);
    Mat tmp; tmp[0][1] = tmp[0][3] = 1;
    int q; cin >> q;
    for(int x; q--; ) {
        char y;
        cin >> x >> y;
        s[y] = x;
        update(y, x);
        SGT::modify(x);
        tmp.clear();
        tmp[0][1] = tmp[0][3] = 1;
        cout << (tmp * SGT::query(1, n))[0][0] << '\n';
    }
    return 0;
}