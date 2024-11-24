// 10:22
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<LL>;

#define ls (x << 1)
#define rs ((x << 1) | 1)
namespace SGT {
    const LL INF = 1e18;
    const int N = 2e5 + 5;
    int A[N];

    int n;
    LL tr[N << 2][2][2];
    void pushup(int x) {
        rep(i, 0, 1) rep(j, 0, 1) tr[x][i][j] = INF;
        rep(i, 0, 1) rep(j, 0, 1) rep(a, 0, 1) rep(b, 0, 1) if(a || b){
            tr[x][i][j] = min({tr[ls][i][a] + tr[rs][b][j], tr[x][i][j]});
            // cerr << i << " " << x << " "  << tr[ls][i][x] + tr[rs][y][j] << '\n';
        }
    }
    void init(int nn) {n = nn; }
    void modify(int it, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x][1][1] = A[l], tr[x][1][0] = tr[x][0][1] = INF, void();  
        int mid = l + r >> 1;
        if(it <= mid) modify(it, ls, l, mid);
        else modify(it, rs, mid + 1 ,r);
        pushup(x);
    }
}
#undef ls
#undef rs
using SGT::A;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; n--;
    SGT::init(n);
    rep(i, 1, n) cin >> A[i], SGT::modify(i);
    int q; cin >> q;
    for(int i = 1, it, v; i <= q; i++) {
        cin >> it >> v;
        A[it] = v;
        SGT::modify(it);
        cout << SGT::tr[1][1][1]  * 2<< '\n';
    }
    return 0;
}