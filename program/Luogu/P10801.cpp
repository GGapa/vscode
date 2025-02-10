#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 2e5 + 5;

vector<AI<2>> G[N];
priority_queue<AI<3>, vector<AI<3>>, greater<AI<3>>> q;

struct dir {
    vector<int> l, r;
    vector<AI<4>> v;
    int n = 0;

    void push_back(const AI<4> &tmp) {
        v.emplace_back(tmp); 
    } 
    void add(int i, int tp = 0) {
        int L = l[i], R = (tp ? i : r[i]);
        if(!v[L][3] && v[R][3]) 
            q.push({abs(v[R][1] - v[L][1]), v[L][2], v[R][2]});
    }
    void init(int id) {
        n = v.size();
        sort(v.begin(), v.end());
        v.insert(v.begin(), {0, 0, 0, 1}), v.push_back({0, 0, 0, 0});
        l.resize(v.size()); r = l;
        rep(i, 1, n) G[v[i][2]].push_back({id, i});
        rep(i, 1, n) {
            l[i] = (v[i][0] == v[i - 1][0] ? i - 1 : 0);
            r[i] = (v[i][0] == v[i + 1][0] ? i + 1 : n + 1);
        }
        rep(i, 1, n) add(i, 1);
    }
    void del(int i) {
        add(i);
        r[l[i]] = r[i], l[r[i]] = l[i];
    }
}d[6];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1, x, y; i <= n; i++) {
        char tp; cin >> x >> y >> tp;
        if(tp == 'N') {
            d[0].push_back({x + y, x, i, 0});
            d[3].push_back({x - y, x, i ,1});
            d[5].push_back({x, y / 2, i, 1});
        }
        else if(tp == 'S') {
            d[1].push_back({x + y, x, i, 1});
            d[2].push_back({x - y, x, i ,0});
            d[5].push_back({x, y / 2, i, 0});
        }
        else if(tp == 'E') {
            d[1].push_back({x + y, x, i, 0});
            d[3].push_back({x - y, x, i, 0});
            d[4].push_back({y, x / 2, i, 0});
        }
        else {
            d[0].push_back({x + y, x, i, 1});
            d[2].push_back({x - y, x, i ,1});
            d[4].push_back({y, x / 2, i, 1});
        }
    }
    rep(i, 0, 5) d[i].init(i);

    vector<int> ans(n + 1);
    while(q.size()) {
        vector<int> v;
        for(int t = q.top()[0], x, y; q.size() && q.top()[0] == t; q.pop()) 
            if(!ans[x = q.top()[1]] && !ans[y = q.top()[2]])
                v.emplace_back(x), v.emplace_back(y);
        for(auto i : v) if(!ans[i]) {
            ans[i] = 1; 
            for(auto [id, j] : G[i]) d[id].del(j); 
        }
    }

    rep(i, 1, n) if(!ans[i]) cout << i << '\n';

    return 0;
}
/*
需要记录不同的方向，然后要记录不同方向上不同的点，
点需要记录的是编号，还需要记录两个值（对应方向上的值和用来计算距离的值)
*/