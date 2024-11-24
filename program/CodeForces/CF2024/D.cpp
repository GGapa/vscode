#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;


void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i ,1, n) cin >> B[i];

    vector<vector<pair<int, int>>> G(n + 1);
    rep(i, 1, n) G[i].emplace_back(i - 1, 0);
    rep(i, 1, n) G[i].emplace_back(B[i], A[i]);

    const LL INF = 1e18;
    vector<LL> dis(n + 1, INF);
    using AI = array<LL, 2>;
    priority_queue<AI, vector<AI>, greater<AI>> q;
    dis[1] = 0; q.push({0, 1});
    while(!q.empty()) {
        int x = q.top()[1], w = q.top()[0]; q.pop();
        if(dis[x] < w) continue;
        for(auto i : G[x]) {
            int to = i.first, w = i.second;
            if(dis[to] > dis[x] + w) {
                dis[to] = dis[x] + w;
                q.push({dis[to], to});
            }
        }   
    }

    LL ans = 0, sum = 0;
    rep(i, 1, n) {
        sum += A[i];
        ans = max(ans, sum - dis[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}