#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<pair<int, int>> s;

    int cnt = 0;
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if(x > y && x != -1 && y != -1) return cout << "No" << '\n', 0;
        if(x == -1 && y == -1) {
            cnt++;
            continue;
        }
        if(s.count({x, y})) return cout << "No" << '\n', 0;
        s.insert({x, y});
    }

    auto check = [&](int r, int j) {
        int l = r - (j + 1) * 2 + 1;

        int ret = 0;
        rep(i, l, r - (j + 1)) 
            if(!s.count({-1, i + j + 1}) && !s.count({i, -1}) && !s.count({i, i + j + 1})) ret++;
        return ret;
    };

    vector<int> F(n * 2 + 1, INF);
    F[0] = 0;
    rep(i, 1, 2 * n) rep(j, 0, i) {
        if(i - (j + 1) * 2 < 0) break;
        F[i] = min(F[i], F[i - (j + 1) * 2] + check(i, j));
    }
    cout << (F[2 * n] <= cnt ? "Yes" : "No") << '\n';
    return 0;
}
/*
这样子会有问题，我们的节点可能会被使用很多次
*/