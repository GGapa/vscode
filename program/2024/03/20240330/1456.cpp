// #1456. 多米诺骨牌 http://124.221.194.184/problem/1456
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 50 * 50 + 5;
vector<VI> G;
int n, m, k;
int fx[] = {0, 1, -1, 0, 0}, fy[] = {0, 0, 0, 1, -1};
int vis[N], mc[N];

bool dfs(int x, int tag) {
    if(vis[x] == tag) return false;
    vis[x] = tag;
    for(auto to : G[x]) if(!mc[to] || dfs(mc[to], tag)) {
        mc[to] = x;
        return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int cnt = n * m, idx = 0;
    vector<VI> mp(n + 1, VI(m + 1, 1)), id(n + 1, VI(m + 1));
    for(int i = 1, x, y; i <= k; i++) 
        cin >> x >> y, mp[x][y] = 0;
    rep(i, 1, n) rep(j, 1, m) if(mp[i][j]) id[i][j] = ++idx;
    G.resize(idx + 1);
    rep(i, 1, n) rep(j, 1, m) if(mp[i][j] && (i + j ) % 2) {
        rep(f, 1, 4) {
            int nx = i + fx[f], ny = j + fy[f];
            if(nx < 1 || ny < 1 || nx > n || ny > m || !mp[nx][ny]) continue;
            G[id[i][j]].push_back(id[nx][ny]);
        }
    } 
    int ans= 0;
    rep(i, 1, idx) if(dfs(i, i)) ans++;
    cout << ans << '\n';
    return 0;
}