#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int op[3][33];

int calc(int x, int y, int z) {
    assert(x <= 1 && y <= 1 && 0 <= z && z <= 2);
    if(z == 0) return x & y;
    if(z == 1) return x | y;
    return x ^ y;
}

namespace ns {
    int ops;
    LL mx1, mx2;
    LL F[33][2][2][2];

    LL dfs(int x, int t1, int t2, int t3) {     // 构成的数、左侧、右侧 a = b op c c <= b
        if(x < 0) return 1;
        auto &f = F[x][t1][t2][t3];
        if(f != -1) return f;
        f = 0;

        int u1 = (t1 ? 1 : (mx1 >> x & 1));
        int u2 = (t2 ? 1 : (mx2 >> x & 1));

        if(x <= 6 && ops == 5 && mx1 == 101) {
            x++;
            x--;
        }

        rep(i, 0, u1) {
            int mcnt = 3; 
            rep(j, 0, u2) rep(k, 0, (t3 ? 1 : j)) {
                 bool tag = 0;
                rep(a, 0, 2) if((ops >> a & 1)) {
                    if(calc(j, k, op[a][x]) != i) {
                        tag = 1; break;
                    }
                }
                if(tag) continue;
                mcnt = min(mcnt, (j == 1) + (k == 1));
            }
            if(mcnt == 3) continue;
            if(mcnt == 2) f += dfs(x - 1, t1 | (i < u1), t2, t3);
            if(mcnt == 1) {
                if(u2) f += dfs(x - 1, t1 | (i < u1), t2, 1);
                else f += dfs(x - 1, t1 | (i < u1), t2 | (0 < u2), t3);
            }
            if(mcnt == 0) f += dfs(x - 1, t1 | (i < u1), t2, t3);
        }
        return f;
    }

    LL work(LL x) {
        if(x < 0) return 0;
        mx1 = x;
        memset(F, -1, sizeof(F));
        cerr << mx1 << ' ' << mx2 << ' ' << x << " " << ops << " " << dfs(32, 0, 0, 0) << '\n'; 
        return dfs(32, 0, 0, 0);
    }

    LL sol(LL p, LL l, LL r) {
        int tp = 7; mx2 = p;
        LL ret = max(0ll, min(p, r) - l + 1); 
        l = max(l, p + 1);
        if(l > r) return ret;
        for(ops = 1; ops <= tp; ops++) {
            ret += ((__builtin_popcount(ops) & 1) ? 1 : -1) * (work(r) - work(l - 1));
        }
        return ret;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    rep(i, 0, 2) rep(j, 0, 31) cin >> op[i][j];

    for(LL x, y, z, oo; q--; ) {
        cin >> oo >> x >> y >> z;
        if(oo == 1) op[x][y] = z;
        else cout << ns::sol(x, y, z) << '\n';
    }

    return 0;
}
/*
显然可以把得到 [l, r] 中的数，转化为前缀和相减。
考虑数位 DP

1
1 1 2 2 2 0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 1 0 2 1 0 1 0 2 0 0 2 
0 2 2 1 2 2 2 1 0 2 1 2 1 0 1 2 2 0 2 2 2 1 1 1 0 2 0 0 2 1 0 2 
1 0 1 1 0 2 0 2 0 1 1 0 2 1 2 2 1 2 2 1 2 1 2 0 0 2 0 1 1 1 2 0 
2 6 5 7

定义 F(i, t1, t2, t3) 然后可能要判断一堆东西，当前已知问题
*/