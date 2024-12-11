#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
const int mod = 2009;
#define int long long

int n, t, m;
struct Mat {
    int a[N][N];
    int x, y;
    Mat operator*(const Mat& b) const {
        Mat c;
        c.x = x; c.y = b.y;
        for(int i = 1; i <= m; i++) 
            for(int j = 1; j <= m; j++) {
                c.a[i][j] = 0;
                for(int k = 1; k <= m; k++) 
                    c.a[i][j] = (c.a[i][j] + (a[i][k] * b.a[k][j]) % mod) % mod;
            }
        return c;
    }
}ans, base;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    m = n * 9;
    ans.x = m; ans.y = m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 8; j++) 
            ans.a[i + j * n][i + (j - 1) * n] = 1;
        for(int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if(x == '0') continue;
            ans.a[i][j + n * (x - 1 - '0')] = 1;
        }
    }
    base = ans;
    t -= 1;
    while(t) {
        if(t & 1) ans = ans * base;
        base = base * base;
        t >>= 1;
    }
    cout << ans.a[1][n] << '\n';
    return 0;
}

/*
对于这一类 n 比较小的问题，且与邻接矩阵有关系，应该优先考虑矩阵乘法
矩阵乘法适合于求解规定步数内到达某一个点的方案数
但由于这种方案只适用于零一
*/