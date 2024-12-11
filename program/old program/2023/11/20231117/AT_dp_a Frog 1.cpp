/**
 * @Problem      : AT_dp_a Frog 1
 * @URL          : https://atcoder.jp/contests/dp/tasks/dp_a
 * @Author       : GGapa
 * @Date         : 2023-11-17 10:56:23
 * @LastEditTime : 2023-11-17 13:09:53
**/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int a[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[2] = abs(a[2] - a[1]);
    for(int i = 3; i <= n; i++) 
        f[i] = min(f[i - 1] + abs(a[i] - a[i - 1]), f[i - 2] + abs(a[i] - a[i - 2]));
    cout << f[n];
    return 0;

}
// AC 100pts