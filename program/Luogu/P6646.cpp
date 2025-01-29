#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

template<int siz>
using AI = array<LL, siz>;

constexpr LL INF = 1e18;
constexpr int N = 2e5 + 5;

int n, k, m;

void fail() {while(k--) cout << -1 << '\n'; exit(0); }

struct COL {
    int l, r;
    priority_queue<AI<4>, vector<AI<4>>, greater<AI<4>>> q;
    vector<LL> ans, vec;
    void init() {
        sort(vec.begin(), vec.end());
        LL res = 0;
        if(vec.size() < l) fail();
        rep(i, 0, l - 1) res += vec[i];
        q.push(AI<4>{res, l - 2, l - 1, (LL)vec.size()});
    }
    void nxt() {
        if(q.size() == 0) return ans.emplace_back(INF), void();
        auto [res, x, y, z] = q.top(); ans.emplace_back(res); q.pop();
        if(x + 1 == y && z == vec.size() && x + 2 < z && x + 3 <= r)
            q.push({res + vec[x + 2], x + 1, x + 2, z});
        if(y + 1 < z && y >= 0) q.push({res + vec[y + 1] - vec[y], x, y + 1, z});
        if(x + 1 < y && x >= 0) q.push({res + vec[x + 1] - vec[x], x - 1, x + 1, y});
    }
    LL ask(int kk) {
        for(; kk >= ans.size(); nxt());
        return ans[kk];
    } 
}col[N];
bool operator<(COL &x, COL &y) {return x.ask(1) - x.ask(0) < y.ask(1) - y.ask(0);}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1, x, y; i <= n; i++) 
        cin >> x >> y, col[x].vec.emplace_back(y);
    for(int i = 1; i <= m; i++) cin >> col[i].l >> col[i].r, col[i].init();
    sort(col + 1, col + 1 + m);

    priority_queue<AI<3>, vector<AI<3>>, greater<AI<3>>> q;
    {
        LL res = 0;
        rep(i, 1, m)
            res += col[i].ask(0);
        q.push({res, 1, 0});
    }
    rep(i, 1, k) {
        if(!q.size()) {
            cout << -1 << '\n';
            continue;
        }
        auto [ans, x, y] = q.top(); q.pop();
        cout << ans << '\n';
        if(col[x].ask(y + 1) != INF) 
            q.push({ans + col[x].ask(y + 1) - col[x].ask(y), x, y + 1});
        if(y > 0 && x + 1 <= m && col[x + 1].ask(1) != INF)
            q.push({ans + col[x + 1].ask(1) - col[x + 1].ask(0), x + 1, 1});
        if(x + 1 <= m && y == 1 && col[x + 1].ask(1) != INF) 
            q.push({ans - (col[x].ask(1) - col[x].ask(0)) + 
                    col[x + 1].ask(1) - col[x + 1].ask(0), 
                    x + 1, 1});
    }
    return 0;
}