#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int x, k; cin >>  x >> k;
    if(x % k == 0) {
        cout << 2 << '\n';
        cout << x - 1 << " " << 1 << '\n';
        return ;
    }
    else {
        cout << 1 << '\n';
        cout << x << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}