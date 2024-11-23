#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5, mod = 1e9 + 7;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}

int find(int x, int *fa) {
    while(x != fa[x]) x = fa[x] = fa[fa[x]]; 
    return x;
}

bool merge(int x, int y, int *fa) {
    x = find(x, fa), y = find(y, fa);
    if(x == y) return false;
    fa[x] = y;
    return true;
}

int fa[20][N];

signed main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    rep(i, 0, 19) iota(fa[i], fa[i] + 1 + n, 0);
    for(int i = 1, l1, l2, r1, r2; i <= m; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        int it = __lg(r1 - l1 + 1);
        merge(l1, l2, fa[it]); merge(r1 - (1 << it) + 1, r2 - (1 << it) + 1, fa[it]);
    }
    per(it, __lg(n), 1) {
        for(int i = 1; i + (1 << it) - 1 <= n; i++) {
            int tmp = find(i, fa[it]);
            if(tmp == i) continue;
            merge(i, tmp, fa[it - 1]);
            merge(i + (1 << it - 1), tmp + (1 << it - 1), fa[it - 1]);
        }
    }
    int cnt = 0;
    vector<int> vis(n + 1);
    rep(i, 1, n) {
        int t = find(i, fa[0]);
        if(!vis[t]) {
            cnt++; vis[t] = 1;
        }
    }
    cout << 9ll * qpow(10, cnt - 1) % mod << '\n';
    return 0;
}