// 20:28
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n + 1), x(n + 1);
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n) cin >> x[i];
    
    auto rng = [&](int i, int cnt) {
        assert(cnt != 0);
        int dmg = (h[i] + cnt - 1) / cnt, dis = m - dmg;
        return make_pair(x[i] - dis, x[i] + dis);
    };
    
    multiset<int> L, R;
    auto ins = [&](int i, int cnt) {
        auto p = rng(i, cnt);
        L.insert(p.first), R.insert(p.second);
    };
    auto del = [&](int i, int cnt) {
        auto p = rng(i, cnt);
        L.erase(L.find(p.first)), R.erase(R.find(p.second));
    };
    auto check = [&](int cnt) {
        L.clear(); R.clear();
        rep(i, 1, k - 1) ins(i, cnt);
        for(int i = 1, j; i <= n - k + 1; i++) {
            j = i + k - 1;
            ins(j, cnt);
            if(x[j] - x[i] + 1 > 2 * m - 1) break;
            if(*L.rbegin() <= *R.begin()) return true;
            del(i, cnt);
        }
        return false;
    };

    int l = 1, r = 1e9 + 1, res = -1;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid - 1, res = mid;
        else l = mid + 1;
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}