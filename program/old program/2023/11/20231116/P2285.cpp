/**
 * @Problem      : P2285 [HNOI2004] 打鼹鼠
 * @URL          : https://www.luogu.com.cn/problem/P2285
 * @Author       : GGapa
 * @Date         : 2023-11-16 11:36:54
 * @LastEditTime : 2023-11-16 11:45:42
**/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 10000 + 5;
int f[maxn], t[maxn], x[maxn], y[maxn];
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        cin >> t[i] >> x[i] >> y[i];
        f[i] = 1;
        for(int j = 1; j < i; j++) {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    for(int i = 1; i <= m; i++) ans = max(ans, f[i]);
    cout << ans << '\n';
    return 0;
    return 0;
}