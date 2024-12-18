/*
P3390 【模板】矩阵快速幂
https://www.luogu.com.cn/problem/P3390
*/

#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 100 + 5;

struct Mat {
    ll a[maxn][maxn];
};
Mat A, ans;

ll k;
int n;

void mpow(ll a[maxn][maxn], ll b[maxn][maxn]) {
    ll c[maxn][maxn];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            c[i][j] = 0;
            for(int q = 1; q <= n; q++) {
                c[i][j] += a[i][q] * b[q][j] % mod;
                c[i][j] %= mod;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = c[i][j];
        }
    }
}


int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> A.a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        ans.a[i][i] = 1;
    }
    while(k > 0) {
        if(k & 1) {
            mpow(ans.a, A.a);
        }
        mpow(A.a, A.a);
        k >>= 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans.a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}