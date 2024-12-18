// Friendly Spiders
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 3e5 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m = 0; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i], m = max(m, A[i]);
    int s, t; cin >> s >> t;
    vector<int> p, mn(m + 1);
    rep(i, 2, m) {
        if(!mn[i]) {
            mn[i] = i;
            p.emplace_back(i);
        }
        for(auto j : p) {
            if(i * j > m) break;
            mn[i * j] = j;
            if(j == mn[i]) break;
        }
    }
    vector<VI> G(m + 1);
    rep(i, 1, n) {
        for(int x = A[i]; x > 1; x /= mn[x]) {
            G[mn[x]].emplace_back(i);
        }
    }
    vector<int> dis(n + m + 2, -1), pre(n + m + 2, 0);
    queue<tuple<int, int, int>> q;
    q.push({s, 0, 0});
    while(!q.empty()) {
        int i, d, pr;
        tie(i, d, pr) = q.front(); q.pop();
        if(dis[i] != -1) continue;
        dis[i] = d;
        pre[i] = pr;
        if(i <= n) for(int x = A[i]; x > 1; x /= mn[x]) q.push({n + mn[x] + 1, d + 1, i});
        else for(auto x : G[i - n - 1]) q.push({x, d + 1, i});
    }
    if(dis[t] == -1) return cout << -1 << '\n', 0;
    vector<int> ans;
    for(t; t; t = pre[t]) if(t <= n)ans.emplace_back(t);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a << " ";
    return 0; 
}