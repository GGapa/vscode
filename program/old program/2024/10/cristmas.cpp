#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
using ULL = unsigned long long;

mt19937_64 rnd(time(0));

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> s(m + 1), t(m + 1), tmp;
    rep(i ,1, m) {
        cin >> s[i] >> t[i], tmp.emplace_back(s[i]), tmp.emplace_back(t[i]);
        if(s[i] > t[i]) swap(s[i], t[i]);
    }
    tmp.emplace_back(0), tmp.emplace_back(n);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    auto get = [&](int &x) {x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin(); };
    rep(i, 1, m) get(s[i]), get(t[i]);
    int nn = tmp.size() - 1;
    vector<int> dis(nn + 1);
    rep(i, 1, nn) dis[i] = tmp[i] - tmp[i - 1];
    vector<ULL> hh(nn + 5);
    rep(i, 1, m)  {
        ULL x = rnd();
        hh[s[i] + 1] ^= x; hh[t[i] + 1]  ^= x;
    }
    rep(i, 1, nn) hh[i] ^= hh[i - 1];
    gp_hash_table<ULL, int> mp;
    rep(i, 1, nn) mp[hh[i]] += dis[i];
    int ans = 0;
    for(auto p : mp) ans = max(ans, p.second);
    cout << ans << '\n';
    return 0;
}
/*
7 4
1 4
5 4
7 4
6 3
*/