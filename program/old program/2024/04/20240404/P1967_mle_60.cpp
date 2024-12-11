// P1967 [NOIP2013 提高组] 货车运输
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
using AI = array<int, 3>;
typedef long long ll;
const int N = 1e4 + 5, INF = 1e9;
int n, m;
int dis[N][N], vis[N];
vector<AI> G[N];
VI F;

int find(int x) {
    return (x == F[x] ? x : F[x] = find(F[x]));
}

void dfs(int x, int fa, int fal, VI& es) {
    for(auto to : es) 
        dis[x][to] = dis[to][x] = min(dis[fa][to], fal);
    es.push_back(x); vis[x] = 1;
    for(auto i : G[x] ) {
        int to = i[2];
        if(to != fa) dfs(to, x, i[0], es);
    }
}

void init();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m; 
    init();
    vector<AI> A(m + 1);
    rep(i, 1, m) cin >> A[i][1] >> A[i][2] >> A[i][0];
    sort(A.begin() + 1, A.end(), greater<>());
    rep(i, 1 ,m) {
        int x = find(A[i][1]), y = find(A[i][2]);
        if(x == y) continue;
        F[x] = y;
        G[A[i][1]].push_back(A[i]), G[A[i][2]].push_back({A[i][0], A[i][2], A[i][1]});
    }
    VI es;
    rep(i, 1, n) if(!vis[i]) {
        es.clear();
        dfs(i, 0, 0, es);
    }
    int q; cin >> q;
    for(int x, y; q--; ) {
        cin >> x >> y;
        cout << (dis[x][y] == INF ? -1 : dis[x][y]) << '\n';
    }
    return 0;


}

void init() {
    F.resize(n + 1);
    iota(F.begin(), F.end(), 0);
    rep(i, 1, n) rep(j, 1, n) dis[i][j] = INF;
}
// MLE 60