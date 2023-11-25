// T368263 环上最大独立集
// https://www.luogu.com.cn/problem/T3682633
// 2023-11-12 16:29

#include <iostream>
#include <limits.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;

int n;
ll a[maxn], dp[maxn * 2][2];    //0 不选，1 要选
ll ans1, ans2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = -1e16;
    dp[1][1] = a[1];
    for(int i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][0] + a[i];
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        if(i != n) ans1 = max({ans1, dp[i][1], dp[i][0]});
        else ans1 = max(ans1, dp[i][0]);
    }

    memset(dp, 0, sizeof(dp));
    dp[1][1] = -1e16;
    for(int i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][0] + a[i];
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        if(i != n)ans2 = max({dp[i][1], dp[i][0], ans2});
        else ans2 = max({dp[i][1], ans2});
    }
    cout << max(ans1, ans2) << "\n";
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.17KB
用时
230ms
内存
4.26MB
 GGapa

所属题目
T368263 环上最大独立集
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 17:12:17
*/
