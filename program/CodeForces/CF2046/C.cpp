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

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> A(n + 1);
    vector<int> tmp;
    rep(i, 1, n) {
        cin >> A[i].first >> A[i].second;
        tmp.emplace_back(A[i].first); tmp.emplace_back(A[i].second);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    auto get = [&](int &x) {x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin() + 1; };
    int m = tmp.size();

    BIT<int> tr1(m + 1), tr2(m + 1);  // 分别处理 <= 和 >

    rep(i, 1, n) get(A[i].first), get(A[i].second);
    vector<VI> nd(m + 1);
    rep(i, 1, n) nd[A[i].first].emplace_back(A[i].second), tr2.add(A[i].second, 1);

    int ans = -1, cnt = n;
    int ansx, ansy;

    auto find = [&](BIT<int> &x, int v) {
        int l = 1, r = m, res = m + 1;
        while(l <= r) {
            int mid = l + r >> 1;
            int t = x.ask(mid - 1);
            if(t >= v) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        int tmp = res;
        l = 1; r = m; res = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            int t = x.query(mid - 1, m);
            if(t >= v) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        return make_tuple(tmp, res);
    };

    auto check = [&](int x) {
        int L = 0, R = m, l, r;
        tie(l, r) = find(tr1, x); L = max(L, l); R = min(R, r);
        tie(l, r) = find(tr2, x); L = max(L, l); R = min(R, r);
        return (L <= R ? L : 0);
    };

    rep(i, 1, m) if(nd[i].size()){
        int l = 0, r = n / 4, res = 0, ii;
        while(l <= r) {
            int mid = l + r >> 1;
            int t = check(mid);
            if(check(mid)) l = mid + 1, res = mid, ii = t;
            else r = mid - 1;
        } 

        if(res > ans) {
            ans = res;
            ansx = i;  ansy = ii;
        }

        for(auto j : nd[i]) {
            tr2.add(j, -1);
            tr1.add(j, 1);
        }
    }
    cout << ans << '\n';
    ansx = tmp[ansx - 1]; ansy = tmp[ansy - 1];
    cout << ansx << " " << ansy << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
