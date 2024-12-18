//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << 81 << '\n';
    int n = 9, c = 3;
    rep(i, 1, n) rep(j, 1, n) {
        if(i < c || j < 3) continue;
        cout << i << " " << j << " " << c << '\n';
    }
    return 0;
}