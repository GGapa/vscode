/**
 * @Problem      : P1064 [NOIP2006 提高组] 金明的预算方案
 * @URL          : https://www.luogu.com.cn/problem/P1064#submit    
 * @Author       : GGapa
 * @Date         : 2023-11-16 11:02:20
 * @LastEditTime : 2023-11-16 11:21:33
**/
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 32000 + 10;

int n, m;
int val[4][maxn], s[4][maxn];
int dp[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1, v, p, q; i <= m; i++) {
        cin >> v >> p >> q;
        if(!q)      
            val[0][i] = v * p, s[0][i] = v;
        else        
            val[++val[3][q]][q] = v * p,
            s[val[3][q]][q] = v;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= s[0][i]; j--) {
            if(j >= s[0][i]) dp[j] = max(dp[j], dp[j - s[0][i]] + val[0][i]);
            if(j >= s[0][i] + s[1][i]) dp[j] = max(dp[j], dp[j - s[0][i] - s[1][i]] + val[0][i] + val[1][i]);
            if(j >= s[0][i] + s[2][i]) dp[j] = max(dp[j], dp[j - s[0][i] - s[2][i]] + val[0][i] + val[2][i]);
            if(j >= s[0][i] + s[1][i] + s[2][i]) dp[j] = max(dp[j], dp[j - s[0][i] - s[1][i] - s[2][i]] + val[0][i] + val[1][i] + val[2][i]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
// AC 100