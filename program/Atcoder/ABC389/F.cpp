#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct fenwick {
    int n;
    struct BIT {
        int n;
        vector<int> T;
        BIT(int _n) : n(_n) ,T(_n + 5) {    };
        int lowbit(int x) {return x & -x;}
        void modify(int x, int v) {
            for(x; x <= n; x += lowbit(x)) T[x] += v;
        }
        LL query(int x) {
            LL res = 0;
            for(; x > 0; x -= lowbit(x)) res += T[x];
            return res;
        }
    };
    BIT T1, T2;
    fenwick(int _n) : n(_n), T1(n), T2(n) { }
    void modif(int x, int v) { T1.modify(x, (x - 1) * v); T2.modify(x, v); }
    LL quer(int y) { return T2.query(y) * y - T1.query(y); }
    void modify(int l, int r, int v) { modif(l ,v); modif(r + 1, -v); }
    LL query(int l, int r) { return quer(r) - quer(l - 1); }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> L(n + 1), R(n + 1);
    rep(i, 1, n) cin >> L[i] >> R[i];
    
    int q; cin >> q;
    vector<array<int, 2>> A(q + 1);
    rep(i, 1, q) cin >> A[i][0], A[i][1] = i;
    sort(A.begin() + 1, A.end());
    fenwick tr(q + 10);
    rep(i, 1, q) tr.modify(i, i, A[i][0]);

    rep(i, 1, n) {
        int l = 1, r = q;
        int ll = q + 1, rr = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            if(tr.query(mid, mid) >= L[i]) ll = mid, r = mid - 1;
            else l = mid + 1;
        }
    
        l = 1, r = q;
        while(l <= r) {
            int mid = l + r >> 1;
            if(tr.query(mid, mid) <= R[i]) rr = mid, l = mid + 1;
            else r = mid - 1;
        }

        if(ll > rr) continue;
        tr.modify(ll, rr, 1);
    }

    vector<int> ans(q + 1);
    rep(i, 1, q)  ans[A[i][1]] = tr.query(i, i) ;
    rep(i, 1, q)  cout << ans[i] << '\n';
    return 0;
}