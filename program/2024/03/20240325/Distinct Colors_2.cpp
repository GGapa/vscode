// Distinct Colors
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
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
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    using VI = vector<int>;
    vector<int> A(n + 1), in = A, out = A, ans = A;
    vector<VI> G(n + 1);
    rep(i, 1, n) cin >> A[i];
    for(int i = 2, x, y; i <= n; i++) 
        cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
    int idx = 1;
    BIT T(n);
    auto dfs = [&](auto self, int x, int fa) -> void {
        in[x] = idx;
        for(auto to : G[x]) if(to != fa) 
            self(self, to, x);
        out[idx++] = x;         // 在这里要先对子树进行运算，所以说在这里加
    };
    unordered_map<int, int> lt;
    dfs(dfs, 1, 0);
    rep(i, 1, n) {
        if(lt.count(A[out[i]])) 
            T.add(lt[A[out[i]]], -1);
        lt[A[out[i]]] = i;
        T.add(i, 1);
        ans[out[i]] = T.ask(i) - T.ask(in[out[i]] - 1);
    }
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
    return 0;
}