#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using PII = pair<int, int>;
using AI = array<int, 4>;

constexpr int N = 1e5 + 5, mod = 1e9 + 7;

int h, w;

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    int n;
    priority_queue<PII, vector<PII>, greater<PII>> q[N << 2];
    int tr[N << 2];
    void build(int x = 1, int l = 1, int r = n) {
        if(l == r) {
            q[x].emplace(h + 1, 1);
            tr[x] = h + 1;
            return ;
        }
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        tr[x] = min(tr[ls], tr[rs]);
    }
    void init(int nn) {n = nn; build(); }
    int query(int L, int R, int lim, int x = 1, int l = 1, int r = n) {
        if(tr[x] > lim || l > R || r < L) return 0;
        int ret = 0, mid = l + r >> 1;
        if(l == r) {
            while(!q[x].empty() && q[x].top().first <= lim) (ret += q[x].top().second) %= mod, q[x].pop();
            tr[x] = (q[x].empty() ? INT_MAX : q[x].top().first);
            return ret;
        }
        (ret += query(L, R, lim, ls, l, mid)) %= mod;
        (ret += query(L, R, lim, rs, mid + 1, r)) %= mod;
        tr[x] = min(tr[ls], tr[rs]);
        return ret;
    }
    void modify(int it, pair<int, int> v, int x = 1, int l = 1, int r = n) {
        if(l == r) {
            q[x].emplace(v);
            tr[x] = q[x].top().first;
            return ;
        }
        int mid = l + r >> 1;
        if(it <= mid) modify(it, v, ls, l, mid);
        else modify(it, v, rs, mid + 1, r);
        tr[x] = min(tr[ls], tr[rs]);
    } 
}
#undef ls
#undef rs

int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> h >> w >> n;
    SGT::init(w);
    vector<AI> A(n + 1);
    rep(i, 1, n) for(auto &a : A[i]) cin >> a;
    sort(A.begin() + 1, A.end(), greater<>());
    rep(i, 1, n) {
        auto &a = A[i];
        int sum = SGT::query(a[1], a[2], a[0] + a[3]);
        if(a[1] == 1) SGT::modify(a[2] + 1, {a[0], sum * 2 % mod});
        else if(a[2] == w) SGT::modify(a[1] - 1, {a[0], sum * 2 % mod});
        else SGT::modify(a[1] - 1, {a[0], sum}), SGT::modify(a[2] + 1, {a[0], sum});
    }
    int ans = SGT::query(1, w, h + 1);
    cout << ans << '\n';
    return 0;
}