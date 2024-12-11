/*
P3205 [HNOI2010] 合唱队
https://www.luogu.com.cn/problem/P3205
*/

#include <iostream>
using namespace std;
const int maxn = 1000 + 5;
const int mod = 19650827;

int n;
int a[maxn], dp[maxn][maxn][2];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i][0] = 1;
    }
    for(int len = 1; len <= n; len++) {
        for(int i = 1, j = i + len; j <= n; j++, i++) {
            if(a[i] < a[i + 1])dp[i][j][0] += dp[i + 1][j][0];
            if(a[i] < a[j])dp[i][j][0] += dp[i + 1][j][1];
            if(a[j] > a[i])dp[i][j][1] += dp[i][j - 1][0];
            if(a[j] > a[j - 1]) dp[i][j][1] += dp[i][j - 1][1];
            dp[i][j][0] %= mod;
            dp[i][j][1] %= mod;
        }
    }
    cout << (dp[1][n][0] + dp[1][n][1]) % mod;
    return 0;   
}