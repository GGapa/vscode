#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    if(n & 1) {
        cout << "1 2 3 " ;
        per(i, n - 2, 4) cout << i << " ";
        cout << n - 1 << " " << n << '\n' ;
    }
    else {
        per(i, n - 2, 1) cout << i << " ";
        cout << n - 1 << " " << n << '\n' ;
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