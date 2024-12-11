// P1880 [NOI1995] 石子合并
// https://www.luogu.com.cn/problem/P1880
// 2023-11-12 16:02
#include <iostream>
#include <limits.h>
using namespace std;
const int maxn = 205 + 5;

int n, a[maxn], f1[maxn][maxn], f2[maxn][maxn];

int dfs1(int l, int r) {
    if(f1[l][r]) return f1[l][r];
    if(l == r) return f1[l][r] = 0;
    int tmp = INT_MAX;
    for(int mid = l; mid < r; mid++) 
        tmp = min(tmp, dfs1(l, mid) + dfs1(mid + 1, r) + a[r] - a[l - 1]);
    return f1[l][r] = tmp;
}

int dfs2(int l, int r) {
    if(f2[l][r]) return f2[l][r];
    if(l == r) return f2[l][r] = 0;
    int tmp = 0;
    for(int mid = l; mid < r; mid++) 
        tmp = max(tmp, dfs2(l, mid) + dfs2(mid + 1, r) + a[r] - a[l - 1]);
    return f2[l][r] = tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[n + i] = a[i];
    for(int i = 1; i <= n * 2; i++) a[i] += a[i-1];
    int ans1 = INT_MAX, ans2 = 0;
    dfs1(1, 2 * n);
    dfs2(1, 2 * n);
    for(int i = 1; i <= n; i++) {
        ans1 = min(ans1, f1[i][i + n - 1]);
        ans2 = max(ans2, f2[i][i + n - 1]);
    }
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.30KB
用时
50ms
内存
808.00KB
 GGapa

所属题目
P1880 [NOI1995] 石子合并
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 16:12:49
*/