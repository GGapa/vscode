#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 5e5 + 5;
constexpr LL INF = 1e18;

vector<int> num(1);

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    struct Node {
        LL F[4], val, tag;
        LL get() {return *min_element(F, F + 4); }
        LL& operator[](const int x) {return F[x]; }
    }tr[N << 2];
    int n;

    void pushup(int x) {
        rep(i, 0, 3) tr[x][i] = INF;
        rep(i, 0, 3) rep(j, 0, 3) {
            int s = i & 2 | j & 1;
            int tg = i & (j >> 1) & 1;
            tr[x][s] = min(tr[x][s], tr[ls][i] + tr[rs][j] - tg * tr[x].val);
        }
    }
    void apply(int x, LL v) {
        tr[x].val += v, tr[x].tag += v;
        rep(i, 0, 3) tr[x][i] += v;
        tr[x][0] = min(tr[x][0], 0ll); 
    }
    void pushdown(int x) {
        if(tr[x].tag == 0) return ;
        apply(ls, tr[x].tag); 
        apply(rs, tr[x].tag);
        tr[x].tag = 0;
    }

    void build(int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x][1] = tr[x][2] = INF, void();
        int mid = l + r >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(x);
    }
    void init(int nn) {n = nn; if(n) build(); }

    void update(int it, LL v, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x][3] += v, void();
        pushdown(x);
        int mid = l + r >> 1;
        if(it <= mid) update(it, v, ls, l, mid);
        else update(it, v, rs, mid + 1, r);
        pushup(x);
    }
    void modfiy(int L, int R, LL v, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return apply(x, v);
        pushdown(x);
        int mid = l + r >> 1, cnt = 0;
        if(L <= mid) modfiy(L, R, v, ls, l, mid), cnt++;
        if(mid < R) modfiy(L, R, v, rs, mid + 1, r), cnt++;
        if(cnt == 2) tr[x].val += v;
        pushup(x);
    }
    LL query() {return tr[1].get(); }
}
#undef ls
#undef rs


int n, l; 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> l;
    vector<int> op(n + 1), X(n + 1), A(n + 1);
    rep(i, 1, n) {
        cin >> op[i] >> X[i] >> A[i];
        if(op[i] == 1) num.emplace_back(X[i]);
    } 

    sort(num.begin() + 1, num.end());
    num.erase(unique(num.begin() + 1, num.end()), num.end());
    int m = (int)num.size() - 1;
    SGT::init(m);

    LL sum = 0;
    rep(i, 1, n) {
        if(op[i] == 1) {
            auto it = lower_bound(num.begin() + 1, num.end(), X[i]) - num.begin();
            sum += A[i];
            SGT::update(it, -A[i]);
        }
        else {
            int L = lower_bound(num.begin() + 1, num.end(), X[i] - l) - num.begin();
            int R = upper_bound(num.begin() + 1, num.end(), X[i] + l) - num.begin() - 1;
            if(L <= R) SGT::modfiy(L, R, A[i]);
        } 
        cout << sum + SGT::query() << '\n';
    }

    return 0;
} 
