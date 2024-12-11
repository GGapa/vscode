#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    using AI = array<int, 2>;
    vector<vector<AI>> ch(n), num(n);
    for(int i = 1, l, r, x; i <= m; i++) {
        cin >> l >> r >> x;
        ch[l].push_back({x, 1}); 
        if(r + 1 < n) ch[r + 1].push_back({x, -1});
        num[x].push_back({l, r});
    }

    multiset<int> s;
    vector<int> mn(n);
    rep(i, 0, n - 1) {
        for(auto a : ch[i]) {
            if(a[1] == 1) s.insert(a[0]);
            else s.erase(s.find(a[0]));
        }
        mn[i] = (s.empty() ? 0 : *s.rbegin());
    }
    s.clear();

    vector<int> fa(n + 1), ans(n, -1);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](int x) {
        while(fa[x] != x) x = fa[x] = fa[fa[x]];
        return x;
    };
    auto merge = [&](int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        return fa[x] = y, true;
    };
    auto fil = [&](int t) {
        auto ps = s.lower_bound(mn[t]);
        if(ps == s.end()) return false;
        ans[t] = *ps; s.erase(ps);
        return true;
    };

    per(i, n - 1, 0) {
        if(num[i].empty()) {s.insert(i); continue;}
        int l = 0, r = n - 1;
        for(auto t : num[i]) {
            l = max(t[0], l), r = min(t[1], r);
            if(l > r) goto ed;
        } 
        vector<int> pos;
        for(int t = find(l); t <= r; t = find(t)) pos.emplace_back(t), merge(t, t + 1);
        if(pos.empty()) goto ed;
        int it = -1;
        for(auto t : pos) if(it == -1 || mn[t] < mn[it]) it = t;
        if(mn[it] > i) goto ed;
        ans[it] = i;
        for(auto t : pos) if(t != it && !fil(t)) goto ed;
    }
    rep(i, 0, n - 1) if(ans[i] == -1 && !fil(i)) goto ed;

    for(auto a : ans) cout << a << " ";
    return 0;

    /////////////////////////////////////////////////////////// 判无解
    ed: 
    rep(i, 1, n) cout << -1 << " \n"[i == n];
    exit(0);
    return 0;
}