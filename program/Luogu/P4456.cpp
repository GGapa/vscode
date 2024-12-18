#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int mod;

struct Mat {
    static const int n = 190; 
    LL A[n + 1][n + 1];
 
    LL* operator [](int i)  {return A[i];} 
    const LL* operator [](int i) const { return A[i]; } //在矩阵乘法中放入这两个函数之后，便可以直接通过 `ans[1][5]` 访问数组元素，而不是 `ans.a[1][5]`。

    Mat(int num = 0) {
        memset(A, 0, sizeof(A)); 
        rep(i, 0, n) A[i][i] = num;
    }
    const Mat operator*(const Mat &B) const {
        Mat C;
        rep(i, 0, n) rep(j, 0, n) {
            rep(k, 0, n) (C[i][j] += (A[i][k] * B[k][j]) % mod);
            C[i][j] %= mod;
        }
        return C;
    }
    
    bool check() {
        return A[0][0] == A[1][1] && A[0][1] == A[1][0] && A[0][0] == 1 && A[0][1] == 0;
    }
};

namespace pre {
    LL qpow(LL x, int y){
        LL ret(1);
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod) ;
            (x = x * x % mod);
        }
        return ret;
    }

    template <typename T>
    constexpr T inv(T x) {
        return qpow(x, mod - 2); 
    }
}   
using namespace pre;

namespace binom {
    constexpr int N = 182;
    LL fac[N], iv[N];
 
    void init() {
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % mod;
        iv[N - 1] = inv(fac[N - 1]); 
        per(i, N - 2, 0) iv[i] = iv[i + 1] * (i + 1) % mod;
    }
 
    LL C(int y, int x) {
        if(x < 0 || y < 0 || y - x < 0) return 0;
        return fac[y] * iv[x] % mod * iv[y - x] % mod;
    }   
}
using binom::C; 

int n, a, b;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> mod;
    binom::init();
    Mat base;
    rep(i, 0, a + b) {
        base[i][i] = base[i][i + a + b + 1] = 1;
        rep(j, 0, i) {
            base[i + a + b + 1][j] = C(i, j);
        }
    }
    Mat ret(1);
    int y = n;
    for(Mat x = base; y; y >>= 1) {
        if(y & 1) (ret = ret * x) ;
        (x = x * x);
    }
    base = ret;

    LL mul = 1, ans = 0;
    rep(i, 0, a) {
        (ans += (((a - i) & 1) ? -1 : 1) * C(a, i) * mul % mod * (base[a + b - i][0] + base[a + b + 1 + a + b - i][0]) % mod) %= mod;
	    mul = mul * n % mod;
    }
    cout << (ans + mod) % mod<< '\n';
    return 0;
}
