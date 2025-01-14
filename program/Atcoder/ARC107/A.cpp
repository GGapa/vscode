#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

LL calc(LL x) {return (x + 1) * x / 2 % mod; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL a, b, c; cin >> a >> b >> c;
    cout << calc(a) * calc(b) % mod * calc(c) % mod << '\n';
    return 0;
}