#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn =  1e3 + 5;
int n, m, sx, sy, tx, ty, num, cnt;
int used[maxn][maxn];
int fx[4] = {1, -1, 0, 0}, fy[4] = {0, 0, 1, -1};
char ans[maxn * maxn], st[4] = {'R', 'L', 'D', 'U'};
vector<pair<int, int>> test;

namespace baoli {

void out() {
    for(int i = 0; i <= cnt ;i++) putchar(ans[i]);
    exit(0);
}

void dfs(int x, int y) {

    // cout << x << " " << y << endl;
    if(x == tx && y == ty) {
        if(cnt == n * m - 1)out();
        return ;
    }
    for(int i = 0 ; i < 4; i++) {
        int nx = x + fx[i], ny = y + fy[i];
        if(used[nx][ny] || nx < 1 || ny < 1 || nx > n || ny > m) continue;
        ans[++cnt] = st[i];
        used[nx][ny] = true;
        dfs(nx, ny);
        cnt--;
        used[nx][ny] = false;
    }
}

}

namespace TN_1TM {
   void solve() {
        for(int i = 1; i < n - 1; i++) {
            if(i % 2) {
                for(int j = 1; j < m; j++) cout << "D";
            }
            else {
                for(int j = 1; j < m; j++) cout << "U";
            }
            cout << "R";
        }
        for(int i = 1; i <= m; i++) {
            if(i % 2) cout << "R";
            else cout << "L";
            if(i != m) cout << "D";
        }
        exit(0);
   }
}

namespace T1N2S1S1 {
void solve() {
    for(int i = 1; i < n; i++) cout << "R";
    for(int i = 1; i < m; i++) cout << "D";
    cout << "L";
    for(int i = n - 1; i >= 1; i--) {
        if(i % 2) {
            for(int i = 1; i < m - 1; i++) cout << "U";
        }
        else {
            for(int i = 1; i < m - 1; i++) cout << "D";
        }
        if(i != 1)cout << "L";
    }
    exit(0);
}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifdef ONLINE_JUDGE
    freopen("post.in", "r", stdin);
    freopen("post.out", "w", stdout);
// #endif
    cin >> n >> m >> sx >> sy >> tx >> ty;
    num = n * m;
    used[sx][sy] = true;
    if(tx == n - 1 && ty == m && sx == 1 && sy == 1) TN_1TM::solve();
    if(tx == 1 && ty == 2 && sx == 1 && sy == 1)  T1N2S1S1::solve();
    if(m <= 30 ) baoli::dfs(sx, sy);
    return 0;
}