/*
P1962 斐波那契数列
https://www.luogu.com.cn/problem/P1962
*/
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll n;

struct Mat {
    ll a[3][3];
};
Mat base, ans;

void init() {
    ans.a[1][1] = ans.a[1][2] = 1;
    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
}
void mul(ll a[3][3], ll b[3][3]) {
    ll c[3][3];
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            c[i][j] = 0;
            for(int q = 1; q <= 2; q++) {
                c[i][j] += (a[i][q] * b[q][j]) % mod;
                c[i][j] %= mod;
            }
        }
    }
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            a[i][j] = c[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n <= 2) {
        cout << 1 << "\n";
        return 0;
    }
    init();
    n -= 2;
    while(n > 0) {
        if(n & 1) {
            mul(ans.a, base.a);
        }
        mul(base.a, base.a);
        n >>= 1;
    }
    cout << ans.a[1][1];
    return 0;
}
/*
        i - 1   i - 2
i       1       1
i - 1   1       0
*/