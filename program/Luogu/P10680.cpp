#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N =2e5 + 5;

int F[N][__lg(N) + 1];


int dfs(int x, int y) {
    if(y <= 8) return F[x][y];
    else return abs(dfs(x, y - 1) - dfs(x + (1 << y - 1), y - 1));
    return -1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i], F[i][0] = A[i];
    rep(j, 1, 8) for(int i = 1; i + (1 << j) - 1 <= n; i++) 
        F[i][j] = abs(F[i][j - 1] - F[i + (1 << j - 1)][j - 1]);
    for(int op, x, y; q--; ) { 
        cin >> op >> x >> y;
        if(op == 1) {
            A[x] = F[x][0] = y;
            rep(j, 1, min(__lg(n), 8)) for(int i = max(x - (1 << j), 1); i + (1 << j) - 1 <= min(x + (1 << j), n); i++) 
                F[i][j] = abs(F[i][j - 1] - F[i + (1 << j - 1)][j - 1]);
        } 
        else cout << dfs(x, y) << '\n';
    }
    return 0;
}