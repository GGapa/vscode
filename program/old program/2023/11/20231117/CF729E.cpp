/**
 * @Problem      : CF729E Subordinates
 * @URL          : https://www.luogu.com.cn/problem/CF729E
 * @Author       : GGapa
 * @Date         : 2023-11-17 15:21:18
 * @LastEditTime : 2023-11-17 16:10:38
**/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;

int n, s;
int a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", 'w', stdout);
    cin >> n >> s;
    int ans = 0, cnt = 1;
    for(int i = 1, x; i <= n; i++) cin >> x, i == s ? ans += x > 0 : a[x]++;
    for(int i = 1; cnt < n; i++) {
        cnt += a[i] > 0 ? a[i] : 1;
        ans += (a[i] == 0);
    }
    cout << ans;
    return 0;
}