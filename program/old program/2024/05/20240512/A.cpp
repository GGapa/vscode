// A
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int fx[4] = {1, -1, 0, 0}, fy[4] = {0, 0, 1, -1};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> C(n + 1, vector<char>(m + 1));
    vector<VI> L(n + 1, VI(m + 1)), H(n + 1, VI(m + 1));
    rep(i, 1, n) rep(j, 1, m) {
        cin >> C[i][j];
        L[i][j] = L[i][j - 1] + (C[i][j] == 'X') ;
        H[i][j] = H[i - 1][j] + (C[i][j] == 'X');
    }
    vector<VI> vis(n + 1, VI(m + 1));
    queue<array<int, 3>> q;
    q.push({1, 1, 0});
    while(!q.empty()) {
        auto nw = q.front(); q.pop();
        vis[nw[0]][nw[1]] = 1;
        if(C[nw[0]][nw[1]] == '#') return cout << nw[2] << '\n', 0;
        rep(i, 0, 3) rep(p, 0, 9) {
            int st = (1 << p), nx = nw[0] + fx[i] * st, ny = nw[1] + fy[i] * st;
            if(nx > 0 && ny > 0 && nx <= n && ny <= m && !vis[nx][ny] && (fy[i] == 0 || L[nw[0]][nw[1]] == L[nx][ny]) && (fx[i] == 0 || H[nw[0]][nw[1]] == H[nx][ny]) && C[nx][ny] != 'X') 
                q.push({nx, ny, nw[2] + 1}), vis[nx][ny] = 1;
        }
    }
    cout << -1 << '\n';
    return 0;
}