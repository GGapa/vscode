//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 998244353;

int k, a, h; 
int n, m;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k >> a >> h;
    n = 1 << k, m = 1 << k - 1;
    unordered_map<int, vector<int>>  mp[2];
    int tp = (1 << m) - 1;
    auto pop = [&](queue<int>&q, int &x) {
        x = q.front(); q.pop();
    };
    vector<int> pre(35 + 1);
    pre[0] = 1;
    rep(i ,1, 35) (pre[i] = pre[i - 1] * a) %= mod;
    vector<int> ans(m);
    rep(s, 0, tp) {
        queue<int> q;
        int cnt = 0, lim = m >> 1, nw = m;
        rep(i, 0, m - 1) q.push(i);
        rep(i, 1, m - 1) {
            int x, y;  pop(q, x); pop(q, y);
            if((s >> i) & 1) ans[y] = nw + 1, q.push(x);
            else ans[x] = nw + 1, q.push(y);
            if(++cnt == lim) lim >>= 1, cnt = 0, nw >>= 1;
        }
        if(s & 1) ans[q.front()] = 1;
        else ans[q.front()] = 2;
        ll hash = 0;
        // cout << hash << '\n';
        rep(i, 0, m - 1) (hash += (i + 1) * pre[ans[i]]) %= mod;
        if(mp[s&1].count(hash) == 0) mp[s&1][hash] = ans;
    }
    rep(s, 0, tp) {
        queue<int> q;
        int cnt = 0, lim = m >> 1, nw = m;
        rep(i, 0, m - 1) q.push(i);
        rep(i, 1, m - 1) {
            int x, y;  pop(q, x); pop(q, y);
            if((s >> i) & 1) ans[y] = nw + 1, q.push(x);
            else ans[x] = nw + 1, q.push(y);
            if(++cnt == lim) lim >>= 1, cnt = 0, nw >>= 1;
        }
        if(s & 1) ans[q.front()] = 2;
        else ans[q.front()] = 1;
        ll hash = 0;
        rep(i, 0, m - 1) (hash += (i + 1 + m) * pre[ans[i]]) %= mod;
        hash = (h - hash + mod) % mod;
        if(mp[s&1].count(hash)) {
            for(auto a : mp[s&1][hash]) cout << a << " ";
            rep(i, 0, m - 1) cout << ans[i] << " \n"[i == m - 1];
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}