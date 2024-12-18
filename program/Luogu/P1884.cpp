// P1884 [USACO12FEB] Overplanting S
// https://www.luogu.com.cn/problem/P1884
// 2023-11-12 21:39
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 4e3 +5;
#define int long long

int n;
int a[maxn][4];
int b[maxn], c[maxn];
int f[maxn][maxn];
map<int, int> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j < 4; j++) cin >> a[i][j], b[++b[0]] = a[i][j];
    sort(b + 1, b + b[0] + 1);
    for(int i = 1; i <= b[0]; i++) {
        if(b[i] != b[i-1] || i == 1) {
            c[++c[0]] = b[i];
            mp[b[i]] = c[0];
        }
    }
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j < 4; j++) a[i][j] = mp[a[i][j]];
    for(int j = 1; j <= n; j++) 
        for(int i = a[j][0]; i < a[j][2]; i++) 
            f[i][a[j][3]]++, f[i][a[j][1]]--;
    long long ans = 0;

    for(int i = 1; i <= c[0]; i++) 
        for(int j = 1; j < c[0]; j++) 
            f[i][j] += f[i][j-1];
    for(int i = 1; i < c[0]; i++) 
        for(int j = 1; j < c[0]; j++) 
            ans += (f[i][j] > 0 ? (c[i+1] - c[i]) * (c[j+1] - c[j]) : 0);
    cout << ans << '\n';
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.34KB
用时
466ms
内存
123.22MB
 GGapa

所属题目
P1884 [USACO12FEB] Overplanting S
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 22:02:51
*/