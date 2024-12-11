/*
Vacation
https://vjudge.csgrandeur.cn/contest/584210#problem/C
*/
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int a[maxn], b[maxn], c[maxn];
int f[maxn][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i] >> b[i] >> c[i];
    for(int i = 1; i <= n; i++) {
        f[i][1] = max(f[i - 1][2], f[i - 1][3]) + a[i];
        f[i][2] = max(f[i - 1][1], f[i - 1][3]) + b[i];
        f[i][3] = max(f[i - 1][1], f[i - 1][2]) + c[i];
    }
    cout <<  max(f[n][1], max(f[n][2], f[n][3]));
    return 0;
}