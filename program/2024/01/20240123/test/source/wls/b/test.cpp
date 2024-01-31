#include <bits/stdc++.h>
using namespace std;
const int N = 8e3 + 10, mod = 1e9 + 7;
int n, m, T = 100;

int dp[N][N], C[N][N];
void add(int x) {
    for (int i = T; i >= 1; i--) {
        for (int j = x; j <= T; j++) {
            for (int k = 1; k <= T; k++) {
                if (i >= k && j >= k * x) (dp[i][j] += dp[i - k][j - k * x] * C[i][k] % mod) %= mod;
            }
        }
    }
}
void del(int x) {
    for (int i = 1; i <= T; i++) {
        for (int j = T; j >= x; j--) {
            for (int k = T; k >= 1; k--) {
                if (i >= k && j >= k * x) (dp[i][j] += mod - dp[i - k][j - k * x] * C[i][k] % mod) %= mod;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i <= T; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    dp[0][0] = 1;
    add(2);
    add(3);
    cout << dp[3][7] << '\n';
    del(3);
    add(3);
    cout << dp[3][7] << '\n';
    return 0;
}