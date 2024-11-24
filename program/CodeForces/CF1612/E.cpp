#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> m(n + 1), k(n + 1), bk(n + 1);
    unordered_map<int, int> to;
    set<int> s;
    rep(i ,1, n) cin >> m[i] >> k[i], s.insert(m[i]);
    for(auto a : s) to[a] = ++to[0], bk[to[0]] = a;
    rep(i, 1, n) m[i] = to[m[i]];
    vector<int> ans; double cnt = 0;
    vector<pair<int, int>> tmp(n + 1);
    rep(t, 1, min(n, 20))  {
        vector<int> res;
        for(int i = 1; i <= n; i++) 
            tmp[i].second = i, tmp[i].first = 0;
        rep(i, 1, n) tmp[m[i]].first += min(t, k[i]);
        sort(tmp.begin() + 1, tmp.end(), greater<>());
        int sum = 0;
        rep(i, 1, t) sum += tmp[i].first, res.emplace_back(tmp[i].second);
        if(cnt < 1.0 * sum / t) cnt = 1.0 * sum / t, ans = res;  
    }
    cout << ans.size() << '\n';
    for(auto a : ans) cout << bk[a] << " ";
    return 0;
}
