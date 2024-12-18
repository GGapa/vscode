#include <iostream>
#include <vector>
using namespace std;
const int maxn = 60 + 5;

int n, m;
int a_[1000][1000];
vector<int> a;
bool used[1000][1000];
int dp[maxn][maxn][maxn][maxn];
int c1, c2, c3, c4;

void init() {
    int x = 1, y = 1;
    bool whi = true;
    while(whi) {
        whi = false;
        while(y <= m && !used[x][y]) {
            a.push_back(a_[x][y]);
            used[x][y] = true;
            y++;
            whi = true;
        }
        y--;
        x++;
        while(x <= n && !used[x][y]) {
            a.push_back(a_[x][y]);
            used[x][y] = true;
            x++;
            whi = true;
        }
        x--;
        y--;
        while(y >= 1 && !used[x][y]) {
            a.push_back(a_[x][y]);
            used[x][y] = true;
            y--;
            whi = true;
        }
        y++;
        x--;
        while(x >= 1 && !used[x][y]) {
            a.push_back(a_[x][y]);
            used[x][y] = true;
            x--;
            whi = true;
        }
        x++;
        y++;
    }
    //for(auto i : a) cout << i << " ";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            cin >> a_[i][j];
    init();
    dp[0][0][0][0] = a[0];
    cin >> c1 >> c2 >> c3 >> c4;
    int end = a.size();
    int ans = 0;
    for(int i = 0; i <= c1; i++) {
        for(int j = 0; j <= c2; j++) {
           for(int k = 0; k <= c3; k++) {
                 for(int q = 0; q <= c4; q++) {
                    int now = 1 * i + 2 * j + 3 * k + 4 * q;
                    if(now > end) continue;
                    if(i < c1) {
                        dp[i+1][j][k][q] = max(dp[i+1][j][k][q], dp[i][j][k][q] + a[now + 1]);
                    }
                    if(j < c2) {
                        dp[i][j+1][k][q] = max(dp[i][j+1][k][q], dp[i][j][k][q] + a[now + 2]);
                    }
                    if(k < c3) {
                        dp[i][j][k+1][q] = max(dp[i][j][k+1][q], dp[i][j][k][q] + a[now + 3]);
                    }
                    if(q < c4) {
                        dp[i][j][k][q+1] = max(dp[i][j][k][q+1], dp[i][j][k][q] + a[now + 4]);
                    }
                    ans = max(ans, dp[i][j][k][q]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}