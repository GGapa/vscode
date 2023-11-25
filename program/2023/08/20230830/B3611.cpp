/*
B3611 【模板】传递闭包
https://www.luogu.com.cn/problem/B3611
*/

#include <iostream>
using namespace std;
const int maxn = 100 + 5;

int n;
int G[maxn][maxn], ans[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> G[i][j];
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                G[i][j] = G[i][j] | (G[i][k] & G[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << G[i][j] << " \n"[j == n];
        }
    }
    return 0;
}