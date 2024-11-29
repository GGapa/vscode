#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(b == 0) return x = 1, y = 0, a;
    LL tp = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return tp;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL n, m; cin >> n >> m;
    LL x, y;
    exgcd(n, m, x, y);cout << (x % m + m) % m << '\n';
    return 0;
}