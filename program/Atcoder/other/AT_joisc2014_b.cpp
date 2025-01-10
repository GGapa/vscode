#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

template <typename T>
struct BIT {
    int n;
    vector<T> tr;
    void init(int nn) {
        n = nn + 1;
        tr.assign(n + 5, T{});
    }
    BIT (int nn = 0) {
        init(nn);
    }
    void add(int x, const T &v) {
        for(++x; x <= n; x += x & -x) tr[x] = (tr[x] + v);
    }
    T ask(int x) {
        T ret{};
        for(++x; x >= 1; x -= x & -x) ret = (ret + tr[x]);
        return ret;
    }
    T query(int l, int r) {
        return ask(r) - ask(l);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), tmp;
    rep(i, 1, n) cin >> A[i];
    tmp = A;
    sort(tmp.begin() + 1, tmp.end());  
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    rep(i, 1, n) A[i] = lower_bound(tmp.begin() + 1, tmp.end(), A[i]) - tmp.begin();
    int m = tmp.size() - 1;
    BIT<int> tr(m + 1);
    vector<int> L(n + 1), R(n + 1);
    rep(i, 1, n) {
        L[i] = tr.query(A[i], m);
        tr.add(A[i], 1);
    }
    tr.init(m + 1);
    per(i, n, 1) {
        R[i] = tr.query(A[i], m);
        tr.add(A[i], 1);
    }
    LL ans = 0;
    rep(i, 1, n) ans += min(L[i], R[i]);
    cout << ans << '\n';
    return 0;
}