// P2880 [USACO07JAN] Balanced Lineup G
// https://www.luogu.com.cn/problem/P2880
// 2023-11-13 11:17
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 5e4 + 5;

int n, q;
int mi[20][maxn], mx[20][maxn];

void init() {
    for(int i = 1; (1 << i) <= n; i++) {
        for(int j = 1; j + (1 << i) - 1 <= n; j++) {
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << i - 1)]);
            mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> mi[0][i], mx[0][i] = mi[0][i];
    init();
    while(q--) {
        int l, r;
        cin >> l >> r;
        int it = log2(r - l + 1) ;
        cout << max(mx[it][l], mx[it][r - (1 << it) + 1]) - min(mi[it][l], mi[it][r - (1 << it) + 1]) << "\n";
    }
    return 0;
}       
/*
编程语言
C++14 (GCC 9)
代码长度
1.02KB
用时
232ms
内存
7.12MB
 GGapa

所属题目
P2880 [USACO07JAN] Balanced Lineup G
评测状态
Accepted
评测分数
100
提交时间
2023-11-13 11:28:38
*/