/*
problem:[USACO17JAN] Hoof, Paper, Scissor G
URL:https://www.luogu.com.cn/problem/P3609
date:2023-10-03
动态规划+滚动数组
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int D[2][24][5]; // D[i][j][k] i 作为滚动数组来使用，j 代表换了多少次手势，k 代表上一次出的手势是什么

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    char ch;
    string s = "HPS"; //记录一下，方便 char 转换为 int 
    for(int i = 1; i <= n; i++) {
        cin >> ch; // 0 克制 1，1 克制 2，2 克制 0
        int ci = i % 2, i1 = ci ^ 1;//ci 代表的是数组 D 使用到的层数，而 i1 代表的是上一层
        for(int j = 0; j <= k; j++) {
            for(int q = 0; q <= 2; q++) {
                int q1 = (q + 1) % 3, q2 = (q + 2) % 3, &d = D[ci][j][q];
                //上面那一行 q q1 q2 代表的是 其他可能会出的手势
                if (q1 == (int)s.find(ch))
                    d = max({D[i1][j][q], D[i1][j + 1][q1], D[i1][j + 1][q2]}) + 1; //不要傻乎乎的嵌套 max， 用一个 {} 就足够了
                else //如果输了
                    d = D[i1][j][q];
            }
        }
    }
    int ci = n % 2; //确定现在是哪一层
    cout << max({D[ci][0][0], D[ci][0][1], D[ci][0][2]}); // max 要用 algorithm 头文件
    return 0; //完美收场
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.16KB
用时
266ms
内存
880.00KB
*/