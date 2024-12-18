#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct Node {
    int x, y, ty;
};

signed main() {
    freopen("class.in", "r", stdin);
    freopen("class.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n;
    vector<Node> nd, aa;
    map<int, int> mp;
    for(int i = 1, x, y; i <= n; i++) 
        cin >> x >> y, mp[x] = mp[y] = 0, nd.push_back({x, y, 0}), aa.push_back({x, y, 0});
    cin >> m;
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, mp[x] = mp[y] = 0, nd.push_back({x, y, 1});
    vector<int> v(2);
    cin >> v[0] >> v[1];
    v[1] *= -1;
    int idx = 0;
    for(auto &p : mp) p.second = ++idx;
    for(auto &a : nd) a.x = mp[a.x], a.y = mp[a.y];
    for(auto &a : aa) a.x = mp[a.x], a.y = mp[a.y];
    sort(nd.begin(), nd.end(), [&](const Node &x, const Node &y) {
        return (x.x == y.x ? x.y < y.y : x.x < y.x);
    });
    sort(aa.begin(), aa.end(), [&](const Node &x, const Node &y) {
        return (x.x == y.x ? x.y < y.y : x.x < y.x);
    });
    vector<VI> S(idx + 1, VI(idx + 1));
    for(auto a : nd) S[a.x][a.y] += v[a.ty];
    rep(i, 1, idx) rep(j, 1, idx) {
        S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
    }
    int ans = 0;
    rep(a, 1, idx) rep(b, 1, idx) rep(x, a + 1, idx) rep(y, b + 1, idx) 
            ans = max(ans, S[x][y] - S[a - 1][y] - S[x][b - 1] + S[a - 1][b - 1]);
    cout << ans << '\n';
    return 0;
}
