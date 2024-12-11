/**
 * @Problem      : P2260 [清华集训2012] 模积和
 * @URL          : https://www.luogu.com.cn/problem/P2260
 * @Author       : GGapa
 * @Date         : 2023-11-29 23:20:39
 * @LastEditTime : 2023-11-30 00:21:57
**/
#include <iostream>
using namespace std;
#define int __int128 

const int mod = 19940417;
const int inv6 = 3323403;
const int inv2 = 9970209;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}


int sum1(int x){
	return x * (x + 1) % mod * inv2 % mod;
}
int sum2(int x){
	return x * (x + 1) % mod * (2 * x + 1) % mod * inv6 % mod;
}

int n, m;
int ans1, ans2, ans, ans3;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = read(); m = read();
    if(n > m) swap(n, m);
    ans1 = n * n % mod, ans2 = m * m % mod;
    for(int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans1 = (ans1 - (sum1(r) - sum1(l - 1) + mod) % mod * (n / l) % mod + mod)  % mod;
    }
    for(int l = 1, r; l <= m; l = r + 1) {
        r = m / (m / l);
        ans2 = (ans2 - (sum1(r) - sum1(l - 1) + mod) % mod * (m / l) % mod + mod)  % mod;
    }
    ans = (ans1 * ans2) % mod;
    for(int l = 1, r; l <= n; l = r + 1) {
        r = min(n / (n / l), m / (m / l));		
        ans3 = (ans3 + ((r - l + 1) * n % mod * m % mod)) % mod;
        ans3 = (ans3 - ((sum1(r) - sum1(l - 1) + mod) % mod * ((n / l) * m % mod + (m / l) * n % mod) % mod) + mod) % mod;
        ans3 = (ans3 + ((sum2(r) - sum2(l - 1) + mod) % mod * (n / l) % mod * (m / l) % mod)) % mod;
    }
    ans = (ans - ans3 + mod) % mod;
    write(ans);
    return 0;
}
