/*
P2758 编辑距离
https://www.luogu.com.cn/problem/P2758
*/

#include <iostream>
using namespace std;
const int maxn = 2000 + 5;

int dp[maxn][maxn];

int main() {
    string a, b;
    cin >> a >> b;
    a.insert(0, " ");
    b.insert(0, " ");
    for(int i = 1; i <= a.length(); i++) dp[i][0] = i;
    for(int i = 1; i <= b.length(); i++) dp[0][i] = i;
    for(int i = 1; i <= a.length(); i++) {
        for(int j = 1; j <= b.length(); j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    cout << dp[a.length()][b.length()];
    return 0;
}