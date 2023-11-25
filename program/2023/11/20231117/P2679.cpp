/**
 * @Problem      : P2679 [NOIP2015 提高组] 子串
 * @URL          : https://www.luogu.com.cn/problem/P2679
 * @Author       : GGapa
 * @Date         : 2023-11-17 09:18:34
 * @LastEditTime : 2023-11-17 09:56:03
**/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int mod = 1000000007;
const int maxm = 200 + 5;
const int maxn = 1000 + 5;

int n, m, k;
int f[2][maxn][maxm], g[2][maxn][maxm];
char a[maxn], b[maxm], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m >> k;
    cin >> a + 1 >> b + 1;
    int it = 1;
    for(int i = 0; i <= n; i++) g[0][i][0] = 1;
    for(int K = 1; K <= k; K++, it ^= 1) {
        memset(f[it], 0, sizeof(f[it]));
        memset(g[it], 0, sizeof(g[it]));
        for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {f[it][i][j] = (f[it][i-1][j-1] + g[it^1][i-1][j-1]) % mod;} 
            g[it][i][j] = (g[it][i-1][j] + f[it][i][j]) % mod;
        }
    }
    cout << g[it ^ 1][n][m] ;
    return 0;
}
//AC 100pts