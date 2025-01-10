
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

double d, x2, x ;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    
    while(n--) {
        double t; cin >> t;
        d = d + t * (3 * x2 + 3 * x + 1);
		x2 = t * (x2 + 2 * x + 1);
		x = t * (x + 1);
    }
    cout << fixed << setprecision(1) << d << '\n';
    return 0;
}