#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int m, p = 71, q;
int a[30], b[30];
bool b1 = true;

ll qpow(ll x, ll y) {
    ll ans = 1, base = x;
    while(y != 0) {
        if(y % 2) ans = (ans * base) % p;
        base = (base * base) % p;
        y >>= 1;
    }
    return ans;
}

ll qmul(ll x, ll y) {
    ll ans = 0;
    while(y != 0) {
        if(y % 2) ans = (ans + x) % p;
        x = (x + x) % p;
        y >>= 1;
    }
    return ans;
}

ll calc(ll x) {
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += a[i] * qpow(x, b[i]) % p;
    }
    return ans;
}

ll f(ll n, ll x) {
    if(n == 1) return calc(x) % p;
    return calc(f(n - 1, x)) % p;
}

namespace B1 {
    ll A, B = 0;
    int main(ll x, ll y) {
        for(int i = 1; i <= m; i++)  {
            if(b[i] == 1)A += a[i];
            else B += a[i];
        }
        
        x = qmul(x, qpow(A, y) % p) % p;
        for(int i = 1; i < y; i++) x = (x + qmul(qpow(A, i), B));
        x = (x + B) % p;
        cout << x << '\n';
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> m >> q >> p;
    for(int i = 1; i <= m; i++) {cin >> a[i] >> b[i]; if(b[i] > 1) b1 = false;}
    while(q--) {
        ll x, y;
        cin >> x >> y;
        if(b1) B1::main(x, y);
        else if(y <= 10)cout << f(y, x) << '\n';

    }
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.59KB
用时
3.88s
内存
808.00KB
 GGapa

所属题目
T390882 少项式复合幂
所属比赛
GenshinOI Round 3
评测状态
Unaccepted
评测分数
15
提交时间
2023-10-29 16:26:00
*/