/*
P2044 [NOI2012] 随机数生成器
https://www.luogu.com.cn/problem/P2044
*/
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll m, a, c, x0, n, g;
ll ans[3][3];
ll base[3][3];

void init() {
    memset(ans, 0, sizeof(ans));
    memset(base, 0, sizeof(base));
    ans[1][1] = a;
    ans[1][2] = 1;
    ans[2][2] = 1;
    base[1][1] = x0;
    base[2][1] = c;
}

ll mul(ll A,ll b)
{
    ll res = 0;
    for(; b; b >>= 1) 
    {
        if(b & 1)res = (res + A) % m;
        A = (A << 1) % m;
    }
    return res;
}
void Mul(ll A[3][3], ll b[3][3]) {
    ll c[3][3];
    for(int i = 1; i <= 2; i++ ){
        for(int j = 1; j <= 2; j++) {
            c[i][j] = 0;
            for(int q = 1; q <= 2; q++) {
                c[i][j] += mul(A[i][q], b[q][j]) % m;
                c[i][j] %= m;
            }
        }
    }
    for(int i = 1; i <= 2; i++) {
        for(int j = 1;j <= 2; j++) {
            A[i][j] = c[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> a >> c >> x0 >> n >> g;
    init();
    ll C[3][3];
    memset(C, 0, sizeof(C));
    for(int i = 1; i <= 2; i++) {
        C[i][i] = 1;
    }
    while(n > 0) {
        if(n & 1) {
            Mul(C, ans);
        }
        Mul(ans, ans);
        n >>= 1;
    }
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            ans[i][j] = C[i][j];
        }
    }

    Mul(ans, base);
    cout << ans[1][1] % g << endl;
    return 0;
}

/*
ans^n*base
*/ 