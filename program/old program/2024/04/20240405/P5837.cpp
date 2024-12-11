// P5837 [USACO19DEC] Milk Pumping G
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;
const int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<array<int, 3>>> G(n + 1);
    for(int i = 1, a, b, c, d; i <= m; i++)
        cin >> a >> b >> c >> d, G[a].push_back({b, c, d}), 
        G[b].push_back({a, c, d}); 
    vector<VI> D(n + 1, VI(1005, INF)); 
    using AI = array<int, 3> ;
    priority_queue<AI, vector<AI>, greater<AI>> q;
    q.push({0, 1, 1001});
    D[1][1001] = 0;
    double ans = 0;
    while(!q.empty()) {
        auto x = q.top();
         q.pop();
        if(x[1] == n) 
            ans = max(ans, (double)x[2] / D[x[1]][x[2]] );
        else {
            for(auto i : G[x[1]]) {
                int nw = min(x[2], i[2]), nd = D[x[1]][x[2]] + i[1];
                if(nd < D[i[0]][nw]) {
                    D[i[0]][nw] = nd;
                    q.push({nd, i[0], nw});
                }
            }
        }
    }
    cout << (int)(ans * 1e6) << '\n';
    return 0;
}