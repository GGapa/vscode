//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    int q; cin >> q;
    vector<VI> F(n + 2, VI(m + 2)), G = F, A(n + 2, VI(m + 2, 1));
    int del = n * m;
    ll ans = 0;
    auto work = [&](int i, int j) {
        if(i < 1 || j < 1 || i > n || j > m) return ;
        ans -= G[i][j] + F[i][j] ;
        if(A[i][j] == 0) return F[i][j] = G[i][j] = 0, void();
        F[i][j] = G[i][j + 1] + 1;
        G[i][j] = F[i + 1][j] + 1;
        ans += G[i][j] + F[i][j] ;
    };
    per(i, n, 1) per(j, m, 1) {
        A[i][j] = 1;
        work(i, j);
    }
    ans -= del;
    auto update = [&](int x, int y, int z) {
        del += z;
        ans -= z;
        for(int i = x,j = y, op = 0; i >= 0 && j >= 0; i--, j--) {
            work(i, j);
            work(i, j - 1);
            work(i - 1, j);
        }
    };
    for(int x, y; q--; ) {
        cin >> x >> y;
        if(A[x][y]) {
            A[x][y] = 0;
            // work(x, y);
            update(x, y, -1);
        }
        else {
            A[x][y] = 1;
            // work(x, y);
            update(x, y, 1);
        }
        // rep(i ,1, n) rep(j ,1, m) cout << F[i][j] << " \n"[j == m];
        // cout << '\n';
        // rep(i ,1, n) rep(j ,1, m) cout << G[i][j] << " \n"[j == m];
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int T; cin >> T;
    int T = 1;
    while(T--) solve();
    return 0;
}
/*
6 5 1 0
4 4 3 1
2 2 2 1

5 5 4 0
3 3 3 2
1 1 1 1
49
1 0 1 0
4 4 3 1
2 2 2 1

5 0 4 0
3 3 3 2
1 1 1 1
35
1 0 1 0
4 1 0 1
2 2 2 1

5 0 1 0
3 3 0 2
1 1 1 1
24
3 2 1 0
4 1 0 1
2 2 2 1

5 2 1 0
3 3 0 2
1 1 1 1
29
3 2 1 0
4 4 3 1
2 2 2 1

5 2 4 0
3 3 3 2
1 1 1 1
40
*/