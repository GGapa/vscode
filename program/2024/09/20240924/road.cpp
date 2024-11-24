#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using ULL = unsigned long long;
const int N = 1e5 +  5;


int pw[N];

#define ls (x << 1)
#define rs ((x << 1) | 1)
struct SGT {
    vector<ULL> t1, t2; // 从左往右 || 从右往左
    int n;
    SGT(int _n) : n(_n), t1((_n << 2) + 1), t2((_n << 2) + 1) {}
    void modify(int it, int v, int l = 1, int r = -1, int x = 1) {
        if(r == -1) r = n;
        if(l == r) return t1[x] = t2[x] = v,void();
        int mid = l + r >> 1;
        if(it <= mid) modify(it, v, l, mid, ls);
        else modify(it, v, mid + 1, r, rs);
        t1[x] = t1[ls] * pw[r - mid] + t1[rs];
        t2[x] = t2[ls] + t2[rs] * pw[mid - l + 1];
    }
    ULL quel(int L, int R, int l = 1, int r = -1, int x = 1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) return t1[x];
        int mid = l + r >> 1;
        if(L <= mid && mid < R) return quel(L, R, l, mid, ls) * pw[min(r, R) - mid] + quel(L, R, mid + 1, r, rs);
        if(L <= mid) return quel(L, R, l, mid, ls);
        if(mid < R) return quel(L, R, mid + 1, r, rs);
        return 0;
    }
    ULL quer(int L, int R, int l = 1, int r = -1, int x = 1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) return t2[x];
        int mid = l + r >> 1;
        if(L <= mid && mid < R) return quer(L, R, l, mid, ls) + quer(L, R, mid + 1, r, rs) * pw[mid - max(L, l) + 1];
        if(L <= mid) return quer(L, R, l, mid, ls);
        if(mid < R) return quer(L, R, mid + 1, r, rs);
        if(L <= mid && mid < R) return quer(L, R, l, mid, ls) * pw[min(R, r) - mid] + quer(L, R, mid + 1, r, rs);
        return 0;
    }
};
#undef ls
#undef rs

void init() {
    pw[0] = 1;
    rep(i, 1, N - 1) pw[i] = pw[i - 1] * 233; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int n, m; cin >> n >> m;
    vector<int> x(m), y(m), le(m), w(m), id(m), fa(n + 1);
    rep(i, 0, m - 1) cin >> x[i] >> y[i] >> le[i] >> w[i]; 
    iota(id.begin(), id.end(), 0), iota(fa.begin(), fa.end(), 0);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        return w[x] < w[y];
    });
    SGT tr(n);
    rep(i, 1, n) tr.modify(i, i);
    auto find = [&](int x) {
        while(x != fa[x]) {
            tr.modify(x, fa[fa[x]]);
            x = fa[x] = fa[fa[x]];
        }
        return x;
    };
    auto merge = [&](int x, int y) {
        cout << x << " " << y << endl;
        x = find(x), y = find(y);
        assert(x != y);
        fa[x] =  y;
        tr.modify(x, y);
    };
    LL ans = 0;
    for(auto i : id) {
        int ix = x[i], iy = y[i];
        while(ix <= x[i] + le[i] - 1) {
            int l = 0, r = x[i] + le[i] - ix, itt = 0;
            while(l <= r) {
                int mid = l + r >> 1;
                if(tr.quel(ix, ix + mid) == tr.quer(iy, iy + mid)) l = mid + 1;
                else r = mid - 1, itt = mid;
            }
            if(ix + itt >= x[i] + le[i]) break;
            merge(ix + itt, iy + itt);
            ans += w[i];
            ix += itt + 1, iy += itt + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}