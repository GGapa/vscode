/**
 * @Problem      : 虫群之心
 * @URL          : http://47.94.97.204/contest/350/problem/1
 * @Author       : GGapa
 * @Date         : 2023-11-14 14:31:14
 * @LastEditTime : 2023-11-14 15:04:45
**/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll T, m, p;

ll read() {
    char c;
    ll x = 0, f = 1;
    c = getchar();
    while(!isdigit(c)) {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

void tmp() {
    ll sum = 1;
    for(ll i = 1; i <= m; i++) {
        sum = sum * i % p;        
    }
    cout << sum << '\n';
}

ll qpow(ll x, ll y ){
    int base = x, ans = 1;
    while(y > 0) {
        if(y & 1) ans =(base * ans) % p;
        base = base * base;
        y >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("factorial.in", "r", stdin);
    freopen("factorial.out", "w", stdout);
    T = read();
    while(T--) {
        m = read(); p = read();
        if(p <= m) {
            cout << "0\n" ;
            continue;
        }
        tmp();
    }
    return 0;
}
// 若 m > p 输出  0
// 暴力 60pts
// 分块？组合数学？
// n! = n! / ((n/2)! * (n/2)!)