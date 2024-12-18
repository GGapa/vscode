#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct Node {
    int x, y, ty;
};

const int N = 4e3 + 5;

struct BIT {
    int T[N][N];
    int n;
    int lowbit(int x) {return x & -x;}
    void add(int x, int y, int v) {
        for(int i = x; i <= n; i += lowbit(i)) for(int j = y; j <= n; j += lowbit(j))
            T[i][j] = min(T[i][j], v);
    };
    int ask(int x, int y) {
        int ret = 0;
        for(int i = x; i; i -= lowbit(i)) for(int j = y; j; j -= lowbit(j))
            ret = min(ret, T[i][j]);
        return ret;
    }
}T;



signed main() {
    // freopen("class.in", "r", stdin);
    // freopen("class.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n;
    vector<Node> nd;
    map<int, int> mp;
    for(int i = 1, x, y; i <= n; i++) 
        cin >> x >> y, mp[x] = mp[y] = 0, nd.push_back({x, y, 0});
    cin >> m;
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, mp[x] = mp[y] = 0, nd.push_back({x, y, 1});
    vector<int> v(2);
    cin >> v[0] >> v[1];
    v[1] *= -1;
    int idx = 0;
    for(auto &p : mp) p.second = ++idx;
    for(auto &a : nd) a.x = mp[a.x], a.y = mp[a.y];
    sort(nd.begin(), nd.end(), [&](const Node &x, const Node &y) {
        return (x.x == y.x ? x.y < y.y : x.x < y.x);
    });
    vector<VI> S(idx + 1, VI(idx + 1));
    for(auto a : nd) S[a.x][a.y] += v[a.ty];
    T.n = idx;
    rep(i, 1, idx) rep(j, 1, idx) {
        S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        T.add(i, j, S[i][j]);
        cout << S[i][j] << " \n"[j == idx];
    }
    int ans = 0;
    int t = nd.size();
    // rep(i, 0, t - 1) rep(j, i + 1, t - 1) 
    //     ans = max(ans, S[nd[j].x][nd[j].y] - S[nd[i].x - 1][nd[j].y] - S[nd[j].x][nd[i].y - 1] + S[nd[i].x - 1][nd[i].y - 1]);
    rep(i, 1, idx) rep(j, 1, idx) {
        ans = max(ans, S[i][j] - T.ask(i, j));
    }
    cout << ans << '\n';
    return 0;
}