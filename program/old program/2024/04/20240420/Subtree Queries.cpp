// Subtree Queries
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
typedef long long ll;
using VI = vector<int>;

struct BIT {
    int n;
    vector<ll> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, ll v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    int ask(int x) {
        ll res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, idx = 0; cin >> n >> q;
    vector<VI> G(n+ 1);
    VI A(n  +1), in(n +1), out(n + 1), to(n + 1);
    rep(i, 1, n) cin >> A[i];
    for(int i = 2, u, v; i <= n; i++)
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);    
    function<void(int ,int)> dfs = [&](int x, int pa) {
        in[x] = ++idx; to[x] = idx;
        for(auto to : G[x]) if(to != pa) {
            dfs(to, x);
        }
        out[x] = idx;
    };
    dfs(1, 0);
    BIT T(n);
    rep(i, 1, n ) T.add(in[i], A[i]); 
    for(int op, x, y, o = 1; o <= q; o++) {
        cin >> op >> x;
        if(op == 1) {
            cin >> y;
            T.add(in[x], (long long)y - A[x]);
            A[x] = y;
        }
        else 
            cout << T.ask(out[x]) - T.ask(in[x] - 1) << '\n';
    }
    return 0;
}