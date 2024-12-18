// P1775 石子合并（弱化版）
// https://www.luogu.com.cn/problem/P1775
// 2023-11-12 16:14
#include <iostream>
using namespace std;
const int maxn = 300 + 5;

int a[maxn], f[maxn][maxn];
int n;

int dfs(int l, int r) {
    if(f[l][r]) return f[l][r];
    if(l == r) return f[l][r] = 0;
    int tmp = 2e9;
    for(int i = l; i < r; i++)  
        tmp = min(tmp, dfs(l, i) + dfs(i + 1, r) + a[r] - a[l-1]);
    return f[l][r] = tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    dfs(1, n);
    cout << f[1][n] << "\n";
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
661B
用时
118ms
内存
864.00KB
 GGapa

所属题目
P1775 石子合并（弱化版）
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 16:21:07
*/