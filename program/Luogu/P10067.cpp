#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 1e6 + 3, INF = 1e9;

namespace SGT {
    constexpr int B = 1 << 20;
    int tr[B << 1];
    void init() {fill_n(tr, B << 1, INF); }
    void modify(int it, int v) {
        for(it += B; it; it >>= 1) tr[it] = v, v = min(v, tr[it ^ 1]);
    }
    int pre(int it) {
        int ret = INF;
        for(it += B; it > 1; it >>= 1) if(it & 1)
            ret = min(ret, tr[it - 1]);
        return ret;
    } 
    int suf(int it) {
        int ret = INF;
        for(it += B; it > 1; it >>= 1) if(!(it & 1))
            ret = min(ret, tr[it + 1]);
        return ret;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    SGT::init();
    vector<int> h(n + 1);
    rep(i, 1, n) cin >> h[i], SGT::modify(i, h[i]);
    
    vector<int> tar(n + 1);
    for(int i = 1, mx = 0; i <= n && (mx = max(mx, h[i])); i++) tar[i] = mx;
    for(int i = n, mx = 0; i >= 1 && (mx = max(mx, h[i])); i--) tar[i] = min(tar[i], mx);

    map<int, VI> mp;
    rep(i, 1, n) mp[h[i]].emplace_back(i), mp[tar[i]].emplace_back(-i);

    // rep(i, 1, n) cerr << tar[i] << " \n"[i == n];

    int lst = 0, ans = 0;
    set<int> s;
    for(auto &p : mp) {
        auto now = p.first; auto &A = p.second;
        if(s.size()) {
            int L = *s.begin(), R = *s.rbegin();
            LL cnt = (now - lst), sum = (lst + now - 1) * cnt / 2 % mod;
            (ans += sum * s.size() % mod) %= mod;
            (ans += cnt * (SGT::pre(L) + SGT::suf(R)) % mod) %= mod;
            if(s.size() > 1) {
                (ans += (sum + cnt) * (s.size() * 2 - 3) % mod) %= mod;
                (ans += cnt * min(SGT::suf(L), SGT::pre(R)) % mod) %= mod;
            }
        }
        for(auto a : A) {
            if(a > 0) s.insert(a), SGT::modify(a, INF);
            else s.erase(-a);
        }
        lst = now;
    }
    cout << ans << '\n';
    return 0;
}
/*
应该是先操作小的再操作大的，因为小的不会对大的有贡献。
如果有多个一样的，可以减少花费。
*/