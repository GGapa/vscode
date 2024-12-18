#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    if(n > m) swap(n, m);
    if(n % 2 == 0) {
        if(n / 2 != m) {
            cout << "YES\n";
            return ;
        }
    }
    if(m % 2 == 0) {
        if(m / 2 != n) {
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}  