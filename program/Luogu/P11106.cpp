#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
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
        for(++x; x <= n; x += x & -x) tr[x] = max(tr[x], v);
    }
    T ask(int x) {
        T ret{};
        for(++x; x >= 1; x -= x & -x) ret = max(ret, tr[x]);
        return ret;
    }
    T query(int l, int r) {
        return ask(r) - ask(l);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    BIT<int> t1(n + 1), t2(n + 1);
    vector<int> F(n + 1), G(n + 1), B(n + 1), C(n + 1);
    rep(i, 1, n) {
        F[A[i]] = F[C[i] = t1.ask(A[i])] + 1;
        G[n + 1 - A[i]] = G[B[i] = t2.ask(n + 1 - A[i])] + 1;
        t1.add(A[i], A[i]);
        t2.add(n + 1 - A[i], n + 1 - A[i]);
    }

    int ans = 0;
    t1.init(n + 1), t2.init(n + 1);
    per(i, n, 1) {
        int w = F[A[i]] + G[n + 1 - A[i]] - 1;
        ans = max(ans, w + max(t1.ask(C[i]) + t2.ask(n + 1 - C[i]), t1.ask(n + 1 - B[i]) + t2.ask(B[i])));
        t1.add(A[i], t1.ask(A[i]) + 1);
        t2.add(n + 1 - A[i], t2.ask(n + 1 - A[i]) + 1);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}