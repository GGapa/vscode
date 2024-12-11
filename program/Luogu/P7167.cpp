// P7167 [eJOI2020 Day1] Fountain
// https://www.luogu.com.cn/problem/P7167
// 2023-11-13 14:04

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
#define int long long
int n, q;
int d[maxn], c[maxn], rmax[20][maxn], f[20][maxn], g[20][maxn];

int qurey(int x, int y ) {
    int it = log2(y - x + 1);
    return max(rmax[it][x], rmax[it][y - (1 << it) + 1]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> d[i] >> c[i], rmax[0][i] = d[i];
    for(int i = 1; (1 << i) <= n; i++) {
        for(int j = 1; j + (1 << i) - 1 <= n; j++) {
            rmax[i][j] = max(rmax[i-1][j], rmax[i-1][j + (1 << i-1)]);
        }
    }
    c[n+1] = 1e9;
    for(int i = 1; i < n; i++) {
        int l = i + 1, r = n + 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(qurey(i + 1, mid) <= d[i])
                l = mid + 1;
            else 
                r = mid;
        }
        f[0][i] = l;
        g[0][i] = c[f[0][i]];
    }
    f[0][n] = n + 1;
    g[0][n] = c[f[0][n]];
    for(int i = 1; i <= 16; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][j] = f[i-1][f[i-1][j]];
            g[i][j] = g[i-1][j] + g[i-1][f[i-1][j]];
        }
    }
    while(q--) {
        int r, v;
        cin >> r >> v;
        if(v > c[r]) {
            v -= c[r];
            for(int i = 16; i >= 0; i--) {
                    if(v > g[i][r]) {
                    v -= g[i][r];
                    r = f[i][r];
                }
            }
            r = f[0][r];
        }
        if(r == n + 1) r = 0;
        cout << r << '\n';
    }
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.82KB
用时
330ms
内存
42.43MB
 GGapa

所属题目
P7167 [eJOI2020 Day1] Fountain
评测状态
Accepted
评测分数
100
提交时间
2023-11-13 15:32:05
*/