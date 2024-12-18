#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 3>;

struct DSU {
    vector<int> fa;
    DSU() {}
    DSU(int n) {init(n); }
    void init(int n) {
        fa.resize(n + 1); 
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;    
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

const string OP = "UDLR";
constexpr int fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, -1, 1};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    auto get = [&](int x, int y) {return (x - 1) * n + y; };
    auto check = [&](int x, int y) {return x < 1 || y < 1 || x > n || y > n; };
    vector<VI> tim(n + 1, VI(n + 1, q + 1)), dis(n + 1, VI(n + 1, 0)), vis = dis;
    vector<int> A(n * n + 5, q + 1);

    const int ok = n * n + 1;
    DSU dsu(ok + 1);
    for(int x, y, i = 1; i <= q; i++) {
        cin >> x >> y;
        char c; cin >> c;
        int t = OP.find(c);

        int nx = x + fx[t], ny = y + fy[t];
        if(check(nx, ny)) dsu.merge(get(x, y), ok);
        else if(!dsu.merge(get(x, y), get(nx, ny))) {
            A[dsu.find(get(x, y))] = i;
        }
        tim[x][y] = i;
    }

    {
        priority_queue<array<int, 3>> qe;
        rep(i, 1, n) qe.push({tim[1][i], 1, i}), qe.push({tim[n][i], n, i});
        rep(i, 2, n - 1) qe.push({tim[i][1], i, 1}), qe.push({tim[i][n], i, n});
        while(!qe.empty()) {
            int w = qe.top()[0], x = qe.top()[1], y = qe.top()[2]; qe.pop();
            if(vis[x][y]) continue;
            dis[x][y] = w; vis[x][y] = 1;
            
            rep(i, 0, 3) {
                int nx = x + fx[i], ny = y + fy[i];
                if(check(nx, ny)) continue;
                int nw = min(w, tim[nx][ny]);
                if(nw <= dis[nx][ny]) continue;
                dis[nx][ny] = nw;
                qe.push({dis[nx][ny], nx, ny});
            }
        }
    }

    vector<int> ans(q + 2);
    rep(i, 1, n) rep(j, 1, n) {
        int res;
        if(tim[i][j] != q + 1) {
            int t = dsu.find(get(i, j));   
            if(t == ok) continue;
            int x = (t - 1) / n + 1, y = (t - 1) % n + 1;
            res = dis[x][y];
            if(A[t] != q + 1) res = max(res, A[t]);
            res = max(res, tim[i][j]);
            if(res == 10) {
                res++;
                }
            ans[res]++;
        }
        else ans[dis[i][j]]++;
    }

    rep(i, 1, q) ans[i] += ans[i - 1];
    rep(i, 1, q) cout << ans[i]  << '\n';
    return 0;
}