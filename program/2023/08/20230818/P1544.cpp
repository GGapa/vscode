/*
P1544 三倍经验
https://www.luogu.com.cn/problem/P1544
*/
#include <iostream>
#include <limits.h>
using namespace std;
const int maxn = 200 + 5;
typedef long long ll;
#define int long long

int n, k;
int a[maxn][maxn];
ll dp[maxn][maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int q = 0; q <= k; q++) {
                dp[i][j][q] = INT_MIN;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[n][i][0] = a[n][i];
        dp[n][i][1] = a[n][i] * 3;
    }
    for(int i = n; i >= 2; i--)  {
        for(int j = 1; j <= i; j++) {
            for(int q = 0; q <= k && q <= n - i + 2; q++) {
                dp[i - 1][j][q] = max(dp[i - 1][j][q], dp[i][j][q] + a[i-1][j]);
                dp[i - 1][j - 1][q] = max(dp[i - 1][j - 1][q], dp[i][j][q] + a[i-1][j - 1]);
                dp[i - 1][j][q + 1] = max(dp[i - 1][j][q + 1], dp[i][j][q] + a[i-1][j] * 3);
                dp[i - 1][j - 1][q + 1] = max(dp[i - 1][j - 1][q + 1], dp[i][j][q] + a[i-1][j - 1] * 3);
            }
        }
    }
    ll ans = INT_MIN;
    for(int i = 0; i <= min(k, n); i++) {
        ans = max(ans, dp[1][1][i]);
    }
    cout << ans << endl;
    return 0;
}