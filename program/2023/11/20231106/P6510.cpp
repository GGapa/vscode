// P6510 奶牛排队
// https://www.luogu.com.cn/problem/P6510
// 2023-11-06 21:35
// 单调栈，前缀最大值和前缀最小值二分查找得到答案，听妙的。
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

int n, ans, tx, tn;
int a[maxn], sx[maxn], sn[maxn];    //后缀最大值和后缀最小值

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        while (tn && a[sn[tn]] >= a[i]) --tn;
        while (tx && a[sx[tx]] < a[i]) --tx;
        int it = upper_bound(sn + 1, sn + 1 + tn, sx[tx]) - sn;
        if (it != tn + 1) ans = max(ans, i - sn[it] + 1);
        sn[++tn] = i;
        sx[++tx] = i;
    }
    cout << ans << "\n";
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
856B
用时
91ms
内存
1.21MB
 GGapa

所属题目
P6510 奶牛排队
评测状态
Accepted
评测分数
100
提交时间
2023-11-06 21:44:30
*/