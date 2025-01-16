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
    vector<int> A(n + 1), B(n + 1), S(n + 1);
    rep(i, 1, n) cin >> A[i], A[i] += i;
    rep(i, 1, n) cin >> B[i], B[i] += i;

    if(accumulate(A.begin(), A.end(), 0ll) != accumulate(B.begin(), B.end(), 0ll)) return cout << -1 << '\n', 0;
     
    int cnt = 0;
    map<int, int> tmp;
    rep(i, 1, n) tmp[B[i]] = 0;
    for(auto &p : tmp) p.second = ++cnt;
    rep(i, 1, n) {
        B[i] = tmp[B[i]];
        if(B[i] == 0) return cout << -1 << '\n', 0;
    }
    rep(i, 1, n) {
        A[i] = tmp[A[i]];
        if(A[i] == 0) return cout << -1 << '\n', 0;
    }

    vector<VI> pos(cnt + 1);
    per(i, n, 1) pos[A[i]].emplace_back(i);

    BIT<int> tr(n + 1);
    LL ans = 0;
    rep(i, 1, n) {
        if(pos[B[i]].empty()) return cout << -1 << '\n', 0;
        int ps = pos[B[i]].back(); pos[B[i]].pop_back();    
        int np = ps + tr.query(ps, n); 
        ans += abs(np - i);
        // cerr << ans << '\n';    
        tr.add(ps, 1);
    }
    cout << ans << '\n';
    return 0;
}