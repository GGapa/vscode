#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct Node {
    int a, b;
    Node() {a = b = 0; }
    friend Node operator+(const Node &x, const Node &y) {
        Node ret;
        vector<int> tmp;
        tmp.emplace_back(x.a);
        tmp.emplace_back(x.b);
        tmp.emplace_back(y.a);
        tmp.emplace_back(y.b);
        sort(tmp.begin(), tmp.end(), greater<>());
        ret.a = tmp[0], ret.b = tmp[1];
        return ret;
    }
    int val() {return a + b; }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int tp = (1 << n) - 1;
    vector<Node> F(tp + 1);
    for(int i = 0; i <= tp; i++) 
        cin >> F[i].a;
    rep(i, 0, n - 1) rep(s, 0, tp) if(s >> i & 1) 
        F[s] = F[s] + F[s ^ (1 << i)];

    int ans = 0;
    rep(i, 1, tp) {
        ans = max(ans, F[i].val());
        cout << ans << '\n';
    }
    return 0;
}