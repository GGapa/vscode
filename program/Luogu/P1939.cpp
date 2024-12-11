/*
P1939 【模板】矩阵加速（数列）
https://www.luogu.com.cn/problem/P1939
*/

#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 10;
const int mod = 1e9 + 7;
#define int long long

int T;
int n;

struct Mat {
    int a[maxn][maxn];
};

Mat base, ans;

void init() {
    memset(ans.a, 0, sizeof(ans.a));
    memset(base.a, 0, sizeof(base.a));
    for(int i = 1; i <= 3; i++) {
        ans.a[i][i] = 1;
    }
    base.a[1][1] = base.a[1][3] = base.a[2][1] = base.a[3][2] = 1;
}

void Pow(int a[maxn][maxn], int b[maxn][maxn]) {
    int c[maxn][maxn];
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            c[i][j] = 0;
            for(int q = 1; q <= 3; q++) {
                c[i][j] += (a[i][q] % mod * b[q][j] % mod) % mod;
                c[i][j] %= mod;
            }
        }
    }
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            a[i][j] = c[i][j];
        }
    }
}

void slove(int p) {
    while(p > 0) {
        if(p & 1) {
            Pow(ans.a, base.a);
        }
        Pow(base.a, base.a);
        p >>= 1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        if(n <= 3) {
            cout << "1\n";
            continue;
        }
        init();
        slove(n);
        cout << ans.a[2][1] << '\n';
    }
    return 0;
}


 