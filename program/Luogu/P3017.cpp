// P3017 [USACO11MAR] Brownie Slicing G
// https://www.luogu.com.cn/problem/P3017
// 2023-11-12 22:29
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 500 + 5;

int n, m, a, b;
int aa[maxn][maxn];
int l, r;

bool check(int x ) {
    int it, num; it = num = 0;
    for(int i = 1; i <= n; i++)  {
        int dis, sum; dis = sum = 0;
        for(int j = 1; j <= m; j++) {
            if(dis + aa[i][j] - aa[i][j-1] - aa[it][j] + aa[it][j-1] < x) 
                dis += aa[i][j] - aa[i][j-1] - aa[it][j] + aa[it][j-1];
            else 
                sum++, dis = 0;
        }
        if(sum >= b) {
            it = i; num++;
        }
    }
    return num >= a; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            cin >> aa[i][j];
            aa[i][j] += aa[i][j-1] + aa[i-1][j] - aa[i-1][j-1];
        }
    l = 0; r = aa[n][m] + 1;
    int ans = 2e9;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else 
            r = mid;
    }
    cout << ans << '\n';
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.34KB
用时
199ms
内存
1.50MB
 GGapa

所属题目
P3017 [USACO11MAR] Brownie Slicing G
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 22:40:06
*/