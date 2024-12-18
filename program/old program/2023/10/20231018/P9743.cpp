#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 91;
#define int long long 
const int mod = 998244353;

int n, m, k;
int a[50][50], b[50][50], ans[50][50];
int f[2][50][maxn][maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("AKIOI.in", "r", stdin);
    //freopen("AKIOI.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> b[i][j];
    f[1][1][0][0][0] = 1; // f[x][y][c][la][lb] 走到x y， 花了c，还剩la长a，lb长b
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i != 1) f[i & 1][j][0][0][0] = 0;
            for(int c = 1; c <= k; c++) {
                for(int la = 0; la + i <= n; la++) {
                    for(int lb = 0; lb + j <= m; lb++) {
                        int tmp = mod;
                        if(la != 0 && c >= a[i][j]) tmp += f[i & 1][j][c - a[i][j]][la - 1][lb];                                    //花了一张a的票
                        if(lb != 0 && c >= b[i][j]) tmp += f[i & 1][j][c - b[i][j]][la][lb - 1];                                    //花了一张b的票
                        if(la != 0 && lb != 0 && c >= a[i][j] + b[i][j]) tmp -= f[i & 1][j][c - a[i][j] - b[i][j]][la - 1][lb - 1]; //这里是为了防止又有a票又有b票重复计算
                        if(i != 1) tmp += f[(i - 1) & 1][j][c][la + 1][lb];     //由上一个情况转移而来
                        if(j != 1) tmp += f[i & 1][j - 1][c][la][lb + 1];       //同上
                        f[i & 1][j][c][la][lb] = tmp % mod;
                        if(c == k && la == 0 && la == lb) ans[i][j] = tmp % mod;//满足条件
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ans[i][j] << " \n"[j == m];
        }
    }
    return 0;
}


/*
编程语言
C++14 (GCC 9)
代码长度
1.92KB
用时
3.07s
内存
501.36MB
 GGapa

所属题目
P9743 「KDOI-06-J」旅行
评测状态
Accepted
评测分数
100
提交时间
2023-10-18 23:59:24
*/