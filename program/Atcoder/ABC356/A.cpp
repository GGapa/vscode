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
    int n, l, r;  cin >> n >> l >> r;
    rep(i, 1, l - 1) cout << i << " ";
    per(i, r, l) cout << i << " ";
    rep(i, r + 1, n) cout << i << " ";
    return 0;
}