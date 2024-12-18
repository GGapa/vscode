#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 3000 + 5;

int n, m, val[maxn], dp[maxn][maxn];
struct Node {
    int to, val;
};
vector<Node> G[maxn];

int dfs(int x) {
    if(x > n - m) {
        dp[x][1] = val[x];
        return 1;
    }
    int sum = 0, t;
    for(auto to : G[x]) {
        to.to;
        t = dfs(to.to);
        sum += t;
        for(int i = sum; i > 0; i--) {
            for(int j = 1; j <= t; j++) {
                if(i - j >= 0) dp[x][i] = max(dp[x][i], dp[x][i-j] + dp[to.to][j] - to.val);
            }
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1, k, a, c; i <= n - m; i++) {
        cin >> k;
        while(k--) {
            cin >> a >> c;
            G[i].push_back(Node{a, c});

        }
    }
    for(int i = n - m + 1; i <= n; i++) cin >> val[i];
    memset(dp, -0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++) dp[i][0] = 0;
    dfs(1);
    for(int i = m; i >= 1; i--) {
        if(dp[1][i] >= 0) {
            cout << i;
            return 0;
        }
    }
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.19KB
用时
215ms
内存
35.14MB
 GGapa

所属题目
P1273 有线电视网
评测状态
Accepted
评测分数
100
提交时间
2023-10-20 11:29:22
*/