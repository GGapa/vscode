// P1435 [IOI2000] 回文字串
// https://www.luogu.com.cn/problem/P1435
// 2023-11-12 15:40
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;

string s1, s2;
int dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s2;
    s1 = s2;
    int n = s1.length();
    reverse(s2.begin(), s2.end());
    s2.insert(0, " ");
    s1.insert(0, " ");
    n++;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    n--;
    cout << n - dp[n][n]<< '\n';
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
809B
用时
53ms
内存
3.47MB
 GGapa

所属题目
P1435 [IOI2000] 回文字串
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 15:53:41
*/