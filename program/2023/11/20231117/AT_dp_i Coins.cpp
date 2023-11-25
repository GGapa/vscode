/**
 * @Problem      : AT_dp_i Coins
 * @URL          : https://www.luogu.com.cn/remoteJudgeRedirect/atcoder/dp_i
 * @Author       : GGapa
 * @Date         : 2023-11-17 18:24:20
 * @LastEditTime : 2023-11-17 18:34:15
**/
#include <iostream>
#include <cstdio>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); i++)
const int maxn = 3000;

double f[maxn], a[maxn];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", 'w', stdout);
    cin >> n;
    f[0] = 1;
    _for(i, 1, n) cin >> a[i];
    _for(i, 1, n)  {
        for(int j = i; j >= 1; j--) 
            f[j] = f[j] * (1 - a[i]) + f[j - 1] * a[i];
            f[0] = f[0] * (1 - a[i]);
    }
    double ans = 0;
    _for(i, n / 2 + 1, n) ans += f[i];
    printf("%.10f", ans);
    return 0;
}