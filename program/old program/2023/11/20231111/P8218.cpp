// P8218 【深进1.例1】求区间和
// https://www.luogu.com.cn/problem/P8218
// // 2023-11-11 23:25

#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn], f[maxn], n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], f[i] = f[i-1] + (a[i]);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l-1] << "\n";
    }
}
/*
编程语言
C++14 (GCC 9)
代码长度
492B
用时
136ms
内存
1.32MB
 GGapa

所属题目
P8218 【深进1.例1】求区间和
评测状态
Accepted
评测分数
100
提交时间
2023-11-11 23:27:49
*/  