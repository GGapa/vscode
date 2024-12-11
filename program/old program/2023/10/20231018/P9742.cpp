#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)     {
        long long ans = 0, mx = -1e18, sum = 0;
        int n;
        cin >> n;
        for(int i = 1, t; i <= n; i++) cin >> t;
        for(int i = 1, c; i <= n; i++) {
            cin >> c;
            int t = abs(c);
            ans = max(ans, mx + sum + c);
            sum += t;
            mx = max(mx, -c - sum);
        }
        cout << ans << "\n";
    }
}
/*
编程语言
C++14 (GCC 9)
代码长度
588B
用时
1.42s
内存
808.00KB
 GGapa

所属题目
P9742 「KDOI-06-J」贡献系统
评测状态
Accepted
评测分数
100
提交时间
2023-10-18 22:58:41
*/