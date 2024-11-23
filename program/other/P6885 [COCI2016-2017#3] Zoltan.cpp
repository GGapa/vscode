#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int mod = 1e9 + 7;

struct Node {
    int val; LL cnt = 0;
    Node(int a = 0, int b = 0) {
        val = a, cnt = b;
    }

    Node operator+(const Node &x) {
        Node ret; 
        ret.val = val; ret.cnt = cnt;
        if(x.val > val) ret.val = x.val, ret.cnt = x.cnt;
        else if(x.val == val) (ret.cnt += x.cnt) %= mod;
        return ret;
    }
};

template <typename T>
struct BIT {
    int n;
    vector<T> tr;
    void init(int nn) {
        n = nn;
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

    auto work = [&](const vector<int>& A) {
        vector<int> ct(n + 2), F(n + 2);
        ct[0] = 1; 
        BIT<Node> tr(n + 1);
        tr.add(0, Node(0, 1));

        per(i, n, 1) {
            Node t;
            F[i] = (t = tr.ask(A[i] - 1)).val + 1;
            ct[i] = t.cnt;
            tr.add(A[i], Node(F[i], ct[i]));
        }

        return make_tuple(F, ct);
    };

    vector<int> A(n + 2), tmp;
    rep(i, 1 ,n) cin >> A[i], tmp.emplace_back(A[i]);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    rep(i, 1, n) A[i] = lower_bound(tmp.begin(), tmp.end(), A[i]) - tmp.begin() + 1;

    vector<int> pf, pc, sf, sc;
    tie(sf, sc) = work(A);
    rep(i, 1, n) A[i] = (int)tmp.size() - A[i] + 1;
    tie(pf, pc) = work(A);

    vector<LL> pw(n + 1);
    pw[0] = 1;
    rep(i, 1, n) pw[i] = pw[i - 1] * 2 % mod;
    int mx = 0; LL cnt = 0;
    rep(i, 1, n) {
        int len = pf[i] + sf[i] - 1;
        LL ctt = 1ll * pc[i] * sc[i] % mod;
        if(len > mx) mx = len, cnt = ctt * pw[n - len] % mod;
        else if(len == mx) (cnt += ctt * pw[n - len] % mod) %= mod;
    }

    cout << mx << " " << cnt << '\n';
    return 0; 
}