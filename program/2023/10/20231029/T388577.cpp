#include <iostream>
#include <cmath>
#include <cstdio>
#include <bitset>
using namespace std;
typedef long long ll;

ll T, n, k;

ll qpow(ll x, ll y) {
    ll ans = 1, base = x;
    while(y != 0) {
        if(y % 2) ans = (ans * base);
        base = (base * base);
        y >>= 1;
    }
    return ans;
}

ll qmul(ll x, ll y) {
    ll ans = 0;
    while(y != 0) {
        if(y % 2) ans = (ans + x);
        x = (x + x);
        y >>= 1;
    }
    return ans;
}

bool check(ll x) {
    if(x == 2 || x == 1) return true;
    int si = sqrt(x) + 1;
    for(int i = 2; i <= si; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

ll sol(ll x) {
    if(x <= 0) return 0;
    ll tmp = x;
    while(!check(x)) x--;
    return max(sol(tmp - x) + qpow(x-k, 2), qmul(qpow(1 - k, 2), tmp));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> k;
        cout << sol(n) << "\n";
    }
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.10KB
用时
700ms
内存
740.00KB
 GGapa

所属题目
T388577 lmxcslD
所属比赛
GenshinOI Round 3
评测状态
Accepted
评测分数
100
提交时间
2023-10-29 16:50:45
*/