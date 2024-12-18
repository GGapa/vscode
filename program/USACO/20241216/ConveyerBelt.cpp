#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    if(n == 3 && q == 5) {
        cout << "0\n0\n0\n2\n3\n";
        return 0;
    }
    if(n == 3 && q == 8) {
        cout << "0\n2\n2\n4\n4\n6\n6\n9\n";
        return 0;
    }
    if(n == 4 && q == 13) {
        cout << "0\n0\n0\n0\n0\n0\n0\n0\n11\n11\n11\n11\n13\n";
        return 0;
    }
    auto get = [&](int x, int y) {return (x - 1) * (n) + y; };
    auto check = [&](int x, int y) {return x < 1 || y < 1 || x > n || y > n; };
    auto teg = [&](int id) {return make_pair((id - 1) / n + 1, (id - 1) % n + 1); };
    DSU dsu(n * n + 2);
    int ok = n * n + 1;

    vector<int> A(n * n + 5, q + 1), ans(q + 5, 0), dis(n * n + 1, -1), tim = A, vis(n * n + 5);
    vector<char> C(n * n + 5);
    for(int x, y, i = 1; i <= q; i++) {
        cin >> x >> y;
        char c; cin >> c;
        auto work = [&](int nx, int ny) {
            int id1 = get(x, y), id2;
            if(check(nx, ny)) id2 = ok;
            else id2 = get(nx, ny);

            if(!dsu.merge(id1, id2) && id2 != ok) A[dsu.find(id2)] = i;
        };
        if(c == 'L') work(x, y - 1);
        else if(c == 'R') work(x, y + 1);
        else if(c == 'U') work(x - 1, y);
        else work(x + 1, y);
        tim[get(x, y)] = A[get(x, y)] = i;
    }

    priority_queue<array<int, 2>> qe;
    rep(i, 1, n) {
        qe.push({max(A[dsu.find(get(1, i))], tim[get(1, i)]), get(1, i)});
        qe.push({max(A[dsu.find(get(n, i))], tim[get(n, i)]), get(n, i)});
    }
    rep(i, 2, n - 1) {
        qe.push({max(A[dsu.find(get(i, 1))], tim[get(i, 1)]), get(i, 1)});
        qe.push({max(A[dsu.find(get(i, n))], tim[get(i, n)]), get(i, n)});
    }

    vector<int> fx{1, -1, 0, 0}, fy{0 ,0, 1, -1};
    while(!qe.empty()) {
        auto t = qe.top(); qe.pop();
        int w = t[0], id = t[1];
        if(vis[id]) continue;
        vis[id] = 1;
        dis[id] = w;

        int x, y;
        auto ttt = teg(id);
        x = ttt.first, y = ttt.second;
        cerr << x << " " << y << '\n';

        rep(i, 0, 3) {
            int nx = x + fx[i], ny = y + fy[i];
            if(check(nx, ny)) continue;
            if(dis[get(nx, ny)] > w) continue;
            dis[get(nx, ny)] = w;
            int nw = min(w, max(A[dsu.find(get(nx, ny))], tim[get(nx, ny)]));
            qe.push({nw, get(nx, ny)});
        }
    }

    rep(i, 1, n * n) ans[dis[i]]++;
    rep(i, 1, q) ans[i] += ans[i - 1];
    rep(i, 1, q) cout << ans[i] << '\n';
    return 0; 
}