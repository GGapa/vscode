#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.in", "w", stdout);
    int n = 10;
    cout << n << '\n';
    mt19937 rnd(time(0));
    rep(i, 1, n) cout <<  rnd() % n + 1 << " \n"[i == n];
    return 0;
}