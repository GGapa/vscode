/**
 * @Problem      : P1874 快速求和
 * @URL          : https://www.luogu.com.cn/problem/P1874
 * @Author       : GGapa
 * @Date         : 2023-11-16 11:59:26
 * @LastEditTime : 2023-11-16 12:33:29
**/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 60;
const int maxs = 1e5 + 5;

string s;
int n, m;
int num[maxn][maxn], dp[maxn][maxs];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> s >> m; n = s.length();
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= i; j++) 
            if(num[j][i - 1] > m) 
                num[j][i] = 2e9;
            else num[j][i] = num[j][i - 1] * 10 + s[i - 1] - '0';
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = i - 1; k >= 0 && num[k + 1][i] <= m; k--) {
                if(j >= num[k + 1][i]) {
                    dp[i][j] = min(dp[i][j], dp[k][j - num[k + 1][i]] + 1);
                }
            }
        }
    }
    cout << (dp[n][m] < 40 ? dp[n][m] : -1);
    return 0;
}

