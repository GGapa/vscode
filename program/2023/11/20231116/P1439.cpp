/**
 * @Problem      : P1439 【模板】最长公共子序列
 * @URL          : https://www.luogu.com.cn/record/135473594
 * @Author       : GGapa
 * @Date         : 2023-11-16 22:39:23
 * @LastEditTime : 2023-11-16 22:49:55
**/
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

int b[maxn], r[maxn], c[maxn], a[maxn], f[maxn], n;

void add(int x, int y) {
    for(; x < maxn; x += x & -x) 
        c[x] = max(c[x], y);
}

int query(int x) {
    int sum = 0;
    for(; x > 0; x -= x & -x) 
        sum = max(c[x], sum);
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 1, tmp; i <= n; i++)
        cin >> tmp, r[tmp] = i;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = query(r[a[i]]) + 1;
        add(r[a[i]], f[i]);
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}