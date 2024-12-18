/*
P2455 [SDOI2006] 线性方程组
https://www.luogu.com.cn/problem/P2455
*/

#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 50 + 5;

int n;
double map[maxn][maxn];
double ans[maxn];
const double eps = 1e-7;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> map[i][j];
        }
    }
    int succ = 0;
    for (int i = 0; i < n; i++) {
        int it = succ;
        for (int j = succ; j < n; j++) {
            if (fabs(map[j][i]) > fabs(map[it][i]))
                it = j;
        }
        if (fabs(map[it][i]) < eps)
            continue;
        for (int j = i; j <= n; j++)
            swap(map[it][j], map[succ][j]);
        for (int j = n; j >= i; j--)
            map[succ][j] /= map[succ][i];
        for (int j = succ + 1; j < n; j++) {
            if (fabs(map[j][i]) > eps) {
                for (int k = n; k >= i; k--)
                    map[j][k] -= map[succ][k] * map[j][i];
            }
        }
        succ++;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            map[i][n] -= map[i][j] * map[j][n];
        }
    }
    if (succ < n) {
        for (int i = succ; i < n; i++) {
            if (fabs(map[i][n]) > eps) {
                cout << "-1" << endl;
                return 0;
            }
        }
        cout << "0" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("x%d=%.2lf\n", i + 1, map[i][n]);
    }
    return 0;
}
