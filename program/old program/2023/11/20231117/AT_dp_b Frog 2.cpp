/**
 * @Problem      : AT_dp_b Frog 2
 * @URL          : https://www.luogu.com.cn/remoteJudgeRedirect/atcoder/dp_b
 * @Author       : GGapa
 * @Date         : 2023-11-17 13:04:20
 * @LastEditTime : 2023-11-17 13:09:55
**/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;

int n, k;
int a[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(f, 0x3f3f, sizeof(f));
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[2] = abs(a[2] - a[1]); f[1] = 0;
    for(int i = 3; i <= n; i++) for(int j = i - 1; j >= max(i - k, 1); j--)
        f[i] = min(f[i], f[j] + abs(a[i] - a[j]));
    cout << f[n];
    return 0;

}
// AC 100pts