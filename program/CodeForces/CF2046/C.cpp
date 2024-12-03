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
    // rep(i, 1, n) cerr << A[i].first << " " << A[i].second << '\n';

    int ans = -1, cnt = n;
    int ansx, ansy;

    auto work = [&](int y) {
        int res = n + 1;
        int t = tr1.ask(y - 1);
        res = min({res, t, (n - cnt) - t});

        t = tr2.ask(y - 1);
        res = min({res, t, cnt - t});
        return res;
    };

    vector<int> tt2;
    rep(i, 1, n) tt2.emplace_back(A[i].second);
    sort(tt2.begin(), tt2.end());
    tt2.erase(unique(tt2.begin(), tt2.end()), tt2.end());
    LL s2 = accumulate(tt2.begin(), tt2.end(), 0ll), s1 = 0;
    int mm = accumulate(tt2.begin(), tt2.end(), 0ll) / n;
    mm = lower_bound(tt2.begin(), tt2.end(), mm) - tt2.begin();

    rep(i, 1, m) {
        // int l = 0, r = (int)tt2.size() - 1;
        // while(r - l >= 3) {
        //     int mid1 = l + (r - l + 1) / 3, mid2 = l + (r - l + 1) / 3 * 2;
        //     int t1 = work(tt2[mid1]), t2 = work(tt2[mid2]);
        //     if(t1 >= t2) r = mid2;
        //     else l = mid1;
        // }
        // rep(j, l, r) {
        //     int t = work(tt2[j]);
        //     if(t > ans) ansx = tmp[i - 1], ansy = tmp[tt2[j] - 1], ans = t;
        // }
        int l = lower_bound(tt2.begin(), tt2.end(), s1 / max(1, (n - cnt))) - tt2.begin(), r = lower_bound(tt2.begin(), tt2.end(), s2 / max(1, cnt)) - tt2.begin();
        rep(j, max(0, l - 10), min((int)tt2.size() - 1, l + 10)) {
            int t = work(tt2[j]);
            if(t > ans) ansx = tmp[i - 1], ansy = tmp[tt2[j] - 1], ans = t;
        }
        rep(j, max(0, r - 10), min((int)tt2.size() - 1, r + 10)) {
            int t = work(tt2[j]);
            if(t > ans) ansx = tmp[i - 1], ansy = tmp[tt2[j] - 1], ans = t;
        }

        rep(j, max(0, mm - 50), min((int)tt2.size() - 1, mm + 50)) {
            int t = work(tt2[j]);
            if(t > ans) ansx = tmp[i - 1], ansy = tmp[tt2[j] - 1], ans = t;
        }

        for(auto j : nd[i]) {
            tr2.add(j, -1);
            tr1.add(j, 1);
            cnt--;
        }
    }
    cout << ans << '\n';
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
/*
1
4
1000000000 1000000000
0 0
-1000000000 -1000000000
0 1000000000
*/