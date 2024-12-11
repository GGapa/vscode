/*
problem:[USACO17JAN] Hoof, Paper, Scissor G
URL:https://www.luogu.com.cn/problem/P3609
time:2023-10-03
记忆化搜索
*/
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int n, k;
int a[maxn], F[maxn][22][3]; //f[i][j][k] 前 i 轮，变换了 j 次，最后一次出的 k
// 还有一个小技巧，数组名用大写，为了方便需要多次操作的数组元素用小写字母代替

int dfs(int x, int b, int w) { // 第 x 轮，还可以变换 b 次，上一轮出的 w
    if(!x || b < 0) return 0; //边界条件判断
    int &f = F[x][b][w], p = -1; 
    if(f) return f; 
    for(int i = 0; i <= 2; i++) 
        p = max(p, dfs((x - 1), b - (i != w), i)); //向前搜索，计算需不需要消耗次数
    return f = p + (w == a[x]); //返回能否胜利，并且赋值
}

int main() {
    ios::sync_with_stdio(0); // IO 优化
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    string s = "PHS"; //将字符转化为 int，方便操作
    char c;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        a[i] = s.find(c); //字符串 s 中的字符很少，时间复杂度可以看作常数
    }
    for(int j = 0; j <= 2; j++) ans = max(ans, dfs(n, k, j));
    cout << ans << "\n"; //建议不要使用 endl 容易出锅
    return 0; //华丽收场
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.05KB
用时
415ms
内存
32.14MB
*/