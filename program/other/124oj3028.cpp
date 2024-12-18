#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for (int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e5 + 5, mod = 1e9 + 7;
constexpr LL INF = 1e18;

struct Mat
{
    int n;
    LL A[6][6];
    LL *operator[](int i) { return A[i]; }
    const LL *operator[](int i) const { return A[i]; } // 在矩阵乘法中放入这两个函数之后，便可以直接通过 `ans[1][5]` 访问数组元素，而不是 `ans.a[1][5]`。
    Mat() : n(5) { rep(i, 0, n) rep(j, 0, n) A[i][j] = 0; }
    const Mat operator*(const Mat &B) const
    {
        Mat C;
        rep(i, 0, n) rep(j, 0, n)
            rep(k, 0, n)(C[i][j] += A[i][k] * B[k][j] % mod) %= mod;
        return C;
    }
};

Mat val[N];
int w[N];
vector<int> L[N];

#define ls (x << 1)
#define rs ((x << 1) | 1)
namespace SGT
{
    int n;
    Mat tr[N << 2];
    void pushup(int x) { tr[x] = tr[ls] * tr[rs]; }
    void build(int x = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            rep(i, 0, (int)L[l].size() - 1) val[l][i][0] = L[l][i];
            val[l][5][0] = w[l];
            val[l][5][5] = 1;
            rep(i, 1, 4) val[l][i - 1][i] = 1;
            tr[x] = val[l];
            return;
        }
        int mid = l + r >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(x);
    }
    void init(int nn) { n = nn, build(); }
    Mat query(int L, int R, int x = 1, int l = 1, int r = n)
    {
        if (L <= l && r <= R)
            return tr[x];
        int mid = l + r >> 1;
        if (L <= mid && mid < R)
            return query(L, R, ls, l, mid) * query(L, R, rs, mid + 1, r);
        if (L <= mid)
            return query(L, R, ls, l, mid);
        if (mid < R)
            return query(L, R, rs, mid + 1, r);
        assert(false);
        return {};
    }
    void modify(int it, int x = 1, int l = 1, int r = n)
    {
        if (l == r)
            return tr[x] = val[it], void();
        int mid = l + r >> 1;
        if (it <= mid)
            modify(it, ls, l, mid);
        else
            modify(it, rs, mid + 1, r);
        pushup(x);
    }
}
#undef ls
#undef rs

int n;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> w[i];
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        L[i].resize(x);
        rep(j, 0, x - 1) cin >> L[i][j];
    }
    SGT::init(n);

    int q;
    cin >> q;
    for (int it, v, l; q--;)
    {
        cin >> it >> v >> l;
        memset(val[it].A, 0, sizeof(val[it].A));
        rep(i, 0, l - 1) cin >> val[it][i][0];

        val[it][5][0] = v;
        val[it][5][5] = 1;
        rep(i, 1, 4) val[it][i - 1][i] = 1;
        val[it][5][0] = v;

        SGT::modify(it);
        Mat tmp, tt = SGT::query(1, n);
        tmp[0][5] = 1;
        tmp = tmp * tt;
        cout << tmp[0][0] << '\n';
    }
    return 0;
}
