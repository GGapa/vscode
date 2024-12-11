// P1120 小木棍
// https://www.luogu.com.cn/problem/P1120
// 2023-11-13 17:07
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 66;

int n, sum;
int a[maxn], len[maxn], pre[maxn];
int d, mn = maxn;

void dfs(int u, int k, int p) {
    if(u == 0) {
        dfs(d, k - 1, a[n]);
        return ;
    }
    if(k == 0) {
        cout << d << '\n';
        exit(0);
    }
    p = (p < u) ? p : u;
    while(p && len[p] == 0) p--;
    while(p) {
        if(len[p]) {
            len[p]--;
            dfs(u - p, k, p);
            len[p]++;
            if((u == p) || (u == d)) return;
            p = pre[p];
        }
        else p = pre[p];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], len[a[i]]++, sum += a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) 
        if(a[i] != a[i-1]) pre[a[i]] = a[i-1];
    for(d = a[n]; d * 2 <= sum; d++) 
        if(sum % d == 0) 
            dfs(d, sum / d, a[n]);
    cout << sum << "\n";
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.21KB
用时
421ms
内存
812.00KB
 GGapa

所属题目
P1120 小木棍
评测状态
Accepted
评测分数
100
提交时间
2023-11-13 17:50:04
*/
