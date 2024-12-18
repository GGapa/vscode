// P2827 [NOIP2016 提高组] 蚯蚓
// https://www.luogu.com.cn/problem/P2827
// 2023-11-13 19:54
/*
这道题目的思路是如何想出来的？
若不考虑单调性，还是能得到 70-85 pts 的。
只要一能找到单调性这个就比较好写了。
为了方便操作，我们并不用每一次都加上，但是呢为了减少操作次数，可以逆操作，进行逆向思维。
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
#define int long long
int n, m, q, u, v, t;
int a[maxn];

queue<int> q1, q2, q3;

int findmax() {
    int x, x1, x2, x3;
    if(!q1.empty()) x1 = q1.front(); else x1 = -2e9;
    if(!q2.empty()) x2 = q2.front(); else x2 = -2e9;
    if(!q3.empty()) x3 = q3.front(); else x3 = -2e9;
    if(x1 > x2 && x1 > x3) x = x1, q1.pop();
    else if(x2 > x3) x = x2, q2.pop();
    else x = x3, q3.pop();
    return x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m >> q >> u >> v >> t;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<>());
    for(int i = 1; i <= n; i++) q1.push(a[i]);
    for(int i = 1; i <= m; i++) {
        int x = findmax() + q * (i - 1);
        if(i % t == 0) cout << x << ' ';
        int y = 1.0 * x * u / v;
        x -= y;
        y -= q * i; q2.push(y);
        x -= q * i; q3.push(x);
    }
    cout << '\n';
    for(int i = 1; i <= n + m; i++) {
        int x = findmax() + q * m;
        if(i % t == 0) cout << x << ' ';
    }
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.36KB
用时
1.44s
内存
58.17MB
GGapa

所属题目
P2827 [NOIP2016 提高组] 蚯蚓
评测状态
Accepted
评测分数
100
提交时间
2023-11-13 20:40:50
*/