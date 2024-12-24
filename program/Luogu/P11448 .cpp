#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; LL k; int m; cin >> n >> k >> m;
    vector<int> A(n + 1), v(m + 1);
    vector<VI> G(n + 1), gg(n + 1);

    rep(i, 1, m) cin >> v[i];
    rep(i, 1 ,n) {
        int x; cin >> x;
        G[i].resize(x);
        for(auto &a : G[i]) cin >> a;
        A[i] = x;
    }

    vector<LL> ans(n + 1, 0), cnt(n + 1, 0), tim(n + 1, 0);
    queue<int> q;
    rep(i, 1, m) q.emplace(v[i]), tim[v[i]] = 1, cnt[v[i]] = 1, gg[v[i]].emplace_back(1);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int nxt = tim[x] + 1;
        if(nxt <= k)
        for(auto to : G[x]) {
            gg[to].emplace_back(nxt);
            if(!tim[to] ) q.emplace(to), tim[to] = nxt;
        }
    }

    rep(i, 1, n) {
        if(tim[i] == 0) {
            cout << "0 ";
            continue;
        }
        (ans[i] += (k - tim[i] + 1) % mod * (A[i]) % mod) %= mod;
        for(auto to : gg[i]) (ans[i] += (k - to + 1) % mod) %= mod;
        cout << ans[i] << " ";
    }
    return 0;
}
/*
3 1 1
1
1 2
1 3 
1 1
*/