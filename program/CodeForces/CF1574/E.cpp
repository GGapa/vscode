//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int mod = 998244353;

map<pair<int, int>, int> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> pre(max(n, m) + 1);
    pre[0] = 1;
    rep(i, 1, max(n, m)) (pre[i] = pre[i - 1] * 2) %= mod; 
    int c1, c2, l1, l2; //有多少格子是没有限制的，有多少格子是冲突的
    vector<VI> W(n + 1, VI(2)), H(m + 1, VI(2));    //当前的行列有多少个限制条件 
    vector<int> C(2); 
    auto update = [&](int x, int y, int z) {
        if(W[x][0] && W[x][1]) l1 += z;
        if(H[y][0] && H[y][1]) l2 += z;
        if(!W[x][0] && !W[x][1]) c1 += z;
        if(!H[y][0] && !H[y][1]) c2 += z;
        if(W[x][0]) C[(x & 1) ^ 0] += z;
        if(W[x][1]) C[(x & 1) ^ 1] += z;
    };
    auto ins = [&](int x, int y, int z) {
        mp[{x, y}] = z + 1;
        W[x][(y & 1) ^ z]++;
        H[y][(x & 1) ^ z]++;
    };
    auto del = [&](int x, int y, int z) {
        mp[{x, y}] = 0;
        W[x][(y & 1) ^ z]--;
        H[y][(x & 1) ^ z]--;
    };
    c1 = n, c2 = m; l1 = l2 = 0;
    for(int x, y , z ; k--; ) {
        cin >> x >> y >> z;
        update(x, y, -1);
        if(mp[{x, y}]) del(x, y, mp[{x, y}] - 1);
        if(z != -1) ins(x, y, z);
        update(x, y, 1);
        ll res = 0;
        res = (pre[c1] * (l1 == 0) + pre[c2] * (l2 == 0)) % mod;
        res = (res - !C[0] - !C[1] + mod) % mod;
        cout << res << '\n';
    }
    return 0;
}