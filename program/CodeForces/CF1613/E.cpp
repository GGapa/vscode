#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int fx[] = {0, 0, 1, -1}, fy[] = {1, -1, 0, 0};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> A(n + 1, vector<char>(m + 1));
    vector<VI> vis(n + 1, VI(m + 1));
    int sx, sy;
    rep(i ,1, n) rep(j, 1, m) {
        cin >> A[i][j];
        if(A[i][j] == 'L') sx = i, sy = j;
    }
    queue<pair<int, int>> q;
    q.push({sx, sy}) ;
    auto check = [&](int x, int y) {
        int opt = 0;
        rep(i, 0, 3) {
            int nx = x + fx[i], ny = y + fy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m || A[nx][ny] == '#' || vis[nx][ny]) continue;
            opt++;
        }
        return opt <= 2;
    };
    while(!q.empty()){ 
        int x = q.front().first, y = q.front().second; q.pop();
        if(A[x][y] != 'L') A[x][y] = '+';
        rep(i, 0, 3) {
            int nx = x + fx[i], ny = y + fy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m || A[nx][ny] == '#' || vis[nx][ny] || !check(nx, ny)) continue;
            q.push({nx, ny});
        }
        vis[x][y] = 1;
    }
    rep(i, 1, n) rep(j, 1, m) cout << A[i][j] << (j == m ? "\n" : "");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();

    return 0;
}