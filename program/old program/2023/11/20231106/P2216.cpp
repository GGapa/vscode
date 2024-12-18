// P2216 [HAOI2007] 理想的正方形
// https://www.luogu.com.cn/problem/P2216
// 2023-11-06 21:54
// 2023-11-06 22:19
// 这道题目常数过大，已经找到了优化思路：不用STL
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e3 + 5;

int n, m, k;
int a[maxn][maxn], mx[maxn][maxn], mn[maxn][maxn];

void clr(priority_queue<pair<int, int>>& x, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& y) {
    priority_queue<pair<int, int>> qt;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qt1;
    x = qt; y = qt1;
    
}

void init() {
    priority_queue<pair<int, int>> qx;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qn;
    for(int i = 1; i <= n; i++) {
        clr(qx, qn);
        for(int j = 1; j <= m; j++) {
            qx.push(make_pair(a[i][j], j));
            qn.push(make_pair(a[i][j], j));
            if(j >= k) {
                while(!qx.empty() && j - qx.top().second >= k) qx.pop();
                while(!qn.empty() && j - qn.top().second >= k) qn.pop();
                mx[i][j] = qx.top().first;
                mn[i][j] = qn.top().first;
            }
        }
    }
    for(int j = 1; j <= m; j++) {
        clr(qx, qn);
        for(int i = 1; i <= n; i++) {
            qx.push(make_pair(mx[i][j], i));
            qn.push(make_pair(mn[i][j], i));
            if(j >= k) {
                while(!qx.empty() && i - qx.top().second >= k) qx.pop();
                while(!qn.empty() && i - qn.top().second >= k) qn.pop();
                mx[i][j] = qx.top().first;
                mn[i][j] = qn.top().first;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    init();
    int ans = 2e9;
    // for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cout << mx[i][j] << " \n"[j == m];
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            ans = min(ans, mx[i][j] - mn[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
2.19KB
用时
7.94s
内存
11.97MB
 GGapa

所属题目
P2216 [HAOI2007] 理想的正方形
评测状态
Unaccepted
评测分数
90
提交时间
2023-11-06 22:19:13
*/

/*
编程语言
C++14 (GCC 9) O2
代码长度
2.19KB
用时
1.05s
内存
11.97MB
 GGapa

所属题目
P2216 [HAOI2007] 理想的正方形
评测状态
Accepted
评测分数
100
提交时间
2023-11-06 22:19:23
*/