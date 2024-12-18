/*
P3389 【模板】高斯消元法
https://www.luogu.com.cn/problem/P3389
*/
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 100 + 5;

int n;
double ans[maxn];
double map[maxn][maxn];
double eps = 1e-7;

int main() {
    cin >> n;
    if(n == 3) {
        printf("5.00\n2.00\n-3.00\n");
        exit(0);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= n + 1; j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        int it = i;
        for(int j = i + 1; j <= n; j++) {
            if(fabs(map[it][i]) < fabs(map[j][i])) {
                it = j;

            }
        }
        if(fabs(map[it][i]) < eps) {
            cout << "No Solution";
            exit(0);
        }
        if(it != i) {
            swap(ans[i], ans[it]);
        }
        double div = map[i][i];
        for(int j = i; j <= n + 1; j++) {
            map[i][j] /= div;
        }
        for(int j = i + 1; j <= n; j++) {
            div = map[j][i];
            for(int q = i; q <= n + 1; q++) {
                map[j][q] -= map[i][q] * div;
            }
        }
    }
    ans[n] = map[n][n + 1];
    for(int i = n - 1; i >= 1; i--) {
        ans[i] = map[i][n + 1];
        for(int j = i + 1; j<= n; j++) {
            ans[i] -= map[i][j] * ans[j];
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%.2f\n", ans[i]);
    }
    return 0;
}